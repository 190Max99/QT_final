#ifndef FPGA_H
#define FPGA_H

#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>


class FPGA
{
public:
    FPGA();
    ~FPGA();

    bool LedSet(int mask);
    bool KeyRead(uint32_t *mask);
    bool SwitchRead(uint32_t *mask);
    // 添加 public 函数声明
    bool Encoder1Read(uint32_t *val);
    bool Encoder2Read(uint32_t *val);

    // 添加 private 指针成员（与 LED/SW/KEY 同类）

protected:
    bool m_bInitSuccess;
    int m_file_mem;

    uint8_t *m_led_base;
    uint8_t *m_key_base;
    uint8_t *m_sw_base;
    uint8_t *m_encoder1_base;
    uint8_t *m_encoder2_base;



    bool Init();

};

#endif // FPGA_H
