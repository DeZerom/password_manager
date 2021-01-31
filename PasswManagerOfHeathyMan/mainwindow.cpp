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
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

extern dataBase *db;
extern QString masterKey; //encrypted already

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_table = ui->tableView;
    m_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_model = new QSqlTableModel(nullptr, db->getDB());
    m_model->setTable("accountsData");
    m_model->select();
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_table->setModel(m_model);
    m_table->setColumnWidth(1, 153);
    m_table->setColumnWidth(2, 153);
    m_table->hideColumn(0);
    m_table->hideColumn(3);
    m_table->hideColumn(4);
    m_table->show();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addNewAcc_button_clicked()
{
    QString name = ui->lineEdit_name->text(),
            login = ui->lineEdit_login->text(),
            pswd = ui->lineEdit_pswd->text();

    if (name == "") {
        QMessageBox::information(this, "Добавление новой записи", "Название ресурса не должно быть пустым");
        return;
    } else if (login == "") {
        QMessageBox::information(this, "Добавление новой записи", "Логин не должен быть пустым");
        return;
    } else if (pswd == "") {
        QMessageBox::information(this, "Добавление новой записи", "Пароль не должен быть пустым");
    }

    db->addAcc(name, login, pswd);

    ui->lineEdit_name->setText("");
    ui->lineEdit_login->setText("");
    ui->lineEdit_pswd->setText("");

    m_model->select();
}

void MainWindow::on_pushButton_clicked()
{
    QItemSelectionModel *selection = m_table->selectionModel();

    if (!selection->hasSelection()) {
        QMessageBox::information(this, "Удаление", "Ничего не выбрано");
    } else {
        //::selectedRows(column) returns QList thats why .count is used here
        //we delete all of selected rows
        for (int i = 0; i < selection->selectedRows(0).count(); i++) {
            QModelIndex selectedItem = selection->selectedRows().at(i);
            db->deleteAcc(selectedItem.data().toInt());
        }
        m_model->select();
    }
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    int row = index.row();

    QString cypherPass = index.sibling(row, 3).data().toString(),
            salt = index.sibling(row, 4).data().toString();

    QString pass = db->getPassword(salt, cypherPass);

    QClipboard *c = QGuiApplication::clipboard();
    c->setText(pass);
}

void MainWindow::on_changeRecord_clicked()
{
    QItemSelectionModel *selection = m_table->selectionModel();
    int id;
    if (!selection->hasSelection()) {
        QMessageBox::information(this, "Изменение записи", "Ничего не выбрано");
        return;
    } else if (selection->selectedRows().count() > 1) {
        QMessageBox::information(this, "Изменение записи", "Невозможно изменить несколько записей одновременно");
        return;
    } else {
        QModelIndexList selectedCells = selection->selectedIndexes();
        id = selectedCells[0].siblingAtColumn(0).data().toInt();
    }

    changeRecord cr(id);
    cr.show();
    cr.loop.exec();

    m_model->select();
}
