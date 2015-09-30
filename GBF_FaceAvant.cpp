#include "GBF_FaceAvant.h"
#include "ui_GBF_FaceAvant.h"

GBF_FaceAvant::GBF_FaceAvant(QWidget *parent) : QMainWindow(parent), ui(new Ui::GBF_FaceAvant)
{
    this->setWindowTitle("Projet GBF");
    ui->setupUi(this);
}

GBF_FaceAvant::~GBF_FaceAvant()
{
    delete ui;
}
