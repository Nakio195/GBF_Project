#include "GBF_Signal.h"

GBF_Signal::GBF_Signal(double Frequency, double Amplitude, double Offset)
{
    setFrequency(Frequency);
    setAmplitude(Amplitude);
    setOffset(Offset);
}

GBF_Signal::~GBF_Signal()
{

}

void GBF_Signal::setFrequency (double Frequency)
{
    if(Frequency < 1.0)
        m_Frequency = 1.0;

    else if(Frequency > 22050.0)
        m_Frequency = 22050.0;

    else
        m_Frequency = Frequency;
}

double GBF_Signal::Frequency () const
{
    return m_Frequency;
}

void GBF_Signal::setOffset (double Offset)
{
    if(Offset > 1.0)
        m_Offset = 1.0;

    else if(Offset < -1.0)
        m_Offset = -1.0;

    else
        m_Offset = Offset;
}

double GBF_Signal::Offset() const
{
    return m_Offset;
}

void GBF_Signal::setAmplitude (double Amplitude)
{
    if(Amplitude > 1.0)
        m_Amplitude = 1.0;

    else if(Amplitude < 0.0)
        m_Amplitude = 0.0;

    else
        m_Amplitude = Amplitude;
}

double GBF_Signal::Amplitude() const
{
    return m_Amplitude;
}

const std::vector<double> GBF_Signal::Waveform ()
{
    return m_Waveform;
}
