#include "GBF_IHM_Quitter.h"
#include "ui_GBF_IHM_Quitter.h"

GBF_IHM_Quitter::GBF_IHM_Quitter(QWidget *parent) : QWidget(parent), ui(new Ui::GBF_IHM_Quitter)
{
    ui->setupUi(this);
    this->setWindowTitle("Quitter ?");
   QObject::connect(ui->Yes_Button,SIGNAL(clicked(bool)), this, SLOT(Quit_app()));
   QObject::connect(ui->No_Button,SIGNAL(clicked(bool)), this, SLOT(Return_ihm()));
}

GBF_IHM_Quitter::~GBF_IHM_Quitter()
{
    delete ui;
}

void GBF_IHM_Quitter::Quit_app()
{

 //  QWidget *parent = this->parent();
   //parent->close();

}

void GBF_IHM_Quitter::Return_ihm()
{
    this->close();
}
