#include "settings.h"
#include "ui_settings.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>
Settings::Settings(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Settings)
{
    ui->setupUi(this);
    QFile settings("settings.txt");
    if(!settings.open(QIODevice::ReadOnly)) {
        qDebug("Did not work");
    }else{
        QTextStream in(&settings);
        int lineNum = 0;
        while(!in.atEnd()){
            QString line = in.readLine();
            if(lineNum == 0){
                ui->difficulty->setCurrentIndex(line.toInt());
            }else{
                ui->sound->setValue(line.toInt());
            }
            lineNum++;
        }
    }
    settings.close();
}

Settings::~Settings()
{
    //Takes the value of difficulty and sound volume from the user
    QFile settings("settings.txt");
    if(settings.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&settings);
        //Saves their indices to be used when opening the settings page later
        out << QString::number(ui->difficulty->currentIndex()) << "\n";
        out << QString::number(ui->sound->value()) << "\n";
    }else{
        qDebug("Did not work");
    }
    settings.close();
    delete ui;
}

void Settings::on_save_clicked()
{
    emit back();
    delete this;
}


void Settings::on_sound_valueChanged(int value)
{
    ui->sound_value->setText(QString::number(value) + "%");
}

