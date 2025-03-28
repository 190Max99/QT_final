#include <QDebug>
#include "hps.h"
#include "mpu6050.h"
#include <stdint.h>

#include <unistd.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>

#ifdef __arm__
#include "socal/socal.h"
#include "socal/hps.h"
#include "socal/alt_gpio.h"
#else
#define ALT_GPIO1_SWPORTA_DR_ADDR
#define ALT_LWFPGASLVS_OFST
#define ALT_STM_OFST 0
#define alt_clrbits_word(x, y)
#define alt_setbits_word(x, y)
#define alt_read_word(x) 0
#endif

#define HW_REGS_BASE ( ALT_STM_OFST )
#define HW_REGS_SPAN ( 0x04000000 )
#define HW_REGS_MASK ( HW_REGS_SPAN - 1 )

#define USER_IO_DIR     (0x01000000)
#define BIT_LED         (0x01000000)
#define BUTTON_MASK     (0x02000000)

#define ENCODER1_PIO_BASE  0x00040000
#define ENCODER2_PIO_BASE  0x00040010
// #define HW_REGS_BASE       0xFF200000     // HPS 到 FPGA 的轻量级桥地址
// #define HW_REGS_SPAN       0x00200000
// #define HW_REGS_MASK       (HW_REGS_SPAN - 1)

volatile uint32_t *encoder1_ptr;
volatile uint32_t *encoder2_ptr;




HPS::HPS()
{
    m_file_gsensor = GsensorInit();
    PioInit();
    EncoderInit();
}

HPS::~HPS()
{
    // 释放 PIO 资源
    munmap(m_virtual_base, HW_REGS_SPAN);
    close(m_file_mem);
}

bool HPS::LedSet(bool bOn){
    if (m_file_mem == -1){
        qDebug() << "Led Set Failed.\r\n";
        return false;
    }

    if (!bOn){
        alt_clrbits_word((void *)((char *)m_virtual_base + ((uint32_t)(ALT_GPIO1_SWPORTA_DR_ADDR) & (uint32_t)(HW_REGS_MASK))), BIT_LED);
    } else {
        alt_setbits_word((void *)((char *)m_virtual_base + ((uint32_t)(ALT_GPIO1_SWPORTA_DR_ADDR) & (uint32_t)(HW_REGS_MASK))), BIT_LED);
    }

    return true;
}

bool HPS::IsButtonPressed(){
    uint32_t scan_input = ~alt_read_word((void *)((char *)m_virtual_base + ((uint32_t)(ALT_GPIO1_EXT_PORTA_ADDR) & (uint32_t)(HW_REGS_MASK))));
    return (scan_input & BUTTON_MASK) ? true : false;
}

bool HPS::PioInit(){
    m_file_mem = open("/dev/mem", (O_RDWR | O_SYNC));
    if (m_file_mem != -1){
        m_virtual_base = mmap(NULL, HW_REGS_SPAN, (PROT_READ | PROT_WRITE), MAP_SHARED, m_file_mem, HW_REGS_BASE);

        // 配置 LED 作为输出
        alt_setbits_word((void *)((char *)m_virtual_base + ((uint32_t)(ALT_GPIO1_SWPORTA_DDR_ADDR) & (uint32_t)(HW_REGS_MASK))), USER_IO_DIR);
    } else {
        qDebug() << "PioInit failed.\r\n";
        return false;
    }

    return true;
}

int HPS::GsensorInit(){
    int file = open("/dev/i2c-1", O_RDWR);
    if (file >= 0){
        if (ioctl(file, I2C_SLAVE, MPU6050_ADDR) < 0){
            file = -1;
        } else {
            MPU6050_Init(file);
        }
    }
    return file;
}

bool HPS::GsensorQuery(int16_t accel[3], int16_t gyro[3]) {
    bool bSuccess = false;

    if (m_file_gsensor >= 0) {
        uint8_t id;
        if (MPU6050_IdRead(m_file_gsensor, &id) && (id == 0x68 || id == 0x70)) { // 确保 MPU6050 连接正常
            // **读取加速度计 & 陀螺仪数据**
            bool accelSuccess = MPU6050_Read_Accel(m_file_gsensor, accel);
            bool gyroSuccess = MPU6050_Read_Gyro(m_file_gsensor, gyro);

            if (accelSuccess && gyroSuccess) {
                // **更新四元数**
                MPU6050_UpdateQuaternion(accel, gyro);
                bSuccess = true;
            }
        }
    }
    return bSuccess;
}

// **新接口：直接获取欧拉角**
bool HPS::GetEulerAngles(float *Roll, float *Pitch, float *Yaw) {
    if (m_file_gsensor < 0) return false;
    MPU6050_GetEulerAngles(Roll, Pitch, Yaw);
    return true;
}

int HPS::EncoderInit() {
    int fd = open("/dev/mem", O_RDWR | O_SYNC);

    void* virtual_base = mmap(NULL, HW_REGS_SPAN, PROT_READ | PROT_WRITE, MAP_SHARED, fd, HW_REGS_BASE);
    encoder1_ptr = (uint32_t*)((char*)virtual_base + (ENCODER1_PIO_BASE & HW_REGS_MASK));
    encoder2_ptr = (uint32_t*)((char*)virtual_base + (ENCODER2_PIO_BASE & HW_REGS_MASK));

}

int32_t HPS::ReadEncoder1() {
    return *encoder1_ptr;
}

int32_t HPS::ReadEncoder2() {
    return *encoder2_ptr;
}
