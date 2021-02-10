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
#ifndef REG_H
#define REG_H

#include <QWidget>
#include <QEventLoop>
#include <database.h>
#include <QCloseEvent>

namespace Ui {
class reg;
}

class reg : public QWidget
{
    Q_OBJECT

public:
    explicit reg(bool *RegMarker, QWidget *parent = nullptr);
    reg(bool *RegMarker, bool changePass = false, QWidget *parent = nullptr);
    ~reg();

    QEventLoop loop;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    void closeEvent(QCloseEvent *event) override;

    Ui::reg *ui;
    bool *ptrToIsRegistred;
    bool m_isChngPassRequired = false;
};

#endif // REG_H
