#ifndef LOCATIONS_H
#define LOCATIONS_H
#include <QFile>
class Locations
{
public:
    Locations();
    QFile* file;
    int** coordinates;
    void readData();
    void writeData();
};

#endif // LOCATIONS_H
