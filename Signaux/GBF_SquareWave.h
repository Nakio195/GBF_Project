#ifndef GBF_SQUAREWAVE_H
#define GBF_SQUAREWAVE_H

#include "GBF_Signal.h"
#include <math.h>

class GBF_SquareWave : public GBF_Signal
{
    public:
        GBF_SquareWave(double Frequency = 1000.0, double Amplitude = 0.5, double Offset = 0, double DutyCycle = 0.5, int Resolution = 8, int SamplingFrequency = 44100);
        virtual void ComputeWaveform (int Resolution, int SamplingFrequency);

        virtual void setDutyCycle(double DutyCycle);
        virtual double DutyCycle() const;

    private:
        double m_DutyCycle;         ///Rapport cyclique
};

#endif // GBF_SQUAREWAVE_H
