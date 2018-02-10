/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *system;
    QLabel *amplitudeLabel;
    QVBoxLayout *verticalLayout_4;
    QLabel *zerosLabel;
    QFrame *line;
    QLabel *polesLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *setAmplitudeButton;
    QPushButton *addZeroButton;
    QPushButton *addPoleButton;
    QPushButton *makeChartButton;
    QHBoxLayout *zerospolesLayout;
    QVBoxLayout *zerosLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(577, 390);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        system = new QLabel(centralWidget);
        system->setObjectName(QStringLiteral("system"));

        horizontalLayout_2->addWidget(system);

        amplitudeLabel = new QLabel(centralWidget);
        amplitudeLabel->setObjectName(QStringLiteral("amplitudeLabel"));

        horizontalLayout_2->addWidget(amplitudeLabel);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        zerosLabel = new QLabel(centralWidget);
        zerosLabel->setObjectName(QStringLiteral("zerosLabel"));

        verticalLayout_4->addWidget(zerosLabel);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        polesLabel = new QLabel(centralWidget);
        polesLabel->setObjectName(QStringLiteral("polesLabel"));

        verticalLayout_4->addWidget(polesLabel);


        horizontalLayout_2->addLayout(verticalLayout_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        setAmplitudeButton = new QPushButton(centralWidget);
        setAmplitudeButton->setObjectName(QStringLiteral("setAmplitudeButton"));

        horizontalLayout_2->addWidget(setAmplitudeButton);

        addZeroButton = new QPushButton(centralWidget);
        addZeroButton->setObjectName(QStringLiteral("addZeroButton"));

        horizontalLayout_2->addWidget(addZeroButton);

        addPoleButton = new QPushButton(centralWidget);
        addPoleButton->setObjectName(QStringLiteral("addPoleButton"));

        horizontalLayout_2->addWidget(addPoleButton);

        makeChartButton = new QPushButton(centralWidget);
        makeChartButton->setObjectName(QStringLiteral("makeChartButton"));

        horizontalLayout_2->addWidget(makeChartButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        zerospolesLayout = new QHBoxLayout();
        zerospolesLayout->setSpacing(6);
        zerospolesLayout->setObjectName(QStringLiteral("zerospolesLayout"));
        zerosLayout = new QVBoxLayout();
        zerosLayout->setSpacing(6);
        zerosLayout->setObjectName(QStringLiteral("zerosLayout"));

        zerospolesLayout->addLayout(zerosLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zerospolesLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(zerospolesLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 577, 21));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuHelp->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        system->setText(QApplication::translate("MainWindow", "G(s) = ", nullptr));
        amplitudeLabel->setText(QApplication::translate("MainWindow", "Amplitude", nullptr));
        zerosLabel->setText(QApplication::translate("MainWindow", "Zeros", nullptr));
        polesLabel->setText(QApplication::translate("MainWindow", "Poles", nullptr));
        setAmplitudeButton->setText(QApplication::translate("MainWindow", "Set Amplitude", nullptr));
        addZeroButton->setText(QApplication::translate("MainWindow", "Add Zero", nullptr));
        addPoleButton->setText(QApplication::translate("MainWindow", "Add Pole", nullptr));
        makeChartButton->setText(QApplication::translate("MainWindow", "Make Chart", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
