#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QInputDialog>
#include <QCheckBox>


/*
TODO better UI at mainwindow
TODO add phase shift plot
*/


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mZeros()
{
    ui->setupUi(this);
    connect(ui->addZeroButton,&QPushButton::clicked,this,&MainWindow::addZero);
    connect(ui->addPoleButton,&QPushButton::clicked,this,&MainWindow::addPole);
    connect(ui->setAmplitudeButton,&QPushButton::clicked,this,&MainWindow::setAmplitude);
    connect(ui->minFrequencySpinBox,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),this,&MainWindow::updateFrequency);
    connect(ui->maxFrequencySpinBox,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),this,&MainWindow::updateFrequency);
    amplitude = 1;
    minFrequency = -3;
    maxFrequency = 3;
    connect(ui->testButton, &QPushButton::clicked,this, &MainWindow::makeGraph);

    graph = new Graph();
    //graph->resize(800,600);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::black);
    graph->setAutoFillBackground(true);
    graph->setPalette(pal);

    scroll = new QScrollArea;
    scroll->setWidgetResizable(true);
    scroll->setWidget(ui->zerosWidget);
    zerosLayoutScroll = new QVBoxLayout(ui->zerosWidget);
    ui->zerosLayout->addWidget(scroll);

    polesScroll = new QScrollArea;
    polesScroll->setWidgetResizable(true);
    polesScroll->setWidget(ui->polesWidget);
    polesLayoutScroll = new QVBoxLayout(ui->polesWidget);
    ui->polesLayout->addWidget(polesScroll);

}

void MainWindow::makeGraph()
{
    bool makePhaseShiftGraph = false;
    if(ui->phaseShiftCheckBox->isChecked()){
        qDebug() << "Add a phase shift graph";
        makePhaseShiftGraph = true;
    }
    qDebug() << "Making Graph";
    double* zeros = new double[mZeros.size()];
    for(int i=0; i<mZeros.size();i++){
        QString value = mZeros[i]->zero();
        zeros[i]=value.toFloat();
    }
    double* poles = new double[mPoles.size()];
    for(int i=0; i<mPoles.size();i++){
        QString value = mPoles[i]->pole();
        poles[i]=value.toFloat();
    }
    graph->setupGraph(amplitude,zeros,poles,mZeros.size(),mPoles.size(),minFrequency,maxFrequency,makePhaseShiftGraph);
    graph->show();
}

void MainWindow::addZero()
{
    bool ok;
    QString name = QString("%1").arg(QInputDialog::getDouble(this,tr("Add zero"),tr("Zero value: "),0,-2147483647,2147483647,7,&ok));
    if(ok && !name.isEmpty()){
        qDebug() << "Adding new zero";
        Zeros* zero = new Zeros(name);
        connect(zero, &Zeros::removed,this,&MainWindow::removeZero);
        mZeros.append(zero);
        zerosLayoutScroll->addWidget(zero);
        updateSystem();
    }
}

void MainWindow::addPole()
{
    bool ok;
    QString name = QString("%1").arg(QInputDialog::getDouble(this,tr("Add pole"),tr("Pole value:"),0,-2147483647,2147483647,7,&ok));
    if(ok && !name.isEmpty()){
        qDebug() << "Adding new pole";
        Poles* pole = new Poles(name);
        connect(pole, &Poles::removed,this,&MainWindow::removePole);
        mPoles.append(pole);
        polesLayoutScroll->addWidget(pole);
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
        }else if(zero==0){
            qDebug() << 0;
            systemZeros.append(QString("s"));
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
        }else if(pole==0){
            qDebug() << 0;
            systemPoles.append(QString("s"));
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

void MainWindow::updateFrequency()
{
    minFrequency = ui->minFrequencySpinBox->value();
    maxFrequency = ui->maxFrequencySpinBox->value();
}

MainWindow::~MainWindow()
{
    qDebug() << "MainWindow destructor";
    delete graph;
    delete ui;
}
