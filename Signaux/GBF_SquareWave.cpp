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
    int NbSamples = 0;                                  // Création variable nombre d'échantillons
    int MaximumAmplitude = 0;                           // Création variable amplitude maximale
    int CurrentSample = 0;                              // Création variable echantillon en cours de calcul

    NbSamples = SamplingFrequency/m_Frequency;          // Définition du nombre d'échantillon en fonction de la fréquence d'échantillonnage et de la fréquence
    MaximumAmplitude = pow(2, Resolution)/2 -1;         // Définition de l'amplitude maximale en fonction de la résolution
    m_Waveform.clear();                                 // RAZ de l'attribut contenant la waveform


    for(int i = 0; i < NbSamples; i++)                  // boucle de calcul de chaque echantillon

    {
        if(i < m_DutyCycle*NbSamples)                   // Calcul des échantillon de la partie haute du signal
        {
            CurrentSample = int(m_Amplitude * MaximumAmplitude + m_Offset * MaximumAmplitude);      // Formule de calcul partie haute
            if(CurrentSample > MaximumAmplitude)                                                    // Si saturation positive
                CurrentSample = MaximumAmplitude;                                                   // Ecretage positif
            else if(CurrentSample < MaximumAmplitude * -1)                                          // Si saturation négative
                CurrentSample = MaximumAmplitude * -1;                                              // Ecretage négatif

            m_Waveform.push_back(CurrentSample);                                 // Ajout de l'échantillon precedement calculé a la fin de la waveform
        }

        else                                                                     // Calcul des échantillon de la partie basse du signal
        {
            CurrentSample = int(-1 * m_Amplitude * MaximumAmplitude + m_Offset * MaximumAmplitude); // Formule de calcul partie basse
            if(CurrentSample > MaximumAmplitude)                                                    // Si saturation positive
                CurrentSample = MaximumAmplitude;                                                   // Ecretage positif
            else if(CurrentSample < MaximumAmplitude * -1)                                          // Si saturation négative
                CurrentSample = MaximumAmplitude * -1;                                              // Ecretage négatif

           m_Waveform.push_back(CurrentSample);                                  // Ajout de l'échantillon precedement calculé a la fin de la waveform
        }
    }
}
