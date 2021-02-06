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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlTableModel>
#include <QTableView>
#include <database.h>
#include <QItemSelectionModel>
#include <cipher_test.h>
#include <QClipboard>
#include <changerecord.h>
#include <login.h>
#include <reg.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addNewAcc_button_clicked();

    void on_pushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_changeRecord_clicked();

    void on_changeRecord_2_clicked();

private:
    Ui::MainWindow *ui;
    QTableView *m_table;
    QSqlTableModel *m_model;

};
#endif // MAINWINDOW_H
