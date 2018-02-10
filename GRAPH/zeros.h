#ifndef ZEROS_H
#define ZEROS_H

#include <QWidget>

namespace Ui {
class Zeros;
}

class Zeros : public QWidget
{
    Q_OBJECT
public slots:
    void changeValue();
signals:
    void removed(Zeros* zero);

public:
    explicit Zeros(const QString& zero, QWidget *parent = 0);
    ~Zeros();
    void setZero(const QString& zero);
    QString zero() const;
private:
    Ui::Zeros *ui;
};

#endif // ZEROS_H
