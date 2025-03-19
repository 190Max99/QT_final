#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

// MPU6050 设备地址
#define MPU6050_ADDR 0x68

// MPU6050 相关寄存器地址
#define PWR_MGMT_1    0x6B  // 电源管理寄存器
#define WHO_AM_I      0x75  // 设备 ID
#define ACCEL_XOUT_H  0x3B  // 加速度计数据起始地址
#define GYRO_XOUT_H   0x43  // 陀螺仪数据起始地址

// 四元数存储
static float Q0 = 1.0f, Q1 = 0.0f, Q2 = 0.0f, Q3 = 0.0f;
static float Roll = 0.0f, Pitch = 0.0f, Yaw = 0.0f;

// 计算参数
#define DELTA_T 0.002f  // 计算间隔 2ms
#define Kp 0.17f        // 加速度收敛速率
#define Ki 0.004f       // 陀螺仪积分增益

// 误差积分项
static float I_ex = 0, I_ey = 0, I_ez = 0;

// 计算平方根 (快速开平方)
float fast_sqrt(float num) {
    float halfx = 0.5f * num;
    float y = num;
    long i = *(long*)&y;
    i = 0x5f375a86 - (i >> 1);
    y = *(float*)&i;
    y = y * (1.5f - (halfx * y * y));
    y = y * (1.5f - (halfx * y * y));
    return y;
}

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
    // 解除休眠模式
    if (!MPU6050_REG_WRITE(file, PWR_MGMT_1, 0x00)) return false;

    // 设置加速度计量程 ±2g
    if (!MPU6050_REG_WRITE(file, 0x1C, 0x00)) return false;

    // 设置陀螺仪量程 ±2000°/s
    if (!MPU6050_REG_WRITE(file, 0x1B, 0x18)) return false;

    return true;
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

// 四元数姿态解算
void MPU6050_UpdateQuaternion(int16_t accel[3], int16_t gyro[3]) {
    float ax = accel[0], ay = accel[1], az = accel[2];
    float gx = gyro[0] * M_PI / 180.0f;
    float gy = gyro[1] * M_PI / 180.0f;
    float gz = gyro[2] * M_PI / 180.0f;

    float norm = fast_sqrt(ax * ax + ay * ay + az * az);
    ax *= norm;
    ay *= norm;
    az *= norm;

    float vx = 2 * (Q1 * Q3 - Q0 * Q2);
    float vy = 2 * (Q0 * Q1 + Q2 * Q3);
    float vz = Q0 * Q0 - Q1 * Q1 - Q2 * Q2 + Q3 * Q3;

    float ex = ay * vz - az * vy;
    float ey = az * vx - ax * vz;
    float ez = ax * vy - ay * vx;

    I_ex += DELTA_T * ex;
    I_ey += DELTA_T * ey;
    I_ez += DELTA_T * ez;

    gx += Kp * ex + Ki * I_ex;
    gy += Kp * ey + Ki * I_ey;
    gz += Kp * ez + Ki * I_ez;

    Q0 += (-Q1 * gx - Q2 * gy - Q3 * gz) * DELTA_T;
    Q1 += (Q0 * gx + Q2 * gz - Q3 * gy) * DELTA_T;
    Q2 += (Q0 * gy - Q1 * gz + Q3 * gx) * DELTA_T;
    Q3 += (Q0 * gz + Q1 * gy - Q2 * gx) * DELTA_T;

    norm = fast_sqrt(Q0 * Q0 + Q1 * Q1 + Q2 * Q2 + Q3 * Q3);
    Q0 *= norm;
    Q1 *= norm;
    Q2 *= norm;
    Q3 *= norm;

    Roll = -asin(-2 * Q1 * Q3 + 2 * Q0 * Q2) * 180.0f / M_PI;
    Pitch = -atan2(2 * Q2 * Q3 + 2 * Q0 * Q1, -2 * Q1 * Q1 - 2 * Q2 * Q2 + 1) * 180.0f / M_PI;
    Yaw = -atan2(2 * Q1 * Q2 + 2 * Q0 * Q3, -2 * Q2 * Q2 - 2 * Q3 * Q3 + 1) * 180.0f / M_PI;
}

// 获取欧拉角
void MPU6050_GetEulerAngles(float *roll, float *pitch, float *yaw) {
    *roll = Roll;
    *pitch = Pitch;
    *yaw = Yaw;
}
