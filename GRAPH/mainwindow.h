#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include "zeros.h"
#include "poles.h"
#include "graph.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void addZero();
    void removeZero(Zeros* zero);
    void setAmplitude();
    void addPole();
    void removePole(Poles* pole);
    void updateFrequency();
    void makeGraph();

public:
    void updateSystem();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QScrollArea *scroll;
    QScrollArea *polesScroll;
    double amplitude;
    QVector<Zeros*> mZeros;
    QVector<Poles*> mPoles;
    int minFrequency;
    int maxFrequency;
    Graph *graph;
    QVBoxLayout *zerosLayoutScroll;
    QVBoxLayout *polesLayoutScroll;
};

#endif // MAINWINDOW_H
