#ifndef MPU6050_H
#define MPU6050_H

#include <stdint.h>
#include <stdbool.h>

// MPU6050 设备地址（默认地址）
#define MPU6050_ADDR 0x68

// 采样率（MPU6050 使用具体数值）
#define MPU6050_RATE_1000HZ  0x07
#define MPU6050_RATE_500HZ   0x08
#define MPU6050_RATE_250HZ   0x09
#define MPU6050_RATE_125HZ   0x0A
#define MPU6050_RATE_50HZ    0x0D

// 加速度计量程设置
#define MPU6050_ACCEL_RANGE_2G   0x00  // ±2g
#define MPU6050_ACCEL_RANGE_4G   0x08  // ±4g
#define MPU6050_ACCEL_RANGE_8G   0x10  // ±8g
#define MPU6050_ACCEL_RANGE_16G  0x18  // ±16g

// 陀螺仪量程设置
#define MPU6050_GYRO_RANGE_250   0x00  // ±250°/s
#define MPU6050_GYRO_RANGE_500   0x08  // ±500°/s
#define MPU6050_GYRO_RANGE_1000  0x10  // ±1000°/s
#define MPU6050_GYRO_RANGE_2000  0x18  // ±2000°/s

// 寄存器地址
#define MPU6050_REG_PWR_MGMT_1    0x6B  // 电源管理
#define MPU6050_REG_WHO_AM_I      0x75  // 设备 ID
#define MPU6050_REG_ACCEL_CONFIG  0x1C  // 加速度计配置
#define MPU6050_REG_GYRO_CONFIG   0x1B  // 陀螺仪配置
#define MPU6050_REG_ACCEL_XOUT_H  0x3B  // 加速度计数据起始地址
#define MPU6050_REG_GYRO_XOUT_H   0x43  // 陀螺仪数据起始地址

// 功能函数声明
bool MPU6050_Init(int file);
bool MPU6050_IdRead(int file, uint8_t *id);
bool MPU6050_Read_Accel(int file, int16_t accel[3]);
bool MPU6050_Read_Gyro(int file, int16_t gyro[3]);

#endif // MPU6050_H
