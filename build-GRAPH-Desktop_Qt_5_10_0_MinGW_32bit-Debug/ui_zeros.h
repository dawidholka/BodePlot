/********************************************************************************
** Form generated from reading UI file 'zeros.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZEROS_H
#define UI_ZEROS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Zeros
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *changeValueButton;
    QPushButton *deleteZeroButton;

    void setupUi(QWidget *Zeros)
    {
        if (Zeros->objectName().isEmpty())
            Zeros->setObjectName(QStringLiteral("Zeros"));
        Zeros->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(Zeros);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Zeros);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        changeValueButton = new QPushButton(Zeros);
        changeValueButton->setObjectName(QStringLiteral("changeValueButton"));

        horizontalLayout->addWidget(changeValueButton);

        deleteZeroButton = new QPushButton(Zeros);
        deleteZeroButton->setObjectName(QStringLiteral("deleteZeroButton"));

        horizontalLayout->addWidget(deleteZeroButton);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Zeros);

        QMetaObject::connectSlotsByName(Zeros);
    } // setupUi

    void retranslateUi(QWidget *Zeros)
    {
        Zeros->setWindowTitle(QApplication::translate("Zeros", "Form", nullptr));
        label->setText(QApplication::translate("Zeros", "TextLabel", nullptr));
        changeValueButton->setText(QApplication::translate("Zeros", "Change Value", nullptr));
        deleteZeroButton->setText(QApplication::translate("Zeros", "Delete Zero", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Zeros: public Ui_Zeros {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZEROS_H
