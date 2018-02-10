#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mZeros()
{
    ui->setupUi(this);
    connect(ui->makeChartButton, &QPushButton::clicked,
    this, &MainWindow::makeChart);
    connect(ui->addZeroButton,&QPushButton::clicked,this,&MainWindow::addZero);
    connect(ui->setAmplitudeButton,&QPushButton::clicked,this,&MainWindow::setAmplitude);
    amplitude = 1;
    //updateSystem();
}

void MainWindow::makeChart()
{
    qDebug() << "Making Chart";
    float* zeros = new float[mZeros.size()];
    for(int i=0; i<mZeros.size();i++){
        QString value = mZeros[i]->zero();
        zeros[i]=value.toFloat();
    }
    //float zeros[1] = {100};
    float poles[1] = {1};
    chart = new Chart(amplitude,zeros,poles,mZeros.size(),1,0.001,1000);
    //ui->chartLayout->addWidget(chart);
}

void MainWindow::addZero()
{
    bool ok;
    QString name = QString("%1").arg(QInputDialog::getInt(this,tr("Add zero"),tr("Zero"),0,-2147483647,2147483647,1,&ok));
    if(ok && !name.isEmpty()){
        qDebug() << "Adding new zero";
        Zeros* zero = new Zeros(name);
        connect(zero, &Zeros::removed,this,&MainWindow::removeZero);
        mZeros.append(zero);
        ui->zerosLayout->addWidget(zero);
        updateSystem();
    }
}

void MainWindow::removeZero(Zeros* zero)
{
    mZeros.removeOne(zero);
    ui->zerosLayout->removeWidget(zero);
    zero->setParent(0);
    delete zero;
    updateSystem();
}

void MainWindow::updateSystem()
{
    qDebug() << "Updating system";
    QString systemZeros = "";
    for(int i=0;i<mZeros.size();i++){
        qDebug() << "Adding zeros";
        systemZeros.append(QString("(s+%1)").arg(mZeros[i]->zero()));
    }
    ui->zerosLabel->setText(systemZeros);
}

void MainWindow::setAmplitude()
{
    qDebug() << "Setting amplitude";
    bool ok;
    amplitude = QInputDialog::getDouble(this,tr("Set amplitude"),tr("Amplitude"),0,-2147483647,2147483647,1,&ok);
    if(ok){
        ui->amplitudeLabel->setText(QString("%1").arg(amplitude));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
