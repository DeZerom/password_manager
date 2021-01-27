#include "cipher_test.h"

cipher_test::cipher_test()
{}

cipher_test::cipher_test(const QString key)
{
    setKey(key);
}

QString cipher_test::encrypt(const QString text_to_encrypt)
{
    qDebug()<<"++encr function started";
    QByteArray openT = text_to_encrypt.toLocal8Bit();
    while (int(openT.length() % 16) != 0 and openT.length() != 0) {
        openT.append('a');
    }
    qDebug()<<"++open text is ready";

    QByteArray key_hash = QCryptographicHash::hash(m_key.toLocal8Bit(), QCryptographicHash::Sha1);
    QVector<QVector<char>> key_parts{4};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            key_parts[i].append(key_hash.at(i * 4 + j));
        }
    }
    qDebug()<<"++key is ready";

    //encrypting
    QVector<QVector<char>> ba{4};
    QString result = "";
    for (int i = 0; i < openT.length(); i += 16) {
        QByteArray openT_block{openT.right(openT.length() - i).left(16)};
        //making a text table
        for (int l = 0; l < 4; l++) {
            for (int x = 0; x < 4; x++) {
                ba[l].append(openT_block.at(l * 4 + x));
            }
        }
        qDebug()<<"++"<<int(i / 16 + 1)<<" text block done";
        //rounds
        for (int j = 0; j < 3; j++) {
            //round XOR
            for (int l = 0; l < 4; l++) {
                for (int x = 0; x < 4; x++) {
                    ba[l][x] = ba[l][x] ^ key_parts[l][x];
                }
            }

            //shift rows
            if (j != 2)
            ba[0].swap(ba[1]);
            ba[0].swap(ba[2]);
            ba[0].swap(ba[3]);
            //TO DO mix columns

            qDebug()<<"++"<<j<<" round's done";
        }
        //writing a block result
        for (int l = 0; l < 4; l++) {
            for (int x = 0; x < 4; x++) {
                result += ba[l][x];
            }
        }
        ba.clear();
    }

    qDebug()<<"++encr's ready. Result's: "<<result;
    return result;
}

QString cipher_test::decrypt(const QString cypher_text)
{
    //prepearing the key
    QByteArray keyHash = QCryptographicHash::hash(m_key.toLocal8Bit(), QCryptographicHash::Sha1);
    QVector<QVector<char>> keyParts{4};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            keyParts[i].append(keyHash[i * 4 + j]);
        }
    }

    QByteArray cypherT = cypher_text.toLocal8Bit();
    QString result = "";
    QVector<QVector<char>> ba{4};
    for (int i = 0; i < cypherT.length(); i += 16) {
        QByteArray cypherT_block = cypherT.right(cypherT.length() - i).left(16);
        for (int j = 0; j < 4; j++) {
            for (int l = 0; l < 4; l++) {
                ba[j].append(cypherT_block[j * 4 + l]);
            }
        }

        //rounds
        for (int j = 0; j < 3; j++) {
            //round XOR
            for (int l = 0; l < 4; l++) {
                for (int x = 0; x < 4; x++) {
                    ba[l][x] = ba[l][x] ^ keyParts[l][x];
                }
            }

            //shift rows
            ba[0].swap(ba[3]);
            ba[0].swap(ba[1]);
            ba[1].swap(ba[2]);
        }

        //writing result
        for (int j = 0; j < 4; j++) {
            for (int l = 0; l < 4; l++) {
                result += ba[j][l];
            }
        }
        ba.clear();
    }

    return result;
}

QString cipher_test::XORencr(const QString text_to_encrypt)
{
    QVector<int> key_parts;
    for (int i = 0; i < m_key.length(); i++) {
        key_parts.append(m_key[i].unicode());
    }

    QVector<int> openT;
    for (int i = 0; i < text_to_encrypt.length(); i++)
        openT.append(text_to_encrypt[i].unicode());

    QString result = "";
    int roundRes;
    for (int i = 0; i < openT.length(); i++) {
        roundRes = openT[i] ^ key_parts[0];
       for (int j = 1; j < key_parts.length(); j++) {
           roundRes ^= key_parts[j];
       }
       result += QChar(roundRes);
    }

    return result;
}

QString cipher_test::XORdecr(const QString cypher_text)
{
    QVector<int> keyParts;
    for (int i = 0; i < m_key.length(); i++)
        keyParts.append(m_key[i].unicode());

    QVector<int> cypherParts;
    for (int i = 0; i < cypher_text.length(); i++)
        cypherParts.append(cypher_text[i].unicode());

    QString result = "";
    int roundRes;
    for (int i = 0; i < cypherParts.length(); i++) {
        roundRes = cypherParts[i] ^ keyParts[keyParts.length() - 1];
        for (int j = keyParts.length() - 2; j >= 0; j--){
            roundRes ^= keyParts[j];
        }
        result += QChar(roundRes);
    }

    return result;
}

QString cipher_test::roundsEncr(const QString text)
{
    QString openT = text; //preparing text
    if (openT.length() % 4 != 0) {
        int i = 1;
        while ((openT.length() + i) % 4 != 0) i++;
        openT = QString::number(i - 1) + openT;
        while (i - 1 > 0) {
            openT += "a";
            i--;
        }
    } else {
        openT = QChar(3) + openT;
        openT += "abc";
    }

    QVector<QVector<int>> textParts{openT.length() / 4};
    for (int i = 0; i < openT.length() / 4; i++)
        for (int j = 0; j < 4; j++)
            textParts[i].append(openT[i * 4 + j].unicode());

    QString res = "";
    for (int i = 0; i < textParts.length(); i++) {
        for (int j = 0; j < 8; j++) {
            for (int l = 0; l < 4; l++){
                textParts[i][l] ^= m_roundKeys[j][l].unicode();
            }
            if (j % 2 == 0) { //mix columns
                int c = textParts[i][0];
                textParts[i][0] = textParts[i][1];
                textParts[i][1] = c;
                c = textParts[i][2];
                textParts[i][2] = textParts[i][3];
                textParts[i][3] = c;
            } else { //shift rows
                int c = textParts[i][0];
                textParts[i][0] = textParts[i][2];
                textParts[i][2] = c;
                c = textParts[i][1];
                textParts[i][1] = textParts[i][3];
                textParts[i][3] = c;
            }
        }
    }

    for (int i = 0; i < textParts.length(); i++) {
        for (int j = 0; j < 4; j++) {
            res += QChar(textParts[i][j]);
        }
    }

    return res;
}

QString cipher_test::roundsDecr(const QString cypherT)
{
    QVector<QVector<int>> textParts{cypherT.length() / 4};
    for (int i = 0; i < textParts.length(); i++) {
        for (int j = 0; j < 4; j++) {
            textParts[i].append(cypherT[i * 4 + j].unicode());
        }
    }

    for (int i = 0; i < textParts.length(); i++) {
        for (int j = 0; j < 8; j++) {
            for (int l = 0; l < 4; l++) {
                textParts[i][l] ^= m_roundKeys[j][l].unicode();
            }
            if (j % 2 == 0) { //mix columns
                int c = textParts[i][0];
                textParts[i][0] = textParts[i][1];
                textParts[i][1] = c;
                c = textParts[i][2];
                textParts[i][2] = textParts[i][3];
                textParts[i][3] = c;
            } else { //shift rows
                int c = textParts[i][0];
                textParts[i][0] = textParts[i][2];
                textParts[i][2] = c;
                c = textParts[i][1];
                textParts[i][1] = textParts[i][3];
                textParts[i][3] = c;
            }
        }
    }

    QString res;
    for (int i = 0; i < textParts.length(); i++) {
        for (int j = 0; j < 4; j++) {
            res += QChar(textParts[i][j]);
        }
    }

    int leftSymbols = res[0].unicode();
    res = res.right(res.length() - 1);
    qDebug()<<leftSymbols;
    if (leftSymbols <= 4) res = res.left(res.length() - leftSymbols);

    qDebug()<<res;
    return res;
}

void cipher_test::expandKey()
{
    QString keyHash = QString(QCryptographicHash::hash(m_key.toUtf8(), QCryptographicHash::Sha384));

    for (int i = 0; i < 8; i++) {
        m_roundKeys[i] = keyHash.right(keyHash.length() - (i * 4) - 1).left(4);
    }
}

void cipher_test::setKey(const QString key)
{
    if (key != m_key) {
        m_key = key;
        expandKey();
    }
}

QString cipher_test::generateSalt()
{
    QRandomGenerator64 rGen;
    rGen.seed(QDateTime::currentMSecsSinceEpoch());

    quint64 number = rGen.generate64();

    QString res = "";
    while (number > 0) {
        int currPart = number % 1000;
        res += QChar(currPart);
        number /= 1000;
    }

    return res;
}
