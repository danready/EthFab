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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
    QGridLayout *gridLayout_3;
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
        gridLayout_3 = new QGridLayout(tab_GeneralPurpose);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        textEdit_GeneralPurpose = new QTextEdit(tab_GeneralPurpose);
        textEdit_GeneralPurpose->setObjectName(QStringLiteral("textEdit_GeneralPurpose"));

        gridLayout_3->addWidget(textEdit_GeneralPurpose, 0, 0, 1, 1);

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

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "EthFab", 0));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect...", 0));
        SendBaseCase->setText(QApplication::translate("MainWindow", "Send", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_BaseCase), QApplication::translate("MainWindow", "Base Case", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_GeneralPurpose), QApplication::translate("MainWindow", "General Purpose Structure", 0));
        menuConnect->setTitle(QApplication::translate("MainWindow", "Connect", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
