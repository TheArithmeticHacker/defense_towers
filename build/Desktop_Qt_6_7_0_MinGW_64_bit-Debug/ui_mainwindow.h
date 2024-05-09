/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *settings;
    QLabel *Title;
    QPushButton *startGame;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(802, 619);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        settings = new QPushButton(centralwidget);
        settings->setObjectName("settings");
        settings->setGeometry(QRect(180, 290, 391, 71));
        settings->setStyleSheet(QString::fromUtf8(" background-color: rgb(16, 57, 0);\n"
"    border-style: solid;\n"
"    color:  rgb(232, 237, 223);\n"
"    border-width: 5px;\n"
"    border-radius: 20px;\n"
"    border-color: rgb(16, 57, 0);\n"
"    font: 48px;\n"
"    padding: 6px;\n"
""));
        Title = new QLabel(centralwidget);
        Title->setObjectName("Title");
        Title->setGeometry(QRect(80, 20, 561, 121));
        QFont font;
        font.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font.setBold(false);
        font.setItalic(false);
        Title->setFont(font);
        Title->setStyleSheet(QString::fromUtf8("    border-style: solid;\n"
"    color:  rgb(47, 102, 144);\n"
"    border-width: 5px;\n"
"    border-radius: 20px;\n"
"    border-color: rgb(16, 57, 0);\n"
"    font: 48px;\n"
"    padding: 6px;\n"
""));
        Title->setAlignment(Qt::AlignCenter);
        startGame = new QPushButton(centralwidget);
        startGame->setObjectName("startGame");
        startGame->setGeometry(QRect(180, 200, 391, 71));
        startGame->setStyleSheet(QString::fromUtf8(" background-color: rgb(16, 57, 0);\n"
"    border-style: solid;\n"
"    color:  rgb(232, 237, 223);\n"
"    border-width: 5px;\n"
"    border-radius: 20px;\n"
"    border-color: rgb(16, 57, 0);\n"
"    font: 48px;\n"
"    padding: 6px;\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 802, 26));
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
        settings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        Title->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#14080e;\">Defense of Towers</span></p></body></html>", nullptr));
        startGame->setText(QCoreApplication::translate("MainWindow", "Start Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
