#include "graph.h"
#include <QDebug>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMessageBox>

Graph::Graph(QWidget *parent) : QWidget(parent)
{
    closeButton = new QPushButton(tr("&Close"));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
    QVBoxLayout *layout = new QVBoxLayout;
    setLayout(layout);
    setWindowTitle(tr("Bode plot"));
    series = new QLineSeries();
    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Bode magnitude plot example");
    axisX = new QLogValueAxis();
    axisX->setTitleText("Frequency (rad/s)");
    axisX->setBase(10.0);
    axisX->setMinorTickCount(-1);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    axisY = new QValueAxis();
    axisY->setTitleText("Magnitude (dB)");
    axisY->setLabelFormat("%d");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->chart()->setTheme(QChart::ChartThemeDark);
    layout->addWidget(chartView);
    layout->addWidget(closeButton);
    menuBar = new QMenuBar;
    graphMenu = new QMenu("Graph");
    menuBar->addMenu(graphMenu);
    //graphMenu->addAction("Export to .jpg");
    //graphMenu->addAction("Clean");
    layout->setMenuBar(menuBar);

    exportToImageAct = new QAction(tr("&Export"),this);
    exportToImageAct->setShortcut(QKeySequence::Save);
    exportToImageAct->setStatusTip("Export graph as a image to a file");
    connect(exportToImageAct,&QAction::triggered,this,&Graph::exportToImage);
    graphMenu->addAction(exportToImageAct);

}

void Graph::exportToImage()
{
    qDebug() << "EXPORT TO IMAGE";
    QString fileName = QFileDialog::getSaveFileName(this,tr("Export graph to a image"),"",tr("PNG image (*.png);;All Files (*)"));
    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
            return;
        }
        chartView->grab().save(fileName);
    }
}

void Graph::setupGraph(double amplitude, double zeros[], double poles[], int nzero, int npole,int minX, int maxX)
{
    series->clear();
    for(int i=minX;i<maxX;i++){
        float change=pow(10,i);
        float start=pow(10,i);
        float end=pow(10,i+1);
        for(float k=start;end>k;k+=change){
            *series << QPointF(k,calcMagnitude(k,amplitude,zeros,poles,nzero,npole));
        }
    }
    char format[] = "%.0f";
    if(minX<0){
        // setting precision
        format[2] = -minX+'0';
    }
    axisX->setLabelFormat(format);
    axisX->setRange(pow(10,minX),pow(10,maxX));
    QVector<QPointF> yValues = series->pointsVector();
    float minimum = yValues[0].y();
    float maximum = yValues[0].y();
    for(int i=1; i<yValues.size();++i){
        if(yValues[i].y()>maximum){
            maximum = yValues[i].y();
        }
        if(yValues[i].y()<minimum){
            minimum = yValues[i].y();
        }
    }
    int minDb = (minimum/10)-2;
    int maxDb = (maximum/10)+2;
    axisY->setRange(minDb*10,maxDb*10);
    axisY->setTickCount(maxDb-minDb+1);
}

double Graph::calcMagnitude(double frequency, double amplitude, double zeros[], double poles[], int nzero, int npole)
{
    double result=1;
    for(int i=0;i<nzero;i++){
        if(zeros[i]==0){
            result*=(frequency*frequency);
        }else{
            amplitude*=fabs(zeros[i]);
            result*=(((frequency/zeros[i])*(frequency/zeros[i]))+1);
        }
    }
    for(int i=0;i<npole;i++){
        if(poles[i]==0){
            result/=(frequency*frequency);
        }else{
            amplitude/=fabs(poles[i]);
            result/=(((frequency/poles[i])*(frequency/poles[i]))+1);
        }
    }
    return 20*log10(fabs(amplitude)*sqrt(result));
}