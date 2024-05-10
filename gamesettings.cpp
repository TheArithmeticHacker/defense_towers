#include "gamesettings.h"
#include <QDebug>
#include <QTextStream>
GameSettings::GameSettings() {
    file = new QFile("settings.txt");
    if(!file->open(QIODevice::ReadOnly)){
        qDebug("File could not open for read");
        return;
    }

    QTextStream text(file);
    int i = 0;
    while(!text.atEnd()){
        QString line = text.readLine();
        if(i == 0){
            difficulty = line.toInt();
            i++;
        }else{
            sound = line.toInt();
        }
    }
    file->close();
    delete file;
    file = new QFile("currlevel.txt");
    if(!file->open(QIODevice::ReadOnly)){
        qDebug("File could not open for read");
        return;
    }

    QTextStream temp(file);
    while(!temp.atEnd()){
        QString line = temp.readLine();
        currLevel = line.toInt();
    }
    file->close();
    delete file;
}

void GameSettings::updateLevel()
{
    currLevel++;
    file = new QFile("currLevel.txt");
    if(!file->open(QIODevice::WriteOnly)){
        qDebug("File could not open for read");
        return;
    }

    QTextStream temp(file);
    temp << QString::number(currLevel);
    file->close();
    delete file;
}
