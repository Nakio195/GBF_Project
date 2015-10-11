#include "GBF_IHM.h"
#include "ui_GBF_IHM.h"

GBF_IHM::GBF_IHM(QWidget *parent) : QMainWindow(parent), ui(new Ui::GBF_IHM)
{
    this->setWindowTitle("Projet GBF");
    ui->setupUi(this);
}

GBF_IHM::~GBF_IHM()
{
    delete ui;
}
