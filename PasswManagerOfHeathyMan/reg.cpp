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
