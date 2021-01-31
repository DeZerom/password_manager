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
#include "changerecord.h"
#include "ui_changerecord.h"

changeRecord::changeRecord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changeRecord)
{
    ui->setupUi(this);
}

changeRecord::changeRecord(const int id, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changeRecord)
{
    ui->setupUi(this);
    m_id = id;
}

void changeRecord::setId(const int id)
{
    m_id = id;
}

changeRecord::~changeRecord()
{
    qDebug()<<"ChangeRecord ui has just terminated";
    loop.exit();
    delete ui;
}

void changeRecord::closeEvent(QCloseEvent *event)
{
    loop.exit();
    event->accept();
}

void changeRecord::on_pushButton_clicked()
{
    QString name, login, pass;
    name = ui->lineEdit_name->text();
    login = ui->lineEdit_login->text();
    pass = ui->lineEdit_pass->text();

    QVector<QString> args;
    bool isName = false;
    if (name != "") {
        args.append(name);
        isName = true;
    }
    bool isLogin = false;
    if (login != "") {
        args.append(login);
        isLogin = true;
    }
    bool isPass = false;
    if (pass != "") {
        args.append(pass);
        isPass = true;
    }

    db->changeRecord(m_id, args, isName, isLogin, isPass);

    this->close();
}
