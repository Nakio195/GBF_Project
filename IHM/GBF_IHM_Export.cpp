#include "GBF_IHM_Export.h"
#include "ui_GBF_IHM_Export.h"

GBF_IHM_Export::GBF_IHM_Export(QWidget *parent) : QWidget(parent), ui(new Ui::GBF_IHM_Export)
{
    ui->setupUi(this);
    this->setWindowTitle("Exporter...");
}

GBF_IHM_Export::~GBF_IHM_Export()
{
    delete ui;
}
