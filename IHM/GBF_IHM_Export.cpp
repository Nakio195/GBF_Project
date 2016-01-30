#include "GBF_IHM_Export.h"

GBF_IHM_Export::GBF_IHM_Export(GBF_IHM *parent) : QWidget(0), ui(new Ui::GBF_IHM_Export)
{
    ui->setupUi(this);
    this->setWindowTitle("Exporter...");

    m_TreeView = new QDirModel();
    ui->treeView->setModel(m_TreeView);

    m_GeneratorIHM = parent;
}

GBF_IHM_Export::~GBF_IHM_Export()
{
    delete ui;
    delete m_TreeView;
}

void GBF_IHM_Export::Export()
{
    QString FileName;
    double Duration;


    FileName = m_TreeView->filePath(ui->treeView->currentIndex());

    if(FileName == QString(""))
    {
        QMessageBox::critical(this, "Pas de destination !", "Veuillez renseigner une destination pour le fichier WAV !");
        ui->txt_FileName->setFocus();
        return;
    }

    if(ui->txt_FileName->text() == QString(""))
    {
        QMessageBox::critical(this, "Pas de nom de fichier !", "Veuillez renseigner un nom pour le fichier WAV !");
        ui->txt_FileName->setFocus();
        return;
    }

    if(ui->num_Duration->value() <= 0.0)
    {
        QMessageBox::critical(this, "Pas de durée", "Veuillez renseigner une durée pour le fichier WAV !");
        ui->num_Duration->setFocus();
        return;
    }
    if(!ui->txt_FileName->text().contains(QString(".wav"), Qt::CaseInsensitive))
        FileName += ui->txt_FileName->text() + QString(".wav");

    else
        FileName += ui->txt_FileName->text();

    Duration = ui->num_Duration->value();

    m_GeneratorIHM->Export(FileName, Duration);

    this->close();
}
