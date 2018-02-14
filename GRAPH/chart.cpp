#include "chart.h"
#include "ui_chart.h"
#include <math.h>

float logmodulus(float frequency, float amplitude, float zeros[], float poles[], int nzero, int npole)
{
    // TODO Check this !!
    float result=1;
    for(int i=0;i<nzero;i++){
        result*=(((frequency/zeros[i])*(frequency/zeros[i]))+1);
    }
    for(int i=0;i<npole;i++){
        result/=(((frequency/poles[i])*(frequency/poles[i]))+1);
    }
    return 20*log10(fabs(amplitude)*sqrt(result));
}

/*float phaseshift(float frequency, float amplitude, float zeros[], float poles[], int nzero, int npole)
{
    float result=0;
    for(int i=0;i<nzero;i++){
        result-=(atan(frequency/zeros[i]));
    }
    for(int i=0;i<npole;i++){
        result+=(atan(frequency/poles[i]));
    }
    return result*180/M_PI;
}*/

Chart::Chart(float amplitude, float zeros[], float poles[], int nzero, int npole,int minX, int maxX, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chart)
{
    ui->setupUi(this);
    series = new QLineSeries();
    for(float i=0.01;i<0.01;i+=0.01){
        *series << QPointF((float)i,logmodulus(i,amplitude,zeros,poles,nzero,npole));
    }
    for(float i=0.01;i<0.1;i+=0.01){
        *series << QPointF((float)i,logmodulus(i,amplitude,zeros,poles,nzero,npole));
    }
    for(float i=0.1;i<1;i+=0.1){
        *series << QPointF((float)i,logmodulus(i,amplitude,zeros,poles,nzero,npole));
    }
    for(int i=1;i<10;i++){
        *series << QPointF((float)i,logmodulus(i,amplitude,zeros,poles,nzero,npole));
    }
    for(int i=10;i<100;i+=10){
        *series << QPointF((float)i,logmodulus(i,amplitude,zeros,poles,nzero,npole));
    }
    for(int i=100;i<1000;i+=100){
        *series << QPointF((float)i,logmodulus(i,amplitude,zeros,poles,nzero,npole));
    }
    //*series << QPointF(1.0, 1.0) << QPointF(2.0, 73.0) << QPointF(3.0, 268.0) << QPointF(4.0, 17.0)
               // << QPointF(5.0, 4325.0) << QPointF(6.0, 723.0);
    chart = new QChart();
    chart->addSeries(series);
    chart->legend()->hide();
    chart->setTitle("Bode magnitude plot example");
    axisX = new QLogValueAxis();
    axisX->setTitleText("Frequency");
    axisX->setLabelFormat("%f");
    axisX->setBase(10.0);
    axisX->setMinorTickCount(-1);
    axisX->setRange(minX,maxX);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    axisY = new QValueAxis();
    axisY->setTitleText("Magnitude (dB)");
    axisY->setLabelFormat("%d");
    //axisY->setTickCount(series->count());
    //axisY->setMax(5);
    //axisY->setMin(-5);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    window.setCentralWidget(chartView);
    window.resize(800, 600);
    window.setWindowTitle("Bode polt");
    window.show();
}

Chart::~Chart()
{
    delete ui;
}
