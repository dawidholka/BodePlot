#include "zeros.h"
#include "ui_zeros.h"
#include <QInputDialog>

Zeros::Zeros(const QString& zero, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Zeros)
{
    ui->setupUi(this);
    setZero(zero);
    connect(ui->changeValueButton,&QPushButton::clicked,this,&Zeros::changeValue);
    connect(ui->deleteZeroButton,&QPushButton::clicked,[this, &zero]{
        this->emit removed(this);});
}

Zeros::~Zeros()
{
    delete ui;
}

void Zeros::setZero(const QString& zero)
{
    ui->label->setText(zero);
}

void Zeros::changeValue()
{
    bool ok;
    QString value = QInputDialog::getText(this,tr("Edit zero"),tr("Zero"),QLineEdit::Normal,this->zero(),&ok);
    if(ok&!value.isEmpty()){
        setZero(value);
    }
}

QString Zeros::zero() const
{
    return ui->label->text();
}
