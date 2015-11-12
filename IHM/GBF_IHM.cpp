#include "GBF_IHM.h"
#include "ui_GBF_IHM.h"

GBF_IHM::GBF_IHM(QWidget *parent) : QMainWindow(parent), ui(new Ui::GBF_IHM)
{
    this->setWindowTitle("Projet GBF");
    ui->setupUi(this);

    m_Generator = new  GBF_Generator(ui->gra_View);

    ui->cmb_Resolution->addItem("8 bits", 8);
    ui->cmb_Resolution->addItem("12 bits", 12);
    ui->cmb_Resolution->addItem("16 bits", 16);
    ui->cmb_Resolution->addItem("24 bits", 24);

    ui->cmb_SamplingFrequency->addItem("44100 Hz", 44100);
    ui->cmb_SamplingFrequency->addItem("98200 Hz", 98200);
    ui->cmb_SamplingFrequency->addItem("192000 Hz", 192000);


    ui->cmb_SignalType->addItem("Cosinus", GBF_Signal::COSINUS);
    ui->cmb_SignalType->addItem("Rectangle", GBF_Signal::SQUARE);
    ui->cmb_SignalType->addItem("Triangle", GBF_Signal::TRIANGLE);
    ui->cmb_SignalType->addItem("Sinus", GBF_Signal::SINUS);


}

GBF_IHM::~GBF_IHM()
{
    delete ui;
}


void GBF_IHM::setSignalType(int Type)
{
    switch(Type)
    {
        case GBF_Signal::SINUS:
            ui->rot_DutyCycle->setEnabled(false);
            ui->num_DutyCycle->setEnabled(false);
            break;

        case GBF_Signal::COSINUS:
        ui->rot_DutyCycle->setEnabled(false);
        ui->num_DutyCycle->setEnabled(false);
            break;

        case GBF_Signal::SQUARE:
            ui->rot_DutyCycle->setEnabled(true);
            ui->num_DutyCycle->setEnabled(true);
            break;

        case GBF_Signal::TRIANGLE:
            ui->rot_DutyCycle->setEnabled(false);
            ui->num_DutyCycle->setEnabled(false);
            break;
    }

    m_Generator->setSignal(Type);
}

void GBF_IHM::setFrequency (int Frequency)
{
    m_Generator->setFrequency(Frequency);
}

void GBF_IHM::setDutyCycle (int Duty)
{
    m_Generator->setDutyCycle(Duty);
}

void GBF_IHM::setOffset (int Offset)
{
    m_Generator->setOffset(Offset);
}

void GBF_IHM::setAmplitude (int Amplitude)
{
    m_Generator->setAmplitude(Amplitude);
}

void GBF_IHM::resizeEvent(QResizeEvent *event)
{
    m_Generator->ScopeRefresh();
}
