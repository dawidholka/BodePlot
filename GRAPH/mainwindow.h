#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chart.h"
#include "zeros.h"

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

public:
    void updateSystem();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Chart *chart;
    float amplitude;
    QVector<Zeros*> mZeros;
};

#endif // MAINWINDOW_H
