#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupChart();
    ui>chartWidget->
    ui(MainWindow::chart)->chartView;
    setCentralWidget(chartView);
}

void MainWindow::setupChart()
{
    series = new QLineSeries();
    *series << QPointF(1.0, 1.0) << QPointF(2.0, 73.0) << QPointF(3.0, 268.0) << QPointF(4.0, 17.0)
            << QPointF(5.0, 4325.0) << QPointF(6.0, 723.0);

    chart = new QChart();
    chart->addSeries(series);
    chart->legend()->hide();
    chart->setTitle("Logarithmic axis example");

    axisX = new QValueAxis();
    axisX->setTitleText("Data point");
    axisX->setLabelFormat("%i");
    axisX->setTickCount(series->count());
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    axisY = new QLogValueAxis();
    axisY->setTitleText("Values");
    axisY->setLabelFormat("%g");
    axisY->setBase(8.0);
    axisY->setMinorTickCount(-1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}

MainWindow::~MainWindow()
{
    delete ui;
}