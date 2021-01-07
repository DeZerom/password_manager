#include "changerecord.h"
#include "ui_changerecord.h"

changeRecord::changeRecord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changeRecord)
{
    ui->setupUi(this);
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
