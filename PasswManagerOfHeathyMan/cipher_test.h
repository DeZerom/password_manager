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
