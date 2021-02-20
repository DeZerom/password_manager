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
#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <reg.h>
#include <QCryptographicHash>

extern dataBase *db;

login::login(bool *ptrToIsLoggedInMarker, QString *ptrToMasterKey, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login),
    m_isSuccesfull(ptrToIsLoggedInMarker),
    m_isMasterKeyGiven(true),
    m_masterKey(ptrToMasterKey)
{
    ui->setupUi(this);
    ui->pushButton_3->hide(); //reg button

    QObject::connect(this, &login::registred, this, &login::changeButtonsToRegConst);

    if (!db->isRegistrated()) {
        ui->pushButton_3->show();
        ui->pushButton->setEnabled(false);
        ui->lineEdit->setEnabled(false);
    }
}

login::login(bool *ptrToIsLoggedInMarker, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login),
    m_isSuccesfull(ptrToIsLoggedInMarker),
    m_isMasterKeyGiven(false)
{
    ui->setupUi(this);
    ui->pushButton_3->hide(); //reg button

    QObject::connect(this, &login::registred, this, &login::changeButtonsToRegConst);

    if (!db->isRegistrated()) {
        ui->pushButton_3->show();
        ui->pushButton->setEnabled(false);
        ui->lineEdit->setEnabled(false);
    }
}

login::~login()
{
    loop.exit();
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString pswd = ui->lineEdit->text();

    if (pswd == "") {
        QMessageBox::information(this, "Авторизация", "Введите пароль");
    } else {
        if (db->loginIntoApp(pswd.toUtf8())) {
            *m_isSuccesfull = true;
            if (m_isMasterKeyGiven)
                *m_masterKey = QCryptographicHash::hash(QCryptographicHash::hash(pswd.toUtf8(), QCryptographicHash::Sha3_224), QCryptographicHash::Sha3_256);
            loop.exit();
            login::close();
        } else {
            QMessageBox::information(this, "Авторизация", "Пароль не верный");
        }
    }
}

void login::on_pushButton_2_clicked()
{
    *m_isSuccesfull = false;
    loop.exit();
    login::close();
}

void login::closeEvent(QCloseEvent *event)
{
    loop.exit();
    event->accept();
}

void login::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    if (key == Qt::Key_Enter) {
        ui->pushButton->click();
    }
}

void login::on_pushButton_3_clicked()
{
    reg r(&m_isRegistred);

    r.show();
    login::hide();
    r.loop.exec();
    login::show();

    if (m_isRegistred) emit registred();
}

void login::changeButtonsToRegConst()
{
    ui->pushButton_3->hide();
    ui->pushButton->setEnabled(true);
    ui->lineEdit->setEnabled(true);
}
