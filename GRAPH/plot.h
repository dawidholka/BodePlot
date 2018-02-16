#ifndef PLOT_H
#define PLOT_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>

class Plot : public QWidget
{
    Q_OBJECT

public:
    explicit Plot(QWidget *parent = 0);
    ~Plot();

private:
    QTextEdit *textEdit;
    QPushButton *closeButton;
};

#endif // PLOT_H
