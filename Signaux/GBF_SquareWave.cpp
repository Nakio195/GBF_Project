#include "GBF_SquareWave.h"

GBF_SquareWave::GBF_SquareWave(double Frequency, double Amplitude, double Offset, double DutyCycle, int Resolution, int SamplingFrequency) : GBF_Signal(Frequency, Amplitude, Offset)
{
    m_Type = GBF_Signal::SQUARE;
    m_DutyCycle = DutyCycle;
    ComputeWaveform(Resolution, SamplingFrequency);
}

void GBF_SquareWave::setDutyCycle(double DutyCycle)
{
    if(DutyCycle > 1.0)
        m_DutyCycle = 1.0;
    else if(DutyCycle < 0.0)
        m_DutyCycle = 0.0;

    else
        m_DutyCycle = DutyCycle;
}

double GBF_SquareWave::DutyCycle() const
{
    return m_DutyCycle;
}

void GBF_SquareWave::ComputeWaveform(int Resolution, int SamplingFrequency)
{
    int NbSamples = 0;
    int MaximumAmplitude = 0;
    int CurrentSample = 0;

    NbSamples = SamplingFrequency/m_Frequency;
    MaximumAmplitude = pow(2, Resolution)/2 -1;

    m_Waveform.clear();

    for(int i = 0; i < NbSamples; i++)
    {
        if(i < m_DutyCycle*NbSamples)
        {
            CurrentSample = int(m_Amplitude * MaximumAmplitude + m_Offset * MaximumAmplitude);
            if(CurrentSample > MaximumAmplitude)
                CurrentSample = MaximumAmplitude;
            else if(CurrentSample < MaximumAmplitude * -1)
                CurrentSample = MaximumAmplitude * -1;

            m_Waveform.push_back(CurrentSample);
        }

        else
        {
            CurrentSample = int(-1 * m_Amplitude * MaximumAmplitude + m_Offset * MaximumAmplitude);
            if(CurrentSample > MaximumAmplitude)
                CurrentSample = MaximumAmplitude;
            else if(CurrentSample < MaximumAmplitude * -1)
                CurrentSample = MaximumAmplitude * -1;

            m_Waveform.push_back(CurrentSample);
        }
    }
}
