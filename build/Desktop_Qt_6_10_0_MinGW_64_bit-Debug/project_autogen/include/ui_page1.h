/********************************************************************************
** Form generated from reading UI file 'page1.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE1_H
#define UI_PAGE1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_page1
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *page1)
    {
        if (page1->objectName().isEmpty())
            page1->setObjectName("page1");
        page1->resize(800, 600);
        centralwidget = new QWidget(page1);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 0, 601, 571));
        groupBox->setStyleSheet(QString::fromUtf8("background-image: url(:/new/start_img/start.jpg);"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(230, 450, 93, 29));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 255, 69);\n"
"alternate-background-color: rgb(216, 224, 255);"));
        page1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(page1);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        page1->setMenuBar(menubar);
        statusbar = new QStatusBar(page1);
        statusbar->setObjectName("statusbar");
        page1->setStatusBar(statusbar);

        retranslateUi(page1);

        QMetaObject::connectSlotsByName(page1);
    } // setupUi

    void retranslateUi(QMainWindow *page1)
    {
        page1->setWindowTitle(QCoreApplication::translate("page1", "page1", nullptr));
        groupBox->setTitle(QString());
        pushButton->setText(QCoreApplication::translate("page1", "play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page1: public Ui_page1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE1_H
