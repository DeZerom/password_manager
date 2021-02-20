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
#ifndef CHANGERECORD_H
#define CHANGERECORD_H

#include <QWidget>
#include <QDebug>
#include <QEventLoop>
#include <QCloseEvent>
#include <QLineEdit>
#include <database.h>

extern dataBase *db;

namespace Ui {
class changeRecord;
}

class changeRecord : public QWidget
{
    Q_OBJECT

public:
    explicit changeRecord(QWidget *parent = nullptr);
    changeRecord(const int id, QWidget *parent = nullptr);
    void setId(const int id);
    ~changeRecord();

    //variables
    QEventLoop loop;

private slots:
    void on_pushButton_clicked();

private:
    Ui::changeRecord *ui;
    int m_id;

    void closeEvent(QCloseEvent *event) override;
};

#endif // CHANGERECORD_H
