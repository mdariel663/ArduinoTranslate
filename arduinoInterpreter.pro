QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        DHT.c \
        LiquidCrystal_I2C.cpp\
        main.cpp \
        stdArduino.cpp

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
        DHT.h \
        LiquidCrystal_I2C.h \
        stdArduino.h
