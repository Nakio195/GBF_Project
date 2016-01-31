#ifndef GBF_IHM_QUITTERR_H
#define GBF_IHM_QUITTERR_H

#include <QWidget>
#include "QMainWindow"

namespace Ui
{
    class GBF_IHM_Quitter;
}

class GBF_IHM_Quitter : public QWidget
{
    Q_OBJECT

    public:
        explicit GBF_IHM_Quitter(QWidget *parent = 0);
        ~GBF_IHM_Quitter();

    public slots:
        void Quit_app();
        void Return_ihm();

    private:
        Ui::GBF_IHM_Quitter *ui;
};

#endif // GBF_IHM_QUITTERR_H
