#ifndef GBF_IHM_EXPORT_H
#define GBF_IHM_EXPORT_H

#include <QWidget>

namespace Ui
{
    class GBF_IHM_Export;
}

class GBF_IHM_Export : public QWidget
{
    Q_OBJECT

    public:
        explicit GBF_IHM_Export(QWidget *parent = 0);
        ~GBF_IHM_Export();

    private:
        Ui::GBF_IHM_Export *ui;
};

#endif // GBF_IHM_EXPORT_H
