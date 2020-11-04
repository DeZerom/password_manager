#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QDebug>
#include <QCryptographicHash>
#include <cipher_test.h>

class dataBase
{
public:
    dataBase();
    bool isRegistrated();
    bool loginIntoApp(const QByteArray pswd_arr);
    void registration(const QByteArray pswd_arr);
    void addAcc(const QString name, const QString login, const QString pswd);
    QSqlDatabase getDB();
    void deleteAcc(const int index);
    QString getPassword(const QString name, const QString login, const QString salt, const QString cypherPass);

private:
    void queryConstructor(const QString type, const QString table, const QVariant args[]);

    QSqlDatabase m_db;
    QSqlQuery *m_qry;
    QString m_qryStr;
    cipher_test *m_cypher;

    struct qryConstr
    {
        const QString INSERT = "INS";
        const QString SELECT = "SEL";
        const QString USERINFO_TABLE = "userinfo";
    };
    qryConstr qryConstants;
};

#endif // DATABASE_H
