/********************************************************************************
** Form generated from reading UI file 'page2.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE2_H
#define UI_PAGE2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_page2
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *Username1;
    QLineEdit *Username2;
    QPushButton *check;

    void setupUi(QDialog *page2)
    {
        if (page2->objectName().isEmpty())
            page2->setObjectName("page2");
        page2->resize(688, 604);
        label = new QLabel(page2);
        label->setObjectName("label");
        label->setGeometry(QRect(12, 100, 81, 20));
        label->setStyleSheet(QString::fromUtf8("color: rgb(27, 27, 27);"));
        label_2 = new QLabel(page2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(280, 100, 81, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(22, 22, 22);"));
        Username1 = new QLineEdit(page2);
        Username1->setObjectName("Username1");
        Username1->setGeometry(QRect(130, 100, 113, 26));
        Username1->setStyleSheet(QString::fromUtf8("\n"
"    background-color: white;\n"
"    border: 3px solid brown;\n"
"    border-radius: 45px;\n"
"\n"
""));
        Username2 = new QLineEdit(page2);
        Username2->setObjectName("Username2");
        Username2->setGeometry(QRect(390, 100, 113, 26));
        Username2->setStyleSheet(QString::fromUtf8("\n"
"    background-color: white;\n"
"    border: 3px solid brown;\n"
"    border-radius: 45px;\n"
"\n"
""));
        check = new QPushButton(page2);
        check->setObjectName("check");
        check->setGeometry(QRect(240, 170, 93, 29));
        check->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);"));

        retranslateUi(page2);

        QMetaObject::connectSlotsByName(page2);
    } // setupUi

    void retranslateUi(QDialog *page2)
    {
        page2->setWindowTitle(QCoreApplication::translate("page2", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("page2", "Username1", nullptr));
        label_2->setText(QCoreApplication::translate("page2", "Username2", nullptr));
        check->setText(QCoreApplication::translate("page2", "check", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page2: public Ui_page2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE2_H
