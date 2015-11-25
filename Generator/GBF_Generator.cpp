#include "GBF_Generator.h"

GBF_Generator::GBF_Generator(QGraphicsView* Displayer)
{
    m_Type = GBF_Signal::COSINUS;
    m_Amplitude = 0.5;
    m_DutyCycle = 0.5;
    m_Frequency = 1000;
    m_Offset = 0.0;
    m_Resolution = 8;
    m_SamplingFrequency = 44100;
    m_Type = GBF_Signal::COSINUS;

    m_CurrentSignal = new GBF_CosinusWave(m_Frequency, m_Amplitude, m_Offset, m_Resolution, m_SamplingFrequency);

    //Scène et Vue pour la visualisation du signal
    m_Displayer = Displayer;
    m_Displayer->centerOn(0, 0);
    m_Scene = new QGraphicsScene(QRect(0, 0, m_Displayer->width(), m_Displayer->height()));

    m_Scene->setBackgroundBrush(QBrush(QColor("black")));
    m_Displayer->setScene(m_Scene);
    m_Scene->setSceneRect(m_Displayer->width()/-2.0, m_Displayer->height()/-2, m_Displayer->width()/2, m_Displayer->height()/2);
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

    UpdateSignal();
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

    UpdateSignal();
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

    UpdateSignal();
}

double GBF_Generator::Offset ()
{
    return m_CurrentSignal->Offset();
}

void GBF_Generator::setAmplitude (double Amplitude)
{
    m_CurrentSignal->setAmplitude(Amplitude);
    m_Amplitude = Amplitude;

    UpdateSignal();
}

double GBF_Generator::Amplitude ()
{
    return m_CurrentSignal->Amplitude();
}


void GBF_Generator::setResolution (unsigned int Resolution)
{
    m_Resolution = Resolution;

    UpdateSignal();
}

unsigned int GBF_Generator::Resolution ()
{
    return m_Resolution;
}

void GBF_Generator::setSamplingFrequency (unsigned int SamplingFrequency)
{
    m_SamplingFrequency = SamplingFrequency;

    UpdateSignal();
}

unsigned int GBF_Generator::SamplingFrequency()
{
    return m_SamplingFrequency;
}

void GBF_Generator::setSignalType(unsigned int Type)
{
    m_Type = Type;

    UpdateSignal();
}

void GBF_Generator::UpdateSignal()
{

    switch(m_Type)
    {
        case GBF_Signal::SINUS:
            m_CurrentSignal = new GBF_SinusWave(m_Frequency, m_Amplitude, m_Offset, m_Resolution, m_SamplingFrequency);
            break;

        case GBF_Signal::COSINUS:
            m_CurrentSignal = new GBF_CosinusWave(m_Frequency, m_Amplitude, m_Offset, m_Resolution, m_SamplingFrequency);
            break;

        case GBF_Signal::SQUARE:
            m_CurrentSignal = new GBF_SquareWave(m_Frequency, m_Amplitude, m_Offset, m_DutyCycle, m_Resolution, m_SamplingFrequency);
            break;

        case GBF_Signal::TRIANGLE:
            m_CurrentSignal = new GBF_TriangleWave(m_Frequency, m_Amplitude, m_Offset, m_Resolution, m_SamplingFrequency);
            break;
    }


    ScopeRefresh();
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

    double Width = m_Displayer->width();
    double Height = m_Displayer->height();
    double SampleLength = 0;
    int MaximumAmplitude = pow(2, m_Resolution)/2 -1;

    QPen Pen(QColor(255, 255, 255, 255));
    Pen.setWidthF(1);

    std::vector<int> *Waveform = m_CurrentSignal->Waveform();

    if(Waveform->size() != 0)
    {
        NbSamples = Waveform->size();
        SampleLength = Width / NbSamples;

        for(CurrentSample = 0; CurrentSample < Waveform->size(); CurrentSample++)
        {
            int x = CurrentSample*SampleLength;
            int y = (Waveform->at(CurrentSample)*-1*Height)/(2*MaximumAmplitude) + Height/2;

            m_Scene->addLine(x, y, x + SampleLength, y, Pen);
        }
    }
}
