TARGET = ColorSlider
TEMPLATE = app
QT += core gui widgets

CONFIG += c++11

DESTDIR = $$PWD/_bin

SOURCES += \
        ColorSlider.cpp \
        RingSlider.cpp \
        main.cpp \
        MainWindow.cpp

HEADERS += \
        ColorSlider.h \
        MainWindow.h \
        RingSlider.h

FORMS += \
        MainWindow.ui

