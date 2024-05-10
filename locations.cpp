#include "locations.h"
#include <QDebug>
Locations::Locations() {
    file = new QFile("C:\\Users\\AUC\\Downloads\\defense_towers-main\\build-DefenseOfTowers-Desktop_Qt_6_7_0_MinGW_64_bit-Debug\\locations.txt");
    if(!file->open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug() << "could not open file for read";
        return;
    }



    coordinates = new int*[13];
    for(int i = 0; i < 13; i++)
        coordinates[i] = new int[13];
    readData();
    file->close();
}

void Locations::readData(){

    QTextStream temp(file);
    int i = 0;
    while(!temp.atEnd()){
        QString line = temp.readLine();
        QStringList row = line.split(",");
        for(int j = 0; j < 13; j++){
            coordinates[i][j] = row[j].toInt();
        }
        i++;
    }
}

void Locations::writeData(){

    if(!file->open(QIODevice::Truncate | QIODevice::ReadWrite)){
        qDebug() << "could not open file for Write";
        return;
    }


    QTextStream temp(file);
    for(int i = 0; i < 13; i++){
        QString temp1 = "";
        for(int j = 0; j < 13; j++){
            temp1 += QString::number(coordinates[i][j]);
            if(j != 12)
                temp1 += ",";
        }
        temp << temp1 << "\n";
    }

    file->close();

}

