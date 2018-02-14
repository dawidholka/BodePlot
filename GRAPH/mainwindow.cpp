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
    connect(ui->addPoleButton,&QPushButton::clicked,this,&MainWindow::addPole);
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
    float* poles = new float[mPoles.size()];
    for(int i=0; i<mPoles.size();i++){
        QString value = mPoles[i]->pole();
        poles[i]=value.toFloat();
    }
    chart = new Chart(amplitude,zeros,poles,mZeros.size(),mPoles.size(),0.001,1000);
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

void MainWindow::addPole()
{
    bool ok;
    QString name = QString("%1").arg(QInputDialog::getInt(this,tr("Add pole"),tr("Pole"),0,-2147483647,2147483647,1,&ok));
    if(ok && !name.isEmpty()){
        qDebug() << "Adding new pole";
        Poles* pole = new Poles(name);
        connect(pole, &Poles::removed,this,&MainWindow::removePole);
        mPoles.append(pole);
        ui->polesLayout->addWidget(pole);
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

void MainWindow::removePole(Poles* pole)
{
    mPoles.removeOne(pole);
    ui->polesLayout->removeWidget(pole);
    pole->setParent(0);
    delete pole;
    updateSystem();
}

void MainWindow::updateSystem()
{
    qDebug() << "Updating system";
    QString systemZeros = "";
    for(int i=0;i<mZeros.size();i++){
        qDebug() << "Adding zeros";
        QString value = mZeros[i]->zero();
        float zero=value.toFloat();
        if(zero<0){
            qDebug() << "++";
            zero*=-1;
            systemZeros.append(QString("(s+%1)").arg(zero));
        }else{
            qDebug() << "--";
            systemZeros.append(QString("(s-%1)").arg(zero));
        }
    }
    ui->zerosLabel->setText(systemZeros);
    QString systemPoles = "";
    for(int i=0;i<mPoles.size();i++){
        qDebug() << "Adding poles";
        QString value = mPoles[i]->pole();
        float pole=value.toFloat();
        if(pole<0){
            qDebug() << "++";
            pole*=-1;
            systemPoles.append(QString("(s+%1)").arg(pole));
        }else{
            qDebug() << "--";
            systemPoles.append(QString("(s-%1)").arg(pole));
        }
    }
    ui->polesLabel->setText(systemPoles);
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
