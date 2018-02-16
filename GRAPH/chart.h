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
#include <QMenuBar>
#include <QMainWindow>
#include <QLabel>



using namespace QtCharts;
class QMenu;
class QLabel;

namespace Ui {
class Chart;
}

class Chart : public QWidget
{
    Q_OBJECT

public:
    Chart(float amplitude, float zeros[], float poles[], int nzero, int npole,int minX, int maxX);
    ~Chart();
protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void newFile();
private:
    Ui::Chart *ui;
    QVBoxLayout *vbox;
    QLabel *infoLabel;
    QGridLayout* gridLayout;
    QChartView *chartView;
    QValueAxis *axisY;
    QLogValueAxis *axisX;
    QChart *chart;
    QLineSeries *series;
    QMainWindow *window;
    QMenu *plotMenu;
    void createMenu();
    void createAction();
    QAction *newAct;
};

#endif // CHART_H
