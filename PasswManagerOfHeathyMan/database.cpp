#include "database.h"
#include <QCoreApplication>

dataBase::dataBase():
    m_cypher(new cipher_test)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = QCoreApplication::applicationDirPath();
    path += "db";

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
        pswd_hash_fromDb = m_qry->value(rec.indexOf("pass")).toString();
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
    m_qry->prepare("INSERT INTO userinfo(pass)"
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

void dataBase::addAcc(const QString name, const QString login, const QString pswd, const QString key)
{
    m_qry->prepare("INSERT INTO accountsData(name, login, pass, salt)"
                   "VALUES(:name, :login, :pass, :salt);");

    QString salt = m_cypher->generateSalt();

    m_cypher->setKey(QCryptographicHash::hash((key + salt).toUtf8(), QCryptographicHash::Sha256));
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

QString dataBase::getPassword(const QString masterkey, const QString salt, const QString cypherPass)
{
   QString key = QCryptographicHash::hash((masterkey + salt).toUtf8(), QCryptographicHash::Sha256);
   m_cypher->setKey(key);

   QString password = m_cypher->roundsDecr(cypherPass);


   return password;
}

void dataBase::changeRecordName(const int id, const QString newName)
{

}

void dataBase::changeRecordLogin(const int id, const QString newLoging)
{

}

void dataBase::changeRecordPass(const int id, const QString newPass)
{

}

void dataBase::changeRecord(const int id, const QString args[], const bool isName, const bool isLogin, const bool isPass)
{
    //id - id of record
    //args[] - new values
    //bool params define if it must change corresponding field

    if (isName) changeRecordName(id, args[0]);
    if (isLogin) changeRecordLogin(id, args[1]);
    if (isPass) changeRecordPass(id, args[2]);
}

