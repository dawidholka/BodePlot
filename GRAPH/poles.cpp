#include "poles.h"
#include "ui_poles.h"
#include <QInputDialog>

Poles::Poles(const QString& pole,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Poles)
{
    ui->setupUi(this);
    setPole(pole);
    connect(ui->changeValueButton,&QPushButton::clicked,this,&Poles::changeValue);
    connect(ui->deletePoleButton,&QPushButton::clicked,[this, &pole]{
        this->emit removed(this);});
}

void Poles::setPole(const QString& pole)
{
    ui->poleValueLabel->setText(pole);
}

Poles::~Poles()
{
    delete ui;
}

QString Poles::pole() const
{
    return ui->poleValueLabel->text();
}

void Poles::changeValue()
{
    bool ok;
    QString value = QInputDialog::getText(this,tr("Edit pole"),tr("Pole"),QLineEdit::Normal,this->pole(),&ok);
    if(ok&!value.isEmpty()){
        setPole(value);
    }
}
