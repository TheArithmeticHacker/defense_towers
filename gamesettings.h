#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H
#include <QFile>

class GameSettings
{
public:
    GameSettings();

    int sound;

    int difficulty;

    int currLevel;

    QFile * file;

    void updateLevel();

};

#endif // GAMESETTINGS_H
