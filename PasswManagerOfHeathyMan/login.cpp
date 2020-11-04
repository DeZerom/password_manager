#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <reg.h>

extern dataBase *db;

login::login(bool *ptrToIsLoggedInMarker, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login),
    m_isSuccesfull(ptrToIsLoggedInMarker)
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
    reg r(&isRegistred);

    r.show();
    login::hide();
    r.loop.exec();
    login::show();

    if (isRegistred) emit registred();
}

void login::changeButtonsToRegConst()
{
    ui->pushButton_3->hide();
    ui->pushButton->setEnabled(true);
    ui->lineEdit->setEnabled(true);
}
