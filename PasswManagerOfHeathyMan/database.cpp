/*
Copyright 2021, Demid Shikhov
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
#include "database.h"
#include <QCoreApplication>

dataBase::dataBase():
    m_cypher(new cipher_test)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = QCoreApplication::applicationDirPath();
    path += "/db";

    if (!QDir(path).exists()) QDir().mkdir(path);
    m_db.setDatabaseName(path + "/db.db");

    /*if (m_db.password() == "") {
        m_db.setUserName("e9iY5i7cRYF9BG02");
        m_db.setPassword("EgEY4CDR5p41n23U");
        if (m_db.password() == "") qDebug()<<"--PSWD IS NOT SETTED TO DB";
        else qDebug()<<"++PSWD SETTED TO DB";
    }*/

    if (!m_db.open()) {
        qDebug()<<"--DB OPENING ERROR: "<<m_db.lastError().text();
    } else {
        qDebug()<<"++CONNECTED TO DB";
    }

    m_qry = new QSqlQuery(m_db);

    m_qryStr = "CREATE TABLE IF NOT EXISTS userinfo("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                  "pswd VARCHAR"
                  ");";
    if (!m_qry->exec(m_qryStr)) {
        qDebug()<<"--CREATING userinfo TABLE ERROR: "<<m_qry->lastError().text();
    } else {
        qDebug()<<"++userinfo has just created or is already existing";
    }

    m_qry->prepare("create table if not exists accountsData("
                   "id integer primary key autoincrement,"
                   "name varchar not null,"
                   "login varchar not null,"
                   "pass varchar not null,"
                   "salt varchar not null"
                   ");");
    if (!m_qry->exec()) {
        qDebug()<<"--CREATING accountsData TABLE ERROR: "<<m_qry->lastError().text();
    } else {
        qDebug()<<"++accountsData has just created or is already existing";
    }
}

bool dataBase::isRegistrated()
{
    if (!m_qry->exec("SELECT * FROM userinfo;")) {
       qDebug()<<"--CAN'T GET PSWD HASH FROM DB (isRegistred):"<<m_qry->lastError();
    } else {
        m_qry->first();
        return m_qry->isValid();
    }

    return false;
}

bool dataBase::loginIntoApp(const QByteArray pswd_arr)
{
    QString pswd_hash = QString(QCryptographicHash::hash(pswd_arr, QCryptographicHash::Sha256));
    QString pswd_hash_fromDb;
    m_qry->prepare("SELECT * FROM userinfo;");
    if(!m_qry->exec()) {
        qDebug()<<"--CAN'T GET PSWD HASH FROM DB (loginIntoApp)";
        return false;
    } else {
        m_qry->first();
        QSqlRecord rec = m_qry->record();
        pswd_hash_fromDb = m_qry->value(rec.indexOf("pswd")).toString();
    }

    if (pswd_hash == pswd_hash_fromDb) {
        return true;
    } else {
        return false;
    }
}

void dataBase::registration(const QByteArray pswd_arr)
{
    QString pswd_hash = QString(QCryptographicHash::hash(pswd_arr, QCryptographicHash::Sha256));
    m_qry->prepare("INSERT INTO userinfo(pswd)"
                  "VALUES(:pswd);");
    m_qry->bindValue(":pswd", pswd_hash);

    if (!m_qry->exec()) {
        qDebug()<<"--CAN'T INSERT PSWD HASH INTO DB (registration): "<<m_qry->lastError().text();
    } else {
        qDebug()<<"++PSWD'S JUST INSERTED INTO DB";
    }
}

QSqlDatabase dataBase::getDB()
{
    return m_db;
}

void dataBase::addAcc(const QString name, const QString login, const QString pswd)
{
    m_qry->prepare("INSERT INTO accountsData(name, login, pass, salt)"
                   "VALUES(:name, :login, :pass, :salt);");

    QString salt = m_cypher->generateSalt();

    m_cypher->setKey(QCryptographicHash::hash((masterKey + salt).toUtf8(), QCryptographicHash::Sha256));
    QString pass = m_cypher->roundsEncr(pswd);

    m_qry->bindValue(":name", name);
    m_qry->bindValue(":login", login);
    m_qry->bindValue(":pass", pass);
    m_qry->bindValue(":salt", salt);

    if (!m_qry->exec()) {
        qDebug()<<"--ADDING A NEW ACC ERROR: "<<m_qry->lastError().text();
    } else {
        qDebug()<<"++A NEW ACC HAS JUST ADDED";
    }
}

void dataBase::deleteAcc(const int index)
{
    m_qry->prepare("DELETE FROM accountsData WHERE id = :id;");
    m_qry->bindValue(":id", index);

    if (!m_qry->exec()) {
        qDebug()<<"--DELETING ACC TROUBLES"<<m_qry->lastError().text()<<" "<<index + 1<<" "<<m_qryStr;
    } else {
        qDebug()<<"++ACC IS DELETED";
    }
}

QString dataBase::getPassword(const QString salt, const QString cypherPass)
{
   QString key = QCryptographicHash::hash((masterKey + salt).toUtf8(), QCryptographicHash::Sha256);
   m_cypher->setKey(key);

   QString password = m_cypher->roundsDecr(cypherPass);

   return password;
}

void dataBase::changeRecordName(const int id, const QString newName)
{
    m_qry->prepare(QString("UPDATE accountsData SET name = :newName WHERE id = :id;"));
    m_qry->bindValue(":newName", newName);
    m_qry->bindValue(":id", QString::number(id));
    //qDebug()<<m_qry->boundValue(":newName");
    //qDebug()<<m_qry->boundValue(":id");

    if (!m_qry->exec()) qDebug()<<"--CAN'T CHANGE RECORD'S NAME"<<m_qry->lastError().text();
}

void dataBase::changeRecordLogin(const int id, const QString newLoging)
{
    m_qry->prepare("UPDATE accountsData SET login = :newLogin WHERE id = :id;");
    m_qry->bindValue(":newLogin", newLoging);
    m_qry->bindValue(":id", id);

    if (!m_qry->exec()) qDebug()<<"--CAN'T CHANGE RECORD'S LOGIN"<<m_qry->lastError().text();
}

void dataBase::changeRecordPass(const int id, const QString newPass)
{
    //prepearing password
    QString salt = m_cypher->generateSalt();
    QString pass = preparePass(newPass, salt);
    //writing in dataBase
    m_qry->prepare("UPDATE accountsData SET pass = :newPass, salt = :newSalt WHERE id = :id;");
    m_qry->bindValue(":newPass", pass);
    m_qry->bindValue(":newSalt", salt);
    m_qry->bindValue(":id", id);

    if (!m_qry->exec()) qDebug()<<"--CAN'T CHANGE RECORD'S PASS"<<m_qry->lastError().text();
}

QString dataBase::preparePass(const QString pass, const QString salt)
{
    m_cypher->setKey(QCryptographicHash::hash((masterKey + salt).toUtf8(), QCryptographicHash::Sha256));
    QString res = m_cypher->roundsEncr(pass);

    return res;
}

void dataBase::changeRecord(const int id, const QVector<QString> args, const bool isName, const bool isLogin, const bool isPass)
{
    //this fun is changing record's values
    //it is neccesarry to write args in this order: name, login, pass
    //but if some args don't сhanged, you shouldn't write them
    //id - id of record
    //args[] - new values
    //bool params define if it is neccecarry change corresponding field
    int numOfArgs = 0;
    if (isName) {
        numOfArgs++;
        changeRecordName(id, args[numOfArgs - 1]);
    }
    if (isLogin) {
        numOfArgs++;
        changeRecordLogin(id, args[numOfArgs - 1]);
    }
    if (isPass) {
        numOfArgs++;
        changeRecordPass(id, args[numOfArgs - 1]);
    }
}

void dataBase::changeUsersPass(const QString newPass)
{

}

