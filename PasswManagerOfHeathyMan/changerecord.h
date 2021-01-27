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
