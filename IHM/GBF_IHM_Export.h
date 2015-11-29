#ifndef GBF_IHM_EXPORT_H
#define GBF_IHM_EXPORT_H

#include <QWidget>
#include <QDirModel>

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

    public slots:
        void Export();

    private:
        Ui::GBF_IHM_Export *ui;
        QDirModel *m_TreeView;
};

#endif // GBF_IHM_EXPORT_H
