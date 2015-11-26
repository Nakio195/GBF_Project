#include "GBF_IHM.h"
#include "ui_GBF_IHM.h"

GBF_IHM::GBF_IHM(QWidget *parent) : QMainWindow(parent), ui(new Ui::GBF_IHM)
{
    this->setWindowTitle("Projet GBF");
    ui->setupUi(this);

    m_Generator = new GBF_Generator(ui->gra_View);

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

    ui->cmb_SignalType->setCurrentIndex(0);
    ui->cmb_Resolution->setCurrentIndex(0);
    ui->cmb_SamplingFrequency->setCurrentIndex(0);

    ui->rot_Amplitude->setValue(50);
    ui->rot_DutyCycle->setValue(50);
    ui->rot_Frequency->setValue(1000);
    ui->rot_Offset->setValue(0);
    ui->num_Amplitude->setValue(50);
    ui->num_DutyCycle->setValue(50);
    ui->num_Frequency->setValue(1000);
    ui->num_Offset->setValue(0);

    ui->rot_DutyCycle->setEnabled(false);
    ui->num_DutyCycle->setEnabled(false);

    QObject::connect(ui->cmb_SignalType, SIGNAL(currentIndexChanged(int)), this, SLOT(setSignalType()));
    QObject::connect(ui->cmb_Resolution, SIGNAL(currentIndexChanged(int)), this, SLOT(setResolution()));
    QObject::connect(ui->cmb_SamplingFrequency, SIGNAL(currentIndexChanged(int)), this, SLOT(setSamplingFrequency()));
    QObject::connect(ui->btn_Export, SIGNAL(clicked(bool)), this, SLOT(ShowExportIHM()));
    QObject::connect(ui->actionQuitter,SIGNAL(triggered(bool)), this, SLOT(Exit()));

    QObject::connect(ui->rot_Offset, SIGNAL(valueChanged(int)), ui->num_Offset, SLOT(setValue(int)));
    QObject::connect(ui->rot_Frequency, SIGNAL(valueChanged(int)), ui->num_Frequency, SLOT(setValue(int)));
    QObject::connect(ui->rot_DutyCycle, SIGNAL(valueChanged(int)), ui->num_DutyCycle, SLOT(setValue(int)));
    QObject::connect(ui->rot_Amplitude, SIGNAL(valueChanged(int)), ui->num_Amplitude, SLOT(setValue(int)));

    QObject::connect(ui->num_Frequency, SIGNAL(valueChanged(int)), ui->rot_Frequency, SLOT(setValue(int)));
    QObject::connect(ui->num_DutyCycle, SIGNAL(valueChanged(int)), ui->rot_DutyCycle, SLOT(setValue(int)));
    QObject::connect(ui->num_Amplitude, SIGNAL(valueChanged(int)), ui->rot_Amplitude, SLOT(setValue(int)));
    QObject::connect(ui->num_Offset, SIGNAL(valueChanged(int)), ui->rot_Offset, SLOT(setValue(int)));

    QObject::connect(ui->num_Frequency, SIGNAL(valueChanged(int)), this, SLOT(setFrequency(int)));
    QObject::connect(ui->num_DutyCycle, SIGNAL(valueChanged(int)), this, SLOT(setDutyCycle(int)));
    QObject::connect(ui->num_Amplitude, SIGNAL(valueChanged(int)), this, SLOT(setAmplitude(int)));
    QObject::connect(ui->num_Offset, SIGNAL(valueChanged(int)), this, SLOT(setOffset(int)));
}

GBF_IHM::~GBF_IHM()
{
    delete ui;
    delete m_Generator;
}


void GBF_IHM::setSignalType()
{

    int Type = ui->cmb_SignalType->currentData().toInt();

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

    m_Generator->setSignalType(Type);
}

void GBF_IHM::setResolution()
{
    m_Generator->setResolution(ui->cmb_Resolution->currentData().toInt());
}

void GBF_IHM::setSamplingFrequency()
{
    m_Generator->setSamplingFrequency(ui->cmb_SamplingFrequency->currentData().toInt());
}

void GBF_IHM::setFrequency (int Frequency)
{
    m_Generator->setFrequency(Frequency);
}

void GBF_IHM::setDutyCycle (int Duty)
{
    m_Generator->setDutyCycle(double(Duty/100.0));
}

void GBF_IHM::setOffset (int Offset)
{
    m_Generator->setOffset(double(Offset/100.0));
}

void GBF_IHM::setAmplitude (int Amplitude)
{
    m_Generator->setAmplitude(double(Amplitude/100.0));
}


void GBF_IHM::resizeEvent(QResizeEvent *event)
{
    m_Generator->ScopeRefresh();
}


void GBF_IHM::ShowExportIHM()
{
    if(m_Export_IHM != NULL)
        delete m_Export_IHM;

    m_Export_IHM = new GBF_IHM_Export();
    m_Export_IHM->show();
}

  void GBF_IHM::Exit()
  {
      delete ui;
      delete m_Generator;
      this->close();
  }
