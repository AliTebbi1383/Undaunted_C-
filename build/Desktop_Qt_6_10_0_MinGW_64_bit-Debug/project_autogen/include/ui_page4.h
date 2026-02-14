/********************************************************************************
** Form generated from reading UI file 'page4.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE4_H
#define UI_PAGE4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_page4
{
public:
    QLineEdit *lineEdit;
    QLineEdit *Username1;
    QLineEdit *Username2;

    void setupUi(QDialog *page4)
    {
        if (page4->objectName().isEmpty())
            page4->setObjectName("page4");
        page4->resize(896, 634);
        lineEdit = new QLineEdit(page4);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(330, 20, 113, 26));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 3px solid black;\n"
"border-radius: 45px;\n"
""));
        Username1 = new QLineEdit(page4);
        Username1->setObjectName("Username1");
        Username1->setGeometry(QRect(40, 70, 113, 26));
        Username1->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 3px solid green;\n"
"border-radius: 45px;\n"
"color: green;"));
        Username2 = new QLineEdit(page4);
        Username2->setObjectName("Username2");
        Username2->setGeometry(QRect(630, 70, 113, 26));
        Username2->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 3px solid #9370DB;\n"
"border-radius: 45px;\n"
"color: #9370DB;"));

        retranslateUi(page4);

        QMetaObject::connectSlotsByName(page4);
    } // setupUi

    void retranslateUi(QDialog *page4)
    {
        page4->setWindowTitle(QCoreApplication::translate("page4", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page4: public Ui_page4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE4_H
