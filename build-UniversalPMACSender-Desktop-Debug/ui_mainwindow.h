/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionDeltaTau_PMAC_Geobrick_2;
    QAction *actionTest_LocalHost;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_BaseCase;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit_BaseCase;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_BaseCase;
    QPushButton *SendBaseCase;
    QWidget *tab_GeneralPurpose;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QComboBox *comboBox_RequestType;
    QLabel *label_2;
    QComboBox *comboBox_Request;
    QLabel *label_3;
    QLineEdit *lineEdit_wValue;
    QLabel *label_4;
    QLineEdit *lineEdit_wIndex;
    QLabel *label_5;
    QLineEdit *lineEdit_wLenght;
    QLabel *label_6;
    QLineEdit *lineEdit_bData;
    QPushButton *pushButton_SendStructure;
    QTextEdit *textEdit_GeneralPurpose;
    QMenuBar *menuBar;
    QMenu *menuConnect;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(625, 659);
        QIcon icon;
        icon.addFile(QStringLiteral(":/SpaceFabIcon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionDeltaTau_PMAC_Geobrick_2 = new QAction(MainWindow);
        actionDeltaTau_PMAC_Geobrick_2->setObjectName(QStringLiteral("actionDeltaTau_PMAC_Geobrick_2"));
        actionTest_LocalHost = new QAction(MainWindow);
        actionTest_LocalHost->setObjectName(QStringLiteral("actionTest_LocalHost"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_BaseCase = new QWidget();
        tab_BaseCase->setObjectName(QStringLiteral("tab_BaseCase"));
        gridLayout_2 = new QGridLayout(tab_BaseCase);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit_BaseCase = new QTextEdit(tab_BaseCase);
        textEdit_BaseCase->setObjectName(QStringLiteral("textEdit_BaseCase"));

        verticalLayout->addWidget(textEdit_BaseCase);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_BaseCase = new QLineEdit(tab_BaseCase);
        lineEdit_BaseCase->setObjectName(QStringLiteral("lineEdit_BaseCase"));

        horizontalLayout->addWidget(lineEdit_BaseCase);

        SendBaseCase = new QPushButton(tab_BaseCase);
        SendBaseCase->setObjectName(QStringLiteral("SendBaseCase"));

        horizontalLayout->addWidget(SendBaseCase);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab_BaseCase, QString());
        tab_GeneralPurpose = new QWidget();
        tab_GeneralPurpose->setObjectName(QStringLiteral("tab_GeneralPurpose"));
        verticalLayout_2 = new QVBoxLayout(tab_GeneralPurpose);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label = new QLabel(tab_GeneralPurpose);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        comboBox_RequestType = new QComboBox(tab_GeneralPurpose);
        comboBox_RequestType->setObjectName(QStringLiteral("comboBox_RequestType"));

        gridLayout_3->addWidget(comboBox_RequestType, 0, 1, 1, 1);

        label_2 = new QLabel(tab_GeneralPurpose);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        comboBox_Request = new QComboBox(tab_GeneralPurpose);
        comboBox_Request->setObjectName(QStringLiteral("comboBox_Request"));

        gridLayout_3->addWidget(comboBox_Request, 1, 1, 1, 1);

        label_3 = new QLabel(tab_GeneralPurpose);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_wValue = new QLineEdit(tab_GeneralPurpose);
        lineEdit_wValue->setObjectName(QStringLiteral("lineEdit_wValue"));

        gridLayout_3->addWidget(lineEdit_wValue, 2, 1, 1, 1);

        label_4 = new QLabel(tab_GeneralPurpose);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_wIndex = new QLineEdit(tab_GeneralPurpose);
        lineEdit_wIndex->setObjectName(QStringLiteral("lineEdit_wIndex"));

        gridLayout_3->addWidget(lineEdit_wIndex, 3, 1, 1, 1);

        label_5 = new QLabel(tab_GeneralPurpose);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 4, 0, 1, 1);

        lineEdit_wLenght = new QLineEdit(tab_GeneralPurpose);
        lineEdit_wLenght->setObjectName(QStringLiteral("lineEdit_wLenght"));

        gridLayout_3->addWidget(lineEdit_wLenght, 4, 1, 1, 1);

        label_6 = new QLabel(tab_GeneralPurpose);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 5, 0, 1, 1);

        lineEdit_bData = new QLineEdit(tab_GeneralPurpose);
        lineEdit_bData->setObjectName(QStringLiteral("lineEdit_bData"));

        gridLayout_3->addWidget(lineEdit_bData, 5, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        pushButton_SendStructure = new QPushButton(tab_GeneralPurpose);
        pushButton_SendStructure->setObjectName(QStringLiteral("pushButton_SendStructure"));

        verticalLayout_2->addWidget(pushButton_SendStructure);

        textEdit_GeneralPurpose = new QTextEdit(tab_GeneralPurpose);
        textEdit_GeneralPurpose->setObjectName(QStringLiteral("textEdit_GeneralPurpose"));

        verticalLayout_2->addWidget(textEdit_GeneralPurpose);

        tabWidget->addTab(tab_GeneralPurpose, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 625, 25));
        menuConnect = new QMenu(menuBar);
        menuConnect->setObjectName(QStringLiteral("menuConnect"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuConnect->menuAction());
        menuConnect->addAction(actionConnect);
        menuConnect->addAction(actionDeltaTau_PMAC_Geobrick_2);
        menuConnect->addAction(actionTest_LocalHost);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "EthFab", 0));
        actionConnect->setText(QApplication::translate("MainWindow", "DeltaTau PMAC Geobrick 1", 0));
        actionDeltaTau_PMAC_Geobrick_2->setText(QApplication::translate("MainWindow", "DeltaTau PMAC Geobrick 2", 0));
        actionTest_LocalHost->setText(QApplication::translate("MainWindow", "Test LocalHost", 0));
        SendBaseCase->setText(QApplication::translate("MainWindow", "Send", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_BaseCase), QApplication::translate("MainWindow", "Base Case", 0));
        label->setText(QApplication::translate("MainWindow", "RequestType", 0));
        label_2->setText(QApplication::translate("MainWindow", "Request", 0));
        label_3->setText(QApplication::translate("MainWindow", "wValue", 0));
        label_4->setText(QApplication::translate("MainWindow", "wIndex", 0));
        label_5->setText(QApplication::translate("MainWindow", "wLength", 0));
        label_6->setText(QApplication::translate("MainWindow", "bData", 0));
        pushButton_SendStructure->setText(QApplication::translate("MainWindow", "Send Structure", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_GeneralPurpose), QApplication::translate("MainWindow", "General Purpose Structure", 0));
        menuConnect->setTitle(QApplication::translate("MainWindow", "Connect", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
