#-------------------------------------------------
#
# Project created by QtCreator 2013-10-02T07:24:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ControlPanel
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    hps.cpp \
    ADLX345.cpp \
    mpu6050.cpp \
    tab_gsensor.cpp \
    fpga.cpp \
    tab_button.cpp

HEADERS  += dialog.h \
    hps.h \
    ADLX345.h \
    fpga.h \
    mpu6050.h

FORMS    += dialog.ui
INCLUDEPATH += /home/syb2002/intelFPGA/20.1/embedded/ip/altera/hps/altera_hps/hwlib/include
INCLUDEPATH += /home/syb2002/intelFPGA/20.1/embedded/ip/altera/hps/altera_hps/hwlib/include/soc_cv_av
DEPENDPATH += /home/syb2002/intelFPGA/20.1/embedded/ip/altera/hps/altera_hps/hwlib/include
#QMAKE_CXXFLAGS += -std=gnu++11
QMAKE_CXXFLAGS += -std=c++11 -Dsoc_cv_av

RESOURCES += \
    images/images.qrc
