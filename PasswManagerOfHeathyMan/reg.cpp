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
#include "reg.h"
#include "ui_reg.h"
#include <QMessageBox>

extern dataBase *db;

reg::reg(bool *RegMarker, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reg),
    ptrToIsRegistred(RegMarker)
{
    ui->setupUi(this);
}

reg::~reg()
{
    delete ui;
}

void reg::on_pushButton_clicked()
{
    QString pswd1 = ui->lineEdit->text();
    QString pswd2 = ui->lineEdit_2->text();

    if (pswd1 == pswd2) {
        db->registration(pswd1.toUtf8());
        *ptrToIsRegistred = true;
        reg::close();
    } else {
        QMessageBox::information(this, "Регистрация", "Пароли не совпадают");
    }
}

void reg::on_pushButton_2_clicked()
{
    *ptrToIsRegistred = false;
    reg::close();
}

void reg::closeEvent(QCloseEvent *event)
{
    loop.exit();
    event->accept();
}
