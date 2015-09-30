#ifndef GBF_FACEAVANT_H
#define GBF_FACEAVANT_H

#include <QMainWindow>

namespace Ui {
class GBF_FaceAvant;
}

class GBF_FaceAvant : public QMainWindow
{
    Q_OBJECT

public:
    explicit GBF_FaceAvant(QWidget *parent = 0);
    ~GBF_FaceAvant();

private:
    Ui::GBF_FaceAvant *ui;
};

#endif // GBF_FACEAVANT_H
