/********************************************************************************
** Form generated from reading UI file 'levelwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVELWINDOW_H
#define UI_LEVELWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LevelWindow
{
public:

    void setupUi(QWidget *LevelWindow)
    {
        if (LevelWindow->objectName().isEmpty())
            LevelWindow->setObjectName("LevelWindow");
        LevelWindow->resize(400, 300);

        retranslateUi(LevelWindow);

        QMetaObject::connectSlotsByName(LevelWindow);
    } // setupUi

    void retranslateUi(QWidget *LevelWindow)
    {
        LevelWindow->setWindowTitle(QCoreApplication::translate("LevelWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LevelWindow: public Ui_LevelWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVELWINDOW_H
