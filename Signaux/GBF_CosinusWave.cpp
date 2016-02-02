#include "GBF_CosinusWave.h"

GBF_CosinusWave::GBF_CosinusWave(double Frequency, double Amplitude, double Offset, int Resolution,int SamplingFrequency) : GBF_Signal(Frequency,Amplitude,Offset)
{
    m_Type=GBF_Signal::COSINUS;
    ComputeWaveform(Resolution,SamplingFrequency);
}

void GBF_CosinusWave::ComputeWaveform(int Resolution,int SamplingFrequency)
{
    int NbSamples = 0;                                  // Création variable nombre d'échantillons
    int MaximumAmplitude = 0;                           // Création variable amplitude maximale
    int CurrentSample = 0;                              // Création variable echantillon en cours de calcul

    NbSamples = SamplingFrequency/m_Frequency;          // Définition du nombre d'échantillon en fonction de la fréquence d'échantillonnage et de la fréquence
    MaximumAmplitude = pow(2, Resolution)/2 -1;         // Définition de l'amplitude maximale en fonction de la résolution
    m_Waveform.clear();                                 // RAZ de l'attribut contenant la waveform

    m_Waveform.resize(NbSamples);
     for(int i = 0; i < NbSamples; i++)                 // boucle de calcul de chaque echantillon
     { 

         CurrentSample = m_Amplitude *MaximumAmplitude*cos(i*2*M_PI/NbSamples) + m_Offset*MaximumAmplitude;       // Calcul de l'échantillon en fonction du signal

         if(CurrentSample > MaximumAmplitude)                               // Si saturation positive
             CurrentSample = MaximumAmplitude;                              // Ecretage positif
         else if(CurrentSample < MaximumAmplitude * -1)                     // Si saturation négative
             CurrentSample = MaximumAmplitude * -1;                         // Ecretage négatif

         m_Waveform[i] = CurrentSample;                               // Ajout de l'échantillon precedement calculé a la fin de la waveform

     }
}

void GBF_CosinusWave::setDutyCycle(double DutyCycle)
{}
double GBF_CosinusWave::DutyCycle() const
{return 0;}
