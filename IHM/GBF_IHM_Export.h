#ifndef GBF_IHM_EXPORT_H
#define GBF_IHM_EXPORT_H

#include <QWidget>
#include <QDirModel>
#include "ui_GBF_IHM_Export.h"
#include "GBF_IHM.h"
#include "QMessageBox"

namespace Ui
{
    class GBF_IHM_Export;
}

class GBF_IHM;

class GBF_IHM_Export : public QWidget
{
    Q_OBJECT

    public:
        explicit GBF_IHM_Export(GBF_IHM *parent);
        ~GBF_IHM_Export();

    public slots:
        void Export();

    private:
        Ui::GBF_IHM_Export *ui;
        GBF_IHM *m_GeneratorIHM;
        QDirModel *m_TreeView;
};

#endif // GBF_IHM_EXPORT_H
