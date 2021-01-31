/*
Copyright 2021, Demid Shikhov
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
#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QEventLoop>
#include <database.h>
#include <QCloseEvent>
#include <QKeyEvent>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(bool *ptrToIsLoggedInMarker, QString *masterKey, QWidget *parent = nullptr);
    login(QWidget *parent = nullptr);
    ~login();

    QEventLoop loop;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void changeButtonsToRegConst();

private:
    Ui::login *ui;
    bool *m_isSuccesfull;
    QString *m_masterKey;
    bool isRegistred = false;
    void closeEvent(QCloseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    //void callReg();

signals:
    void registred();

};

#endif // LOGIN_H
