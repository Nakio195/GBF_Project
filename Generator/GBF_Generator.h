#ifndef GBF_GENERATOR_H
#define GBF_GENERATOR_H

#include <string.h>
#include <QGraphicsView>
#include <QFile>
#include <QDataStream>
#include <QTextStream>
#include <QIODevice>
#include <QMessageBox>

#include "Signaux/GBF_Signal.h"
#include "Signaux/GBF_SquareWave.h"
#include "Signaux/GBF_TriangleWave.h"
#include "Signaux/GBF_CosinusWave.h"
#include "Signaux/GBF_SinusWave.h"

class GBF_Generator
{

    public:
        GBF_Generator(QGraphicsView* Displayer);

        void setName (QString Name);
        std::string Name ();
        GBF_Signal* CurrentSignal ();

        void setFrequency (double Frequency = 1000.0);
        double Frequency ();

        void setDutyCycle (double Duty = 0.5);
        double DutyCycle ();

        void setOffset (double Offset = 0);
        double Offset ();

        void setAmplitude (double Amplitude = 0);
        double Amplitude ();

        void setResolution (unsigned int Resolution = 8);
        unsigned int Resolution();

        void setSamplingFrequency (unsigned int SamplingFrequency = 44100);
        unsigned int SamplingFrequency ();

        void setSignalType(unsigned int Type);
        void UpdateSignal();

        void DisplayGrid();
        void DisplaySignal();
        void ScopeRefresh();            /// Rafraichit et redessine la zone de dessin

        void Export(double Duration, QString FilePath);                  /// Création du fichier Wave

    private:
        std::string m_Name;                 /// Nom du générateur
        GBF_Signal* m_CurrentSignal;        /// Pointeur sur un signal courant créer dynamiquement
        QGraphicsView* m_Displayer;     /// Vue de l'IHM pouvant afficher une scène
        QGraphicsScene *m_Scene;
        double m_Frequency;             /// Fréquence du signal.
        double m_Amplitude;             /// Amplitude du signal en pourcentage de la pleine échelle en fonction de la rés
        double m_DutyCycle;             /// Rapport cyclique du signal de 0% à 100%
        double m_Offset;                /// Composante continue en pourcentage de la pleine échelle en fonction de la rés

        int m_Resolution;
        int m_SamplingFrequency;
        int m_Type;
};


#endif // GBF_GENERATOR_H
