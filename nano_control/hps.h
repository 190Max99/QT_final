#ifndef HPS_H
#define HPS_H

#include <stdint.h>


class HPS
{
public:
    HPS();
    ~HPS();

    bool LedSet(bool bOn);
    bool IsButtonPressed();
    bool GsensorQuery(int16_t accel[3], int16_t gyro[3]);
    bool GetEulerAngles(float *Roll, float *Pitch, float *Yaw);
    int32_t ReadEncoder1();
    int32_t ReadEncoder2();

protected:
    // pio
    int m_file_mem;
    void *m_virtual_base;


    bool PioInit();

    // gsensor
    int m_file_gsensor;
    int GsensorInit();

    int EncoderInit();
};

#endif // HPS_H
