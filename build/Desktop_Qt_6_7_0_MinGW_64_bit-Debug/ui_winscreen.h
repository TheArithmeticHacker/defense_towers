/********************************************************************************
** Form generated from reading UI file 'winscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINSCREEN_H
#define UI_WINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WinScreen
{
public:
    QLabel *Title;
    QPushButton *MainMenu;
    QPushButton *nextLevel;

    void setupUi(QWidget *WinScreen)
    {
        if (WinScreen->objectName().isEmpty())
            WinScreen->setObjectName("WinScreen");
        WinScreen->resize(821, 585);
        WinScreen->setBaseSize(QSize(0, 0));
        Title = new QLabel(WinScreen);
        Title->setObjectName("Title");
        Title->setGeometry(QRect(70, 0, 561, 121));
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
        MainMenu = new QPushButton(WinScreen);
        MainMenu->setObjectName("MainMenu");
        MainMenu->setGeometry(QRect(50, 200, 291, 71));
        MainMenu->setStyleSheet(QString::fromUtf8(" background-color: rgb(16, 57, 0);\n"
"    border-style: solid;\n"
"    color:  rgb(232, 237, 223);\n"
"    border-width: 5px;\n"
"    border-radius: 20px;\n"
"    border-color: rgb(16, 57, 0);\n"
"    font: 48px;\n"
"    padding: 6px;\n"
""));
        nextLevel = new QPushButton(WinScreen);
        nextLevel->setObjectName("nextLevel");
        nextLevel->setGeometry(QRect(400, 200, 311, 71));
        nextLevel->setStyleSheet(QString::fromUtf8(" background-color: rgb(16, 57, 0);\n"
"    border-style: solid;\n"
"    color:  rgb(232, 237, 223);\n"
"    border-width: 5px;\n"
"    border-radius: 20px;\n"
"    border-color: rgb(16, 57, 0);\n"
"    font: 48px;\n"
"    padding: 6px;\n"
""));

        retranslateUi(WinScreen);

        QMetaObject::connectSlotsByName(WinScreen);
    } // setupUi

    void retranslateUi(QWidget *WinScreen)
    {
        WinScreen->setWindowTitle(QCoreApplication::translate("WinScreen", "Form", nullptr));
        Title->setText(QCoreApplication::translate("WinScreen", "<html><head/><body><p>CONGRATULATIONS</p></body></html>", nullptr));
        MainMenu->setText(QCoreApplication::translate("WinScreen", "Main Menu", nullptr));
        nextLevel->setText(QCoreApplication::translate("WinScreen", "Next Level", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinScreen: public Ui_WinScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINSCREEN_H
