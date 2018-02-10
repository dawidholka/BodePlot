#ifndef CHART_H
#define CHART_H

#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QLogValueAxis>
#include <QtCharts/QValueAxis>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QGridLayout>


using namespace QtCharts;

namespace Ui {
class Chart;
}

class Chart : public QWidget
{
    Q_OBJECT

public:
    explicit Chart(float amplitude, float zeros[], float poles[], int nzero, int npole,int minX, int maxX, QWidget *parent = 0);
    ~Chart();

private:
    Ui::Chart *ui;
    QGridLayout* gridLayout;
    QChartView *chartView;
    QValueAxis *axisY;
    QLogValueAxis *axisX;
    QChart *chart;
    QLineSeries *series;
    QMainWindow window;
};

#endif // CHART_H
