/********************************************************************************
** Form generated from reading UI file 'changerecord.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGERECORD_H
#define UI_CHANGERECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_changeRecord
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *changeRecord)
    {
        if (changeRecord->objectName().isEmpty())
            changeRecord->setObjectName(QString::fromUtf8("changeRecord"));
        changeRecord->resize(400, 300);
        pushButton = new QPushButton(changeRecord);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 250, 80, 21));

        retranslateUi(changeRecord);

        QMetaObject::connectSlotsByName(changeRecord);
    } // setupUi

    void retranslateUi(QWidget *changeRecord)
    {
        changeRecord->setWindowTitle(QCoreApplication::translate("changeRecord", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("changeRecord", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changeRecord: public Ui_changeRecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGERECORD_H
