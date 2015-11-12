#include "GBF_TriangleWave.h"

GBF_TriangleWave::GBF_TriangleWave(double Frequency, double Amplitude, double Offset, int Resolution, int SamplingFrequency) : GBF_Signal(Frequency, Amplitude, Offset)
{
    m_Type = GBF_Signal::TRIANGLE;
    ComputeWaveform(Resolution, SamplingFrequency);
}


void GBF_TriangleWave::setDutyCycle(double DutyCycle)
{}

double GBF_TriangleWave::DutyCycle() const
{}


void GBF_TriangleWave::ComputeWaveform(int Resolution, int SamplingFrequency)
{
    int NbSamples = 0;
    int MaximumAmplitude = 0;
    int CurrentSample = 0;

    NbSamples = SamplingFrequency/m_Frequency;
    MaximumAmplitude = pow(2, Resolution)/2 -1;

    m_Waveform.clear();

    for(int i = 0; i < NbSamples; i++)
    {
        if(i < NbSamples/2)
        {
            CurrentSample = int(-1 * m_Amplitude * MaximumAmplitude + (4*m_Amplitude*MaximumAmplitude/(NbSamples))*i + m_Offset * MaximumAmplitude);

            if(CurrentSample > MaximumAmplitude)
                CurrentSample = MaximumAmplitude;
            else if(CurrentSample < MaximumAmplitude * -1)
                CurrentSample = MaximumAmplitude * -1;

            m_Waveform.push_back(CurrentSample);
        }

        else
        {
            CurrentSample = int(m_Amplitude * MaximumAmplitude + (4*m_Amplitude*MaximumAmplitude/(NbSamples))*(i - NbSamples/2)*-1 + m_Offset * MaximumAmplitude);

            if(CurrentSample > MaximumAmplitude)
                CurrentSample = MaximumAmplitude;
            else if(CurrentSample < MaximumAmplitude * -1)
                CurrentSample = MaximumAmplitude * -1;

            m_Waveform.push_back(CurrentSample);
        }
    }
}
