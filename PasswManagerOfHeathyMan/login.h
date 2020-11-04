#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QEventLoop>
#include <database.h>
#include <QCloseEvent>
#include <QKeyEvent>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(bool *ptrToIsLoggedInMarker, QWidget *parent = nullptr);
    login(QWidget *parent = nullptr);
    ~login();

    QEventLoop loop;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void changeButtonsToRegConst();

private:
    Ui::login *ui;
    bool *m_isSuccesfull;
    bool isRegistred = false;
    void closeEvent(QCloseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    //void callReg();

signals:
    void registred();

};

#endif // LOGIN_H
