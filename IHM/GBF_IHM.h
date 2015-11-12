#ifndef GBF_IHM_H
#define GBF_IHM_H

#include <QMainWindow>
#include "Signaux/GBF_SquareWave.h"
#include "Signaux/GBF_TriangleWave.h"
#include "Generator/GBF_Generator.h"

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

    public slots:
        void setSignalType(int Type);
        void setFrequency (int Frequency);
        void setDutyCycle (int Duty);
        void setOffset (int Offset);
        void setAmplitude (int Amplitude);

    private:
        Ui::GBF_IHM *ui;
        GBF_Generator* m_Generator;
};

#endif // GBF_IHM_H
