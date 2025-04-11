#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

// MPU6050 设备地址
#define MPU6050_ADDR 0x68

// MPU6050 相关寄存器地址
#define PWR_MGMT_1    0x6B  // 电源管理寄存器
#define WHO_AM_I      0x75  // 设备 ID
#define ACCEL_XOUT_H  0x3B  // 加速度计数据起始地址
#define GYRO_XOUT_H   0x43  // 陀螺仪数据起始地址

// API 函数声明
bool MPU6050_REG_WRITE(int file, uint8_t reg, uint8_t value);
bool MPU6050_REG_READ(int file, uint8_t reg, uint8_t *value);
bool MPU6050_REG_MULTI_READ(int file, uint8_t reg, uint8_t *data, uint8_t length);
bool MPU6050_Init(int file);
bool MPU6050_IdRead(int file, uint8_t *id);
bool MPU6050_Read_Accel(int file, int16_t accel[3]);
bool MPU6050_Read_Gyro(int file, int16_t gyro[3]);

// 单字节写入寄存器
bool MPU6050_REG_WRITE(int file, uint8_t reg, uint8_t value) {
    uint8_t data[2] = {reg, value};
    return write(file, data, sizeof(data)) == sizeof(data);
}

// 单字节读取寄存器
bool MPU6050_REG_READ(int file, uint8_t reg, uint8_t *value) {
    if (write(file, &reg, 1) != 1) return false;
    return read(file, value, 1) == 1;
}

// 多字节读取
bool MPU6050_REG_MULTI_READ(int file, uint8_t reg, uint8_t *data, uint8_t length) {
    if (write(file, &reg, 1) != 1) return false;
    return read(file, data, length) == length;
}

// 初始化 MPU6050
bool MPU6050_Init(int file) {
    return MPU6050_REG_WRITE(file, PWR_MGMT_1, 0x00);  // 解除休眠模式
}

// 读取 MPU6050 设备 ID
bool MPU6050_IdRead(int file, uint8_t *id) {
    return MPU6050_REG_READ(file, WHO_AM_I, id);
}

// 读取加速度计数据
bool MPU6050_Read_Accel(int file, int16_t accel[3]) {
    uint8_t rawData[6];
    bool success = MPU6050_REG_MULTI_READ(file, ACCEL_XOUT_H, rawData, 6);

    if (success) {
        accel[0] = (rawData[0] << 8) | rawData[1]; // X 轴
        accel[1] = (rawData[2] << 8) | rawData[3]; // Y 轴
        accel[2] = (rawData[4] << 8) | rawData[5]; // Z 轴
    }
    return success;
}

// 读取陀螺仪数据
bool MPU6050_Read_Gyro(int file, int16_t gyro[3]) {
    uint8_t rawData[6];
    bool success = MPU6050_REG_MULTI_READ(file, GYRO_XOUT_H, rawData, 6);

    if (success) {
        gyro[0] = (rawData[0] << 8) | rawData[1]; // X 轴
        gyro[1] = (rawData[2] << 8) | rawData[3]; // Y 轴
        gyro[2] = (rawData[4] << 8) | rawData[5]; // Z 轴
    }
    return success;
}
