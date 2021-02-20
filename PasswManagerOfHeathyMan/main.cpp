/*
Copyright 2021, Demid Shikhov <demid2001s@gmail.com>
This file is part of PasswManagerOfHeathyMan.

PasswManagerOfHeathyMan is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

PasswManagerOfHeathyMan is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with PasswManagerOfHeathyMan.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "mainwindow.h"
#include <database.h>
#include <QApplication>
#include <login.h>

dataBase *db;
QString masterKey;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    db = new dataBase;
    bool isAuthorized = false;
    login l(&isAuthorized, &masterKey);
    l.show();
    l.loop.exec();
    if (!isAuthorized) {
        return 0;
    } else {
        MainWindow w;
        w.show();
        return a.exec();
    }
}
