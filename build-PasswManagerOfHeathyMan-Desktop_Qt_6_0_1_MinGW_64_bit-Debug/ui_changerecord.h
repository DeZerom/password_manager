/********************************************************************************
** Form generated from reading UI file 'changerecord.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGERECORD_H
#define UI_CHANGERECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_changeRecord
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit_name;
    QLabel *label;
    QLineEdit *lineEdit_login;
    QLabel *label_2;
    QLineEdit *lineEdit_pass;
    QLabel *label_3;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *changeRecord)
    {
        if (changeRecord->objectName().isEmpty())
            changeRecord->setObjectName(QString::fromUtf8("changeRecord"));
        changeRecord->resize(380, 260);
        pushButton = new QPushButton(changeRecord);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 230, 80, 21));
        lineEdit_name = new QLineEdit(changeRecord);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(30, 40, 231, 21));
        label = new QLabel(changeRecord);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 121, 16));
        lineEdit_login = new QLineEdit(changeRecord);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));
        lineEdit_login->setGeometry(QRect(30, 90, 231, 21));
        label_2 = new QLabel(changeRecord);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 70, 81, 16));
        lineEdit_pass = new QLineEdit(changeRecord);
        lineEdit_pass->setObjectName(QString::fromUtf8("lineEdit_pass"));
        lineEdit_pass->setGeometry(QRect(30, 140, 231, 21));
        label_3 = new QLabel(changeRecord);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 120, 101, 16));
        textBrowser = new QTextBrowser(changeRecord);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(30, 180, 321, 41));

        retranslateUi(changeRecord);

        QMetaObject::connectSlotsByName(changeRecord);
    } // setupUi

    void retranslateUi(QWidget *changeRecord)
    {
        changeRecord->setWindowTitle(QCoreApplication::translate("changeRecord", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("changeRecord", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("changeRecord", "\320\235\320\276\320\262\320\276\320\265 \320\270\320\274\321\217 \321\200\320\265\321\201\321\203\321\200\321\201\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("changeRecord", "\320\235\320\276\320\262\321\213\320\271 \320\273\320\276\320\263\320\270\320\275", nullptr));
        label_3->setText(QCoreApplication::translate("changeRecord", "\320\235\320\276\320\262\321\213\320\271 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("changeRecord", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\225\321\201\320\273\320\270 \320\276\321\201\321\202\320\260\320\262\320\270\321\202\321\214 \320\273\321\216\320\261\320\276\320\265 \320\270\320\267 \320\277\320\276\320\273\320\265\320\271 \320\277\321\203\321\201\321\202\321\213\320\274, \321\202\320\276 \321\201\320\276\320\276\321\202\320\262\320\265\321\202\321\201\320\262\321\203\321\216\321\211\320\265\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\275\320\265 \320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\201\321\217</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changeRecord: public Ui_changeRecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGERECORD_H
