#ifndef ADXL345_H
#define ADXL345_H

#include <stdint.h>
#include <stdbool.h>


/* Bit values in BW_RATE                                                */
/* Expresed as output data rate */
#define XL345_RATE_3200       0x0f  // MPU6050 doesn't have this rate, but keeping it for consistency
#define XL345_RATE_1600       0x0e
#define XL345_RATE_800        0x0d
#define XL345_RATE_400        0x0c
#define XL345_RATE_200        0x0b
#define XL345_RATE_100        0x0a
#define XL345_RATE_50         0x09
#define XL345_RATE_25         0x08
#define XL345_RATE_12_5       0x07
#define XL345_RATE_6_25       0x06
#define XL345_RATE_3_125      0x05
#define XL345_RATE_1_563      0x04
#define XL345_RATE__782       0x03
#define XL345_RATE__39        0x02
#define XL345_RATE__195       0x01
#define XL345_RATE__098       0x00

/* Bit values in DATA_FORMAT                                            */

/* Register values read in DATAX0 through DATAZ1 are dependant on the
   value specified in data format.  Customer code will need to interpret
   the data as desired.                                                 */
#define XL345_RANGE_2G             0x00  // For MPU6050: equivalent is 0x00 for 2G range
#define XL345_RANGE_4G             0x01  // For MPU6050: equivalent is 0x08 for 4G range
#define XL345_RANGE_8G             0x02  // For MPU6050: equivalent is 0x10 for 8G range
#define XL345_RANGE_16G            0x03  // For MPU6050: equivalent is 0x18 for 16G range
#define XL345_DATA_JUST_RIGHT      0x00
#define XL345_DATA_JUST_LEFT       0x04
#define XL345_10BIT                0x00
#define XL345_FULL_RESOLUTION      0x08
#define XL345_INT_LOW              0x20
#define XL345_INT_HIGH             0x00
#define XL345_SPI3WIRE             0x40
#define XL345_SPI4WIRE             0x00
#define XL345_SELFTEST             0x80

/* Bit values in INT_ENABLE, INT_MAP, and INT_SOURCE are identical
   use these bit values to read or write any of these registers.        */
#define XL345_OVERRUN              0x01
#define XL345_WATERMARK            0x02
#define XL345_FREEFALL             0x04
#define XL345_INACTIVITY           0x08
#define XL345_ACTIVITY             0x10
#define XL345_DOUBLETAP            0x20
#define XL345_SINGLETAP            0x40
#define XL345_DATAREADY            0x80

/* Bit values in POWER_CTL                                              */
#define XL345_WAKEUP_8HZ           0x00
#define XL345_WAKEUP_4HZ           0x01
#define XL345_WAKEUP_2HZ           0x02
#define XL345_WAKEUP_1HZ           0x03
#define XL345_SLEEP                0x04
#define XL345_MEASURE              0x08
#define XL345_STANDBY              0x00
#define XL345_AUTO_SLEEP           0x10
#define XL345_ACT_INACT_SERIAL     0x20
#define XL345_ACT_INACT_CONCURRENT 0x00

// Register List
#define ADXL345_REG_DEVID       0x00
#define ADXL345_REG_POWER_CTL   0x2D
#define ADXL345_REG_DATA_FORMAT 0x31
#define ADXL345_REG_FIFO_CTL    0x38
#define ADXL345_REG_BW_RATE     0x2C
#define ADXL345_REG_INT_ENALBE  0x2E  // default value: 0x00
#define ADXL345_REG_INT_MAP     0x2F  // default value: 0x00
#define ADXL345_REG_INT_SOURCE  0x30  // default value: 0x02
#define ADXL345_REG_DATA_FORMAT 0x31  // default value: 0x00
#define ADXL345_REG_DATAX0      0x43  // read only
#define ADXL345_REG_DATAX1      0x44  // read only
#define ADXL345_REG_DATAY0      0x45  // read only
#define ADXL345_REG_DATAY1      0x46  // read only
#define ADXL345_REG_DATAZ0      0x47  // read only
#define ADXL345_REG_DATAZ1      0x48  // read only


bool ADXL345_Init(int file);
bool ADXL345_IsDataReady(int file);
bool ADXL345_XYZ_Read(int file, uint16_t szData16[3]);
bool ADXL345_IdRead(int file, uint8_t *pId);


#endif // ADXL345_H
