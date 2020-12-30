#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

extern dataBase *db;
extern QString masterKey;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_table = ui->tableView;
    m_model = new QSqlTableModel(nullptr, db->getDB());
    m_model->setTable("accountsData");
    m_model->select();
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_table->setModel(m_model);
    m_table->setColumnWidth(1, 153);
    m_table->setColumnWidth(2, 153);
    m_table->hideColumn(0);
    m_table->hideColumn(3);
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

    db->addAcc(name, login, pswd, masterKey);

    m_model->select();
}

void MainWindow::on_pushButton_clicked()
{
    QItemSelectionModel *selection = m_table->selectionModel();

    if (!selection->hasSelection()) {
        QMessageBox::information(this, "Удаление", "Ничего не выбрано");
    } else {
        //::selectedRows(column) returns QList thats way .count is used here
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

    QString name = index.sibling(row, 1).data().toString(),
            login = index.sibling(row, 2).data().toString(),
            cypherPass = index.sibling(row, 3).data().toString(),
            salt = index.sibling(row, 4).data().toString();

    QString pass = db->getPassword(name, login, salt, cypherPass);

    QClipboard *c = QGuiApplication::clipboard();
    c->setText(pass);
}
