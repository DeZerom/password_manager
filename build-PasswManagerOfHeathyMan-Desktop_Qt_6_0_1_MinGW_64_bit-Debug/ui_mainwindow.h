/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_name;
    QLabel *label_2;
    QLineEdit *lineEdit_login;
    QLabel *label;
    QLineEdit *lineEdit_pswd;
    QPushButton *addNewAcc_button;
    QGroupBox *groupBox_2;
    QPushButton *pushButton;
    QGroupBox *groupBox_3;
    QPushButton *changeRecord;
    QGroupBox *groupBox_4;
    QPushButton *changeRecord_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(678, 585);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(40, 20, 307, 511));
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(370, 20, 281, 191));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 261, 164));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        lineEdit_name = new QLineEdit(layoutWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        verticalLayout->addWidget(lineEdit_name);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        lineEdit_login = new QLineEdit(layoutWidget);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));

        verticalLayout->addWidget(lineEdit_login);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit_pswd = new QLineEdit(layoutWidget);
        lineEdit_pswd->setObjectName(QString::fromUtf8("lineEdit_pswd"));
        lineEdit_pswd->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEdit_pswd);

        addNewAcc_button = new QPushButton(layoutWidget);
        addNewAcc_button->setObjectName(QString::fromUtf8("addNewAcc_button"));

        verticalLayout->addWidget(addNewAcc_button);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(370, 230, 281, 51));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 20, 261, 21));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(370, 300, 281, 51));
        changeRecord = new QPushButton(groupBox_3);
        changeRecord->setObjectName(QString::fromUtf8("changeRecord"));
        changeRecord->setGeometry(QRect(10, 20, 261, 21));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(370, 370, 281, 51));
        changeRecord_2 = new QPushButton(groupBox_4);
        changeRecord_2->setObjectName(QString::fromUtf8("changeRecord_2"));
        changeRecord_2->setGeometry(QRect(10, 20, 261, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 678, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\271 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\200\320\265\321\201\321\203\321\200\321\201\320\260:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        addNewAcc_button->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\267\320\260\320\277\320\270\321\201\320\270:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\267\320\260\320\277\320\270\321\201\320\270:", nullptr));
        changeRecord->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214:", nullptr));
        changeRecord_2->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
