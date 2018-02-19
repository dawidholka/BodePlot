#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include <math.h>
#include <QPushButton>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QLogValueAxis>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QMenuBar>

using namespace QtCharts;

class Graph : public QWidget
{
    Q_OBJECT
public:
    explicit Graph(QWidget *parent = nullptr);
    void setupGraph(double amplitude, double zeros[], double poles[], int nzero, int npole,int minX, int maxX, bool makePhaseShiftGraph);
signals:

public slots:
private slots:
    void exportToImage();
private:
    QVBoxLayout *layout;
    QPushButton *closeButton;
    QChartView *chartView;
    QValueAxis *axisY;
    QLogValueAxis *axisX;
    QChart *chart;
    QLineSeries *series;
    QMenuBar *menuBar;
    QMenu *graphMenu;
    QAction *exportToImageAct;
    double calcMagnitude(double frequency, double amplitude, double zeros[], double poles[], int nzero, int npole);
    double calcPhase(double frequency, double amplitude, double zeros[], double poles[], int nzero, int npole);
    QChartView *phaseChartView;
    QValueAxis *phaseAxisY;
    QLogValueAxis *phaseAxisX;
    QChart *phaseChart;
    QLineSeries *phaseSeries;
};

#endif // GRAPH_H
