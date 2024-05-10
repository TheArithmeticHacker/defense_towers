QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Tower.cpp \
    TowerBullet.cpp \
    castle.cpp \
    closebutton.cpp \
    fence.cpp \
    game.cpp \
    gameover.cpp \
    gamesettings.cpp \
    healthbar.cpp \
    levelwindow.cpp \
    locations.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    settings.cpp \
    structure.cpp \
    timerwidget.cpp \
    winscreen.cpp

HEADERS += \
    Tower.h \
    TowerBullet.h \
    castle.h \
    closebutton.h \
    fence.h \
    game.h \
    gameover.h \
    gamesettings.h \
    healthbar.h \
    levelwindow.h \
    locations.h \
    mainwindow.h \
    map.h \
    settings.h \
    structure.h \
    timerwidget.h \
    winscreen.h

FORMS += \
    gameover.ui \
    levelwindow.ui \
    mainwindow.ui \
    settings.ui \
    winscreen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
