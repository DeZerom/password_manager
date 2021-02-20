/*
Copyright 2021, Demid Shikhov <demid2001s@gmail.com>
This file is part of PasswManagerOfHeathyMan.

PasswManagerOfHeathyMan is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

PasswManagerOfHeathyMan is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with PasswManagerOfHeathyMan.  If not, see <https://www.gnu.org/licenses/>.
*/
#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QDebug>
#include <QCryptographicHash>
#include <cipher_test.h>

extern QString masterKey;

class dataBase
{
public:
    dataBase();
    bool isRegistrated();
    bool loginIntoApp(const QByteArray pswd_arr);
    void registration(const QByteArray pswd_arr);
    void addAcc(const QString name, const QString login, const QString pswd);
    void deleteAcc(const int index);
    void changeRecord(const int id, const QVector<QString> args, const bool isName = false, const bool isLogin = false, const bool isPass = false);
    void changeUsersPass(const QString newPass); //changes masterKey variable
    void recypherWithNewMasterKey(const int id, const QString oldMS, const QString cypherPass, const QString salt);
    QSqlDatabase getDB();
    QString getPassword(const QString salt, const QString cypherPass, QString ms = masterKey);
    QString getUsersPassHash(); //don't needeed

private:
    void queryConstructor(const QString type, const QString table, const QVariant args[]);
    void changeRecordName(const int id, const QString newName);
    void changeRecordLogin(const int id, const QString newLoging);
    void changeRecordPass(const int id, const QString newPass);
    QString preparePass(const QString pass, const QString salt);

    QSqlDatabase m_db;
    QSqlQuery *m_qry;
    QString m_qryStr;
    cipher_test *m_cypher;

    /*struct qryConstr
    {
        const QString INSERT = "INS";
        const QString SELECT = "SEL";
        const QString USERINFO_TABLE = "userinfo";
    };
    qryConstr qryConstants;*/
};

#endif // DATABASE_H
