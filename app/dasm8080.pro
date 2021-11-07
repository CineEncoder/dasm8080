QT += core
QT += gui
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = dasm8080
TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    exportwindow.cpp \
    importwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    messagewindow.cpp

HEADERS += \
    exportwindow.h \
    importwindow.h \
    mainwindow.h \
    messagewindow.h

FORMS += \
    exportwindow.ui \
    importwindow.ui \
    mainwindow.ui \
    messagewindow.ui

RESOURCES += \
    files.qrc

win32 {
    RC_FILE = icon.rc
}

# Default rules for deployment.
qnx: target.path = /tmp/bin
else: unix:!android {
    target.path = /usr/bin
}
!isEmpty(target.path): INSTALLS += target
