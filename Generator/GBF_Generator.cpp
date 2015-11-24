#include "GBF_Generator.h"

GBF_Generator::GBF_Generator(QGraphicsView* Displayer)
{
    m_CurrentSignal = new GBF_TriangleWave();

    //Scène et Vue pour la visualisation du signal
    m_Displayer = Displayer;
    m_Displayer->centerOn(0, 0);
    m_Scene = new QGraphicsScene(QRect(0, 0, m_Displayer->width(), m_Displayer->height()));

    m_Scene->setBackgroundBrush(QBrush(QColor("black")));
    m_Displayer->setScene(m_Scene);
    m_Scene->setSceneRect(m_Displayer->width()/-2.0, m_Displayer->height()/-2, m_Displayer->width()/2, m_Displayer->height()/2);

    DisplayGrid();
}

void GBF_Generator::setName (QString Name)
{

}

std::string GBF_Generator::Name ()
{
    return m_Name;
}

GBF_Signal* GBF_Generator::CurrentSignal ()
{
    return m_CurrentSignal;
}

void GBF_Generator::setFrequency (double Frequency)
{
    m_CurrentSignal->setFrequency(Frequency);
    m_Frequency = Frequency;
}

double GBF_Generator::Frequency ()
{
    return m_CurrentSignal->Frequency();
}

void GBF_Generator::setDutyCycle (double Duty)
{
    if(m_CurrentSignal->Type() == GBF_Signal::SQUARE)
    {
        m_CurrentSignal->setDutyCycle(Duty);
    }

    m_DutyCycle = Duty;
}

double GBF_Generator::DutyCycle ()
{
    if(m_CurrentSignal->Type() == GBF_Signal::SQUARE)
    {
        return m_CurrentSignal->DutyCycle();
    }

    return -1.0;
}

void GBF_Generator::setOffset (double Offset)
{
    m_CurrentSignal->setOffset(Offset);
    m_Offset = Offset;
}

double GBF_Generator::Offset ()
{
    return m_CurrentSignal->Offset();
}

void GBF_Generator::setAmplitude (double Amplitude)
{
    m_CurrentSignal->setAmplitude(Amplitude);
    m_Amplitude = Amplitude;
}

double GBF_Generator::Amplitude ()
{
    return m_CurrentSignal->Amplitude();
}

void GBF_Generator::setSignal (unsigned int SignalType)
{
    if(m_CurrentSignal->Type() == SignalType)
        return;

    else
    {
        delete m_CurrentSignal;

        switch(SignalType)
        {
            case GBF_Signal::SINUS:
                m_CurrentSignal = new GBF_SquareWave(m_Frequency, m_Amplitude, m_Offset, m_DutyCycle, m_Resolution, m_SamplingFrequency);
                break;

            case GBF_Signal::COSINUS:
                m_CurrentSignal = new GBF_SquareWave(m_Frequency, m_Amplitude, m_Offset, m_DutyCycle, m_Resolution, m_SamplingFrequency);
                break;

            case GBF_Signal::SQUARE:
                m_CurrentSignal = new GBF_SquareWave(m_Frequency, m_Amplitude, m_Offset, m_DutyCycle, m_Resolution, m_SamplingFrequency);
                break;

            case GBF_Signal::TRIANGLE:
                m_CurrentSignal = new GBF_TriangleWave(m_Frequency, m_Amplitude, m_Offset, m_Resolution, m_SamplingFrequency);
                break;
        }
    }
}


void GBF_Generator::ScopeRefresh()
{
    DisplayGrid();
    DisplaySignal();
    m_Displayer->setSceneRect(m_Scene->itemsBoundingRect());
}

void GBF_Generator::DisplayGrid()
{
    int Width = m_Displayer->width();
    int Height = m_Displayer->height();

    QPen Pen(QColor(0, 255, 0, 255));
    Pen.setWidthF(0.75);

    m_Scene->clear();

    for(int i = 1; i < 10; i++)
    {
        m_Scene->addLine(0, i*Height/10, Width, i*Height/10, Pen);
        m_Scene->addLine(i*Width/10, 0, i*Width/10, Height, Pen);
    }

    Pen.setColor(QColor(255, 255, 255, 255));
    m_Scene->addRect(0, 0, Width, Height, Pen);

}

void GBF_Generator::DisplaySignal()
{
    unsigned int NbSamples = 0;
    unsigned int CurrentSample = 0;

    unsigned int Width = m_Displayer->width();
    unsigned int Height = m_Displayer->height();
    double SampleLength = 0;

    QPen Pen(QColor(0, 0, 255, 255));
    Pen.setWidthF(1);

    std::vector<int> *Waveform = m_CurrentSignal->Waveform();

    if(Waveform->size() != 0)
    {
        NbSamples = Waveform->size();
        SampleLength = Width / NbSamples;

        for(CurrentSample = 0; CurrentSample < Waveform->size(); CurrentSample++)
        {
            m_Scene->addLine(CurrentSample*SampleLength, Waveform->at(CurrentSample) * Height, 2*CurrentSample*SampleLength, Waveform->at(CurrentSample)*Height, Pen);
        }
    }
}
