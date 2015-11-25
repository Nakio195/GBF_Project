#include "GBF_TriangleWave.h"

GBF_TriangleWave::GBF_TriangleWave(double Frequency, double Amplitude, double Offset, int Resolution, int SamplingFrequency) : GBF_Signal(Frequency, Amplitude, Offset)
{
    m_Type = GBF_Signal::TRIANGLE;
    ComputeWaveform(Resolution, SamplingFrequency);
}


void GBF_TriangleWave::setDutyCycle(double DutyCycle)
{}

double GBF_TriangleWave::DutyCycle() const
{return 0;}


void GBF_TriangleWave::ComputeWaveform(int Resolution, int SamplingFrequency)
{
    int NbSamples = 0;                                  // Création variable nombre d'échantillons
    int MaximumAmplitude = 0;                           // Création variable amplitude maximale
    int CurrentSample = 0;                              // Création variable echantillon en cours de calcul

    NbSamples = SamplingFrequency/m_Frequency;          // Définition du nombre d'échantillon en fonction de la fréquence d'échantillonnage et de la fréquence
    MaximumAmplitude = pow(2, Resolution)/2 -1;         // Définition de l'amplitude maximale en fonction de la résolution
    m_Waveform.clear();                                 // RAZ de l'attribut contenant la waveform

    for(int i = 0; i < NbSamples; i++)                  // Boucle de calcul pour chaque échantillon
    {
        if(i < NbSamples/2)                             // Calcul des échantillons pour la descente du signal triangle
        {
            CurrentSample = int(-1 * m_Amplitude * MaximumAmplitude + (4*m_Amplitude*MaximumAmplitude/(NbSamples))*i + m_Offset * MaximumAmplitude);

            if(CurrentSample > MaximumAmplitude)                    // Si saturation positive
                CurrentSample = MaximumAmplitude;                   // Ecretage positif
            else if(CurrentSample < MaximumAmplitude * -1)          // Si saturation négative
                CurrentSample = MaximumAmplitude * -1;              // Ecretage négatif

            m_Waveform.push_back(CurrentSample);        // Ajout de l'échantillon precedement calculé a la fin de la waveform
        }

        else                                            // Calcul des échantillons pour la montée du signal triangle (même principe)
        {
            CurrentSample = int(m_Amplitude * MaximumAmplitude + (4*m_Amplitude*MaximumAmplitude/(NbSamples))*(i - NbSamples/2)*-1 + m_Offset * MaximumAmplitude);

            if(CurrentSample > MaximumAmplitude)
                CurrentSample = MaximumAmplitude;
            else if(CurrentSample < MaximumAmplitude * -1)
                CurrentSample = MaximumAmplitude * -1;

            m_Waveform.push_back(CurrentSample);        // Ajout de l'échantillon precedement calculé a la fin de la waveform

        }
    }
}
