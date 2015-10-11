#include "GBF_IHM.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GBF_IHM w;
    w.setWindowTitle(QString("Projet GBF"));
    w.show();

    return a.exec();
}
