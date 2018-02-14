/********************************************************************************
** Form generated from reading UI file 'poles.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POLES_H
#define UI_POLES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Poles
{
public:
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *poleValueLabel;
    QPushButton *deletePoleButton;
    QPushButton *changeValueButton;

    void setupUi(QWidget *Poles)
    {
        if (Poles->objectName().isEmpty())
            Poles->setObjectName(QStringLiteral("Poles"));
        Poles->resize(400, 300);
        horizontalLayout = new QHBoxLayout(Poles);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        poleValueLabel = new QLabel(Poles);
        poleValueLabel->setObjectName(QStringLiteral("poleValueLabel"));

        horizontalLayout_2->addWidget(poleValueLabel);

        deletePoleButton = new QPushButton(Poles);
        deletePoleButton->setObjectName(QStringLiteral("deletePoleButton"));

        horizontalLayout_2->addWidget(deletePoleButton);

        changeValueButton = new QPushButton(Poles);
        changeValueButton->setObjectName(QStringLiteral("changeValueButton"));

        horizontalLayout_2->addWidget(changeValueButton);


        horizontalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Poles);

        QMetaObject::connectSlotsByName(Poles);
    } // setupUi

    void retranslateUi(QWidget *Poles)
    {
        Poles->setWindowTitle(QApplication::translate("Poles", "Form", nullptr));
        poleValueLabel->setText(QApplication::translate("Poles", "Pole", nullptr));
        deletePoleButton->setText(QApplication::translate("Poles", "Delete Pole", nullptr));
        changeValueButton->setText(QApplication::translate("Poles", "Change Value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Poles: public Ui_Poles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLES_H
