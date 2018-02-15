#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chart.h"
#include "zeros.h"
#include "poles.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void makeChart();
    void addZero();
    void removeZero(Zeros* zero);
    void setAmplitude();
    void addPole();
    void removePole(Poles* pole);
    void updateFrequency();

public:
    void updateSystem();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Chart *chart;
    float amplitude;
    QVector<Zeros*> mZeros;
    QVector<Poles*> mPoles;
    int minFrequency;
    int maxFrequency;
};

#endif // MAINWINDOW_H
