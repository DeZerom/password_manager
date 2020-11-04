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
    ~reg();

    QEventLoop loop;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    void closeEvent(QCloseEvent *event) override;

    Ui::reg *ui;
    bool *ptrToIsRegistred;
};

#endif // REG_H
