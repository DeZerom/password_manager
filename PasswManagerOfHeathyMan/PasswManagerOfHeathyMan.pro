#Copyright 2021, Demid Shikhov
#This file is part of PasswManagerOfHeathyMan.
#
#PasswManagerOfHeathyMan is free software: you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation, either version 3 of the License, or
#any later version.
#
#PasswManagerOfHeathyMan is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.
#
#You should have received a copy of the GNU General Public License
#along with PasswManagerOfHeathyMan.  If not, see <https://www.gnu.org/licenses/>.
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    changerecord.cpp \
    cipher_test.cpp \
    database.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    reg.cpp

HEADERS += \
    changerecord.h \
    cipher_test.h \
    database.h \
    login.h \
    mainwindow.h \
    reg.h

FORMS += \
    changerecord.ui \
    login.ui \
    mainwindow.ui \
    reg.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
