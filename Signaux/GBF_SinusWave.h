#ifndef GBF_SINUSWAVE_H
#define GBF_SINUSWAVE_H

#include "GBF_Signal.h"
#include <math.h>

class GBF_SinusWave: public GBF_Signal
{
public:
    GBF_SinusWave(double Frequency = 1000.0, double Amplitude = 0.5, double Offset = 0, double DutyCycle = 0.5, int Resolution = 8, int SamplingFrequency = 44100);
    virtual void ComputeWaveform (int Resolution, int SamplingFrequency);

    virtual void setDutyCycle(double DutyCycle);
    virtual double DutyCycle() const;
};

#endif // GBF_SINUSWAVE_H
