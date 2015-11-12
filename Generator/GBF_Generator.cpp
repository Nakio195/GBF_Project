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
    //m_Displayer->ensureVisible(0, 0, m_Displayer->width(), m_Displayer->height());

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
    m_Displayer->setSceneRect(m_Scene->itemsBoundingRect());
}

void GBF_Generator::DisplayGrid()
{
    int width = m_Displayer->width();
    int height = m_Displayer->height();

    //m_Scene

    QPen Pen(QColor(0, 255, 0, 255));
    Pen.setWidthF(0.75);

    m_Scene->clear();

    for(int i = 1; i < 10; i++)
    {
       // m_Scene->addLine()
        m_Scene->addLine(0, i*height/10, width, i*height/10, Pen);
        m_Scene->addLine(i*width/10, 0, i*width/10, height, Pen);
    }

    Pen.setColor(QColor(255, 255, 255, 255));
    m_Scene->addRect(0, 0, width, height, Pen);

}
