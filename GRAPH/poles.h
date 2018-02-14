#ifndef POLES_H
#define POLES_H

#include <QWidget>

namespace Ui {
class Poles;
}

class Poles : public QWidget
{
    Q_OBJECT

public slots:
    void changeValue();

signals:
    void removed(Poles* pole);

public:
    explicit Poles(const QString& pole,QWidget *parent = 0);
    ~Poles();
    void setPole(const QString& pole);
    QString pole() const;

private:
    Ui::Poles *ui;
};

#endif // POLES_H
