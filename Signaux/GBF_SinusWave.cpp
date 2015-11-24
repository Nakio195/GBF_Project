#include "GBF_SinusWave.h"


GBF_SinusWave::GBF_SinusWave(double Frequency, double Amplitude, double Offset, int Resolution,int SamplingFrequency): GBF_Signal(Frequency,Amplitude,Offset)
{
    m_Type = GBF_Signal::SINUS;
    ComputeWaveform(Resolution,SamplingFrequency);
}

void GBF_SinusWave::ComputeWaveform(int Resolution,int SamplingFrequency)
{
    int NbSamples = 0;
    int MaximumAmplitude = 0;
    int CurrentSample = 0;

    NbSamples = SamplingFrequency/m_Frequency;
    MaximumAmplitude = pow(2, Resolution)/2 -1;
    m_Waveform.clear();

     for(int i = 0; i < NbSamples; i++)
     {
         CurrentSample =m_Amplitude*sin(i*2*M_PI/NbSamples)+m_Offset;

         if(CurrentSample > MaximumAmplitude)
             CurrentSample = MaximumAmplitude;
         else if(CurrentSample < MaximumAmplitude * -1)
             CurrentSample = MaximumAmplitude * -1;

         m_Waveform.push_back(CurrentSample);

     }
}

void GBF_SinusWave::setDutyCycle(double DutyCycle)
{}
double GBF_SinusWave::DutyCycle() const
{}
