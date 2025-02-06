/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *ButtonStart;
    QPushButton *ButtonStop;
    QPlainTextEdit *canList;
    QCheckBox *displayType;
    QRadioButton *radioButton;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1278, 748);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        ButtonStart = new QPushButton(centralwidget);
        ButtonStart->setObjectName("ButtonStart");
        ButtonStart->setGeometry(QRect(80, 190, 121, 51));
        ButtonStop = new QPushButton(centralwidget);
        ButtonStop->setObjectName("ButtonStop");
        ButtonStop->setGeometry(QRect(80, 370, 121, 51));
        canList = new QPlainTextEdit(centralwidget);
        canList->setObjectName("canList");
        canList->setGeometry(QRect(310, 10, 871, 691));
        canList->setStyleSheet(QString::fromUtf8("background-color: black;\n"
"color:white;"));
        displayType = new QCheckBox(centralwidget);
        displayType->setObjectName("displayType");
        displayType->setGeometry(QRect(90, 510, 111, 22));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(90, 550, 91, 22));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(80, 570, 121, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1278, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ButtonStart->setText(QCoreApplication::translate("MainWindow", "Start Can", nullptr));
        ButtonStop->setText(QCoreApplication::translate("MainWindow", "Stop Can", nullptr));
        displayType->setText(QCoreApplication::translate("MainWindow", "Fixed message", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Enable mask", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
