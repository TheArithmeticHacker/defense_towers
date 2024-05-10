/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QLabel *sound_value;
    QPushButton *save;
    QSlider *sound;
    QComboBox *difficulty;
    QLabel *Settings_2;
    QLabel *Difficult_labe;
    QLabel *sound_label;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName("Settings");
        Settings->resize(779, 740);
        sound_value = new QLabel(Settings);
        sound_value->setObjectName("sound_value");
        sound_value->setGeometry(QRect(610, 220, 71, 20));
        save = new QPushButton(Settings);
        save->setObjectName("save");
        save->setGeometry(QRect(0, 650, 391, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font.setBold(false);
        font.setItalic(false);
        save->setFont(font);
        save->setStyleSheet(QString::fromUtf8(" background-color: rgb(0,0,0);\n"
"    border-style: solid;\n"
"    color:  rgb(255, 255, 255);\n"
"    border-width: 5px;\n"
"    border-radius: 20px;\n"
"    border-color: rgb(255, 0, 0);\n"
"    font: 48px;\n"
"    padding: 6px;\n"
""));
        sound = new QSlider(Settings);
        sound->setObjectName("sound");
        sound->setGeometry(QRect(368, 220, 226, 22));
        sound->setBaseSize(QSize(0, 26));
        sound->setStyleSheet(QString::fromUtf8(""));
        sound->setMaximum(100);
        sound->setSingleStep(5);
        sound->setPageStep(1);
        sound->setOrientation(Qt::Horizontal);
        difficulty = new QComboBox(Settings);
        difficulty->addItem(QString());
        difficulty->addItem(QString());
        difficulty->addItem(QString());
        difficulty->setObjectName("difficulty");
        difficulty->setGeometry(QRect(360, 130, 241, 41));
        difficulty->setStyleSheet(QString::fromUtf8("  /* Reset */\n"
"hover::after{\n"
"color: #f39c12;\n"
"}\n"
"radius: 500px;\n"
"  appearance: none;\n"
"  border: 0;\n"
"  outline: 0;\n"
"  font: inherit;\n"
"  /* Personalize */\n"
"  width: 20rem;\n"
"  padding: 1rem 4rem 1rem 1rem;\n"
"  background: var(--arrow-icon) no-repeat right 0.8em center / 1.4em,\n"
"    linear-gradient(to left, var(--arrow-bg) 3em, var(--select-bg) 3em);\n"
"  color: black;\n"
"  border-radius: 0.25em;\n"
"  box-shadow: 0 0 1em 0 rgba(255, 0, 0, 0.2);\n"
"  cursor: pointer;"));
        Settings_2 = new QLabel(Settings);
        Settings_2->setObjectName("Settings_2");
        Settings_2->setGeometry(QRect(260, 0, 201, 81));
        Settings_2->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font1.setPointSize(24);
        Settings_2->setFont(font1);
        Settings_2->setFrameShadow(QFrame::Sunken);
        Settings_2->setLineWidth(2);
        Settings_2->setMidLineWidth(0);
        Difficult_labe = new QLabel(Settings);
        Difficult_labe->setObjectName("Difficult_labe");
        Difficult_labe->setGeometry(QRect(50, 100, 201, 81));
        Difficult_labe->setMaximumSize(QSize(16777215, 16777215));
        Difficult_labe->setFont(font1);
        Difficult_labe->setFrameShadow(QFrame::Sunken);
        Difficult_labe->setLineWidth(2);
        Difficult_labe->setMidLineWidth(0);
        sound_label = new QLabel(Settings);
        sound_label->setObjectName("sound_label");
        sound_label->setGeometry(QRect(30, 200, 271, 71));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Comic Sans MS")});
        sound_label->setFont(font2);

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "Form", nullptr));
        sound_value->setText(QString());
        save->setText(QCoreApplication::translate("Settings", "Back/Save", nullptr));
        difficulty->setItemText(0, QCoreApplication::translate("Settings", "Easy", nullptr));
        difficulty->setItemText(1, QCoreApplication::translate("Settings", "Medium", nullptr));
        difficulty->setItemText(2, QCoreApplication::translate("Settings", "Hard", nullptr));

        Settings_2->setText(QCoreApplication::translate("Settings", "<html><head/><body><p><span style=\" color:#14080e;\">Settings</span></p></body></html>", nullptr));
        Difficult_labe->setText(QCoreApplication::translate("Settings", "<html><head/><body><p><span style=\" color:#14080e;\">Difficulty</span></p></body></html>", nullptr));
        sound_label->setText(QCoreApplication::translate("Settings", "<html><head/><body><p><span style=\" font-size:24pt;\">Sound Volume</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
