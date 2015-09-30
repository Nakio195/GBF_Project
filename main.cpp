#include "GBF_FaceAvant.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GBF_FaceAvant w;
    w.show();

    return a.exec();
}
