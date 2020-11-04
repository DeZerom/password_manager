#ifndef CIPHER_TEST_H
#define CIPHER_TEST_H

#include <QString>
#include <QCryptographicHash>
#include <QDebug>
#include <QMessageBox>
#include <QRandomGenerator64>
#include <QDateTime>

class cipher_test
{
public:
    cipher_test();
    cipher_test(const QString key);
    void setKey(const QString key);
    QString encrypt(const QString text_to_encrypt);
    QString decrypt(const QString cypher_text);
    QString XORencr(const QString text_to_encrypt);
    QString XORdecr(const QString cypher_text);
    QString roundsEncr(const QString text);
    QString roundsDecr(const QString cypherT);
    QString generateSalt();

private:
    void expandKey();

    QVector<QString> m_roundKeys{8};
    QString m_key = "";
};

#endif // CIPHER_TEST_H
