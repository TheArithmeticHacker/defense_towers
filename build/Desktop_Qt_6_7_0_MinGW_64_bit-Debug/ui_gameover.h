/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameOver
{
public:
    QLabel *Title;
    QPushButton *MainMenu;
    QPushButton *tryAgain;

    void setupUi(QWidget *GameOver)
    {
        if (GameOver->objectName().isEmpty())
            GameOver->setObjectName("GameOver");
        GameOver->resize(786, 589);
        Title = new QLabel(GameOver);
        Title->setObjectName("Title");
        Title->setGeometry(QRect(100, 50, 561, 121));
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
        MainMenu = new QPushButton(GameOver);
        MainMenu->setObjectName("MainMenu");
        MainMenu->setGeometry(QRect(30, 250, 291, 71));
        MainMenu->setStyleSheet(QString::fromUtf8(" background-color: rgb(16, 57, 0);\n"
"    border-style: solid;\n"
"    color:  rgb(232, 237, 223);\n"
"    border-width: 5px;\n"
"    border-radius: 20px;\n"
"    border-color: rgb(16, 57, 0);\n"
"    font: 48px;\n"
"    padding: 6px;\n"
""));
        tryAgain = new QPushButton(GameOver);
        tryAgain->setObjectName("tryAgain");
        tryAgain->setGeometry(QRect(430, 250, 311, 71));
        tryAgain->setStyleSheet(QString::fromUtf8(" background-color: rgb(16, 57, 0);\n"
"    border-style: solid;\n"
"    color:  rgb(232, 237, 223);\n"
"    border-width: 5px;\n"
"    border-radius: 20px;\n"
"    border-color: rgb(16, 57, 0);\n"
"    font: 48px;\n"
"    padding: 6px;\n"
""));

        retranslateUi(GameOver);

        QMetaObject::connectSlotsByName(GameOver);
    } // setupUi

    void retranslateUi(QWidget *GameOver)
    {
        GameOver->setWindowTitle(QCoreApplication::translate("GameOver", "Form", nullptr));
        Title->setText(QCoreApplication::translate("GameOver", "<html><head/><body><p><span style=\" color:#14080e;\">GAME OVER</span></p></body></html>", nullptr));
        MainMenu->setText(QCoreApplication::translate("GameOver", "Main Menu", nullptr));
        tryAgain->setText(QCoreApplication::translate("GameOver", "Try Again", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameOver: public Ui_GameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
