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
