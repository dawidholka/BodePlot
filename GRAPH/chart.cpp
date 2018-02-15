#include "chart.h"
#include "ui_chart.h"
#include <math.h>
#include "QDebug"

// TODO DEALOCATE RESOURCES AFTER CLOSING CHART WINDOW!!!

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

Chart::Chart(float amplitude, float zeros[], float poles[], int nzero, int npole,int minX, int maxX)
{
    series = new QLineSeries();
    for(int i=minX;i<maxX;i++){
        float change=pow(10,i);
        float start=pow(10,i);
        float end=pow(10,i+1);
        for(float k=start;end>k;k+=change){
            *series << QPointF(k,logmodulus(k,amplitude,zeros,poles,nzero,npole));
        }
    }
    chart = new QChart();
    chart->addSeries(series);
    chart->legend()->hide();
    chart->setTitle("Bode magnitude plot example");
    axisX = new QLogValueAxis();
    axisX->setTitleText("Frequency (rad/s)");
    char format[] = "%.0f";
    if(minX<0){
        // setting precision
        format[2] = -minX+'0';
    }
    axisX->setLabelFormat(format);
    axisX->setBase(10.0);
    axisX->setMinorTickCount(-1);
    axisX->setRange(pow(10,minX),pow(10,maxX));
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    axisY = new QValueAxis();
    axisY->setTitleText("Magnitude (dB)");
    axisY->setLabelFormat("%d");
    //axisY->setTickCount(series->count());
    //axisY->setRange(0, 10);
    //axisY->setMax(5);
    //axisY->setMin(-5);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    qDebug() << axisY->min();
    qDebug() << axisY->max();
    int maxDb = (axisY->max()/10)+2;
    int minDb = (axisY->min()/10)-2;
    qDebug() << maxDb;
    qDebug() << minDb;
    axisY->setRange(minDb*10,maxDb*10);
    axisY->setTickCount(maxDb-minDb+1);
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->chart()->setTheme(QChart::ChartThemeDark);


    // TODO Add saving plot to file in menubar!
    createAction();
    createMenu();

    window.setCentralWidget(chartView);
    window.resize(800, 600);
    window.setWindowTitle("Bode plot");


    QPalette pal = window.palette();
    pal.setColor(QPalette::Window, QRgb(0x40434a));
    pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
    window.show();
    //handle close event somehow
}

void Chart::createAction()
{
    newAct = new QAction(tr("&New"), this);
        newAct->setShortcuts(QKeySequence::New);
        newAct->setStatusTip(tr("Create a new file"));
        connect(newAct, &QAction::triggered, this, &Chart::newFile);
}

void Chart::newFile()
{
    qDebug() << "new file";
}

void Chart::createMenu()
{
    plotMenu = menuBar()->addMenu(tr("&File"));
    plotMenu->addAction(newAct);
   // plotMenu->addAction(openAct);
    //plotMenu->addAction(saveAct);
    //plotMenu->addAction(printAct);
    plotMenu->addSeparator();
    //plotMenu->addAction(exitAct);
}

Chart::~Chart()
{
    qDebug() << "END?";
    delete ui;
}
