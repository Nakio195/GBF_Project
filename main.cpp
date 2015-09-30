#include "GBF_FaceAvant.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GBF_FaceAvant w;
    w.setWindowTitle(QString("Projet GBF"));
    w.show();

    return a.exec();
}
