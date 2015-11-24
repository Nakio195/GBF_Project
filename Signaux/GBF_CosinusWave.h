#ifndef GBF_COSINUSWAVE_H
#define GBF_COSINUSWAVE_H

#include "GBF_Signal.h"
#include <math.h>

class GBF_CosinusWave: public GBF_Signal

{
    public:
        GBF_CosinusWave(double Frequency = 1000.0, double Amplitude = 0.5, double Offset = 0, int Resolution = 8, int SamplingFrequency = 44100);
        virtual void ComputeWaveform (int Resolution, int SamplingFrequency);

        virtual void setDutyCycle(double DutyCycle);
        virtual double DutyCycle() const;
};

#endif // GBF_COSINUSWAVE_H
