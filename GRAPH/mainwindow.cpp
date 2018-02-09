#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->makeChartButton, &QPushButton::clicked,
    this, &MainWindow::makeChart);
}

void MainWindow::makeChart()
{
    qDebug() << "Making Chart";
    chart = new Chart;
    resize(800,600);
    ui->chartLayout->addWidget(chart);
}

MainWindow::~MainWindow()
{
    delete ui;
}
