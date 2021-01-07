#ifndef CHANGERECORD_H
#define CHANGERECORD_H

#include <QWidget>
#include <QDebug>
#include <QEventLoop>
#include <QCloseEvent>

namespace Ui {
class changeRecord;
}

class changeRecord : public QWidget
{
    Q_OBJECT

public:
    explicit changeRecord(QWidget *parent = nullptr);
    ~changeRecord();

    //variables
    QEventLoop loop;

private:
    Ui::changeRecord *ui;
    void closeEvent(QCloseEvent *event) override;
};

#endif // CHANGERECORD_H
