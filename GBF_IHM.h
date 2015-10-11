#ifndef GBF_IHM_H
#define GBF_IHM_H

#include <QMainWindow>

namespace Ui
{
    class GBF_IHM;
}

class GBF_IHM : public QMainWindow
{
    Q_OBJECT

    public:
        explicit GBF_IHM(QWidget *parent = 0);
        ~GBF_IHM();

    private:
        Ui::GBF_IHM *ui;
};

#endif // GBF_IHM_H
