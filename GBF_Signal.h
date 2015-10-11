#ifndef GBF_SIGNAL_H
#define GBF_SIGNAL_H

#include <vector>

class GBF_Signal
{
    public:
        GBF_Signal(double Frequency = 1000.0, double Amplitude = 0.5, double Offset = 0);
        ~GBF_Signal();

        void setFrequency (double Frequency = 1000.0);
        double Frequency () const;

        void setOffset (double Offset = 0);
        double Offset() const;

        void setAmplitude (double Amplitude = 0.5);
        double Amplitude () const;

        virtual void ComputeWaveform (int Resolution, int SamplingFrequency) = 0;
        const std::vector<double> Waveform ();

    private:
        double m_Frequency;      /// Fréquence en Hz du signal
        double m_Offset;                  /// Composante continue du signal
        double m_Amplitude;               /// Amplitude crête à crête
        std::vector<double> m_Waveform;   /// Contient les points calculés du signal
};


#endif // GBF_SIGNAL_H
