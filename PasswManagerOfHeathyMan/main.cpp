#include "mainwindow.h"
#include <database.h>
#include <QApplication>
#include <login.h>

dataBase *db;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    db = new dataBase;
    bool isAuthorized = false;
    login l(&isAuthorized);
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
