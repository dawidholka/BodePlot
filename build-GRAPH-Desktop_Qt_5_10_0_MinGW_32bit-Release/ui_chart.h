/********************************************************************************
** Form generated from reading UI file 'chart.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHART_H
#define UI_CHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chart
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *chartWidget;

    void setupUi(QWidget *Chart)
    {
        if (Chart->objectName().isEmpty())
            Chart->setObjectName(QStringLiteral("Chart"));
        Chart->resize(400, 300);
        verticalLayout = new QVBoxLayout(Chart);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        chartWidget = new QWidget(Chart);
        chartWidget->setObjectName(QStringLiteral("chartWidget"));

        verticalLayout->addWidget(chartWidget);


        retranslateUi(Chart);

        QMetaObject::connectSlotsByName(Chart);
    } // setupUi

    void retranslateUi(QWidget *Chart)
    {
        Chart->setWindowTitle(QApplication::translate("Chart", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chart: public Ui_Chart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHART_H
