#include "GBF_CosinusWave.h"

GBF_CosinusWave::GBF_CosinusWave(double Frequency,double Amplitude,double Offset, int Resolution,int SamplingFrequency): GBF_Signal(Frequency,Amplitude,Offset)
{
    m_Type=GBF_Signal::COSINUS;
    ComputeWaveform(Resolution,SamplingFrequency);
}

void GBF_CosinusWave::ComputeWaveform(int Resolution,int SamplingFrequency)
{
    int NbSamples = 0;
    int MaximumAmplitude = 0;
    int CurrentSample = 0;

    NbSamples = SamplingFrequency/m_Frequency;
    MaximumAmplitude = pow(2, Resolution)/2 -1;
    m_Waveform.clear();

     for(int i = 0; i < NbSamples; i++)
     {
         CurrentSample =MaximumAmplitude*cos(i);
         m_Waveform.push_back(CurrentSample);

     }
}

