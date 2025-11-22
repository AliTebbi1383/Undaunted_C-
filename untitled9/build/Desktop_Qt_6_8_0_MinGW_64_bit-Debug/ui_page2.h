/********************************************************************************
** Form generated from reading UI file 'page2.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE2_H
#define UI_PAGE2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_page2
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *Username1;
    QLineEdit *Username2;
    QPushButton *pushButton;

    void setupUi(QWidget *page2)
    {
        if (page2->objectName().isEmpty())
            page2->setObjectName("page2");
        page2->resize(400, 300);
        label = new QLabel(page2);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 50, 91, 16));
        label_2 = new QLabel(page2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 110, 101, 16));
        Username1 = new QLineEdit(page2);
        Username1->setObjectName("Username1");
        Username1->setGeometry(QRect(140, 50, 113, 22));
        Username2 = new QLineEdit(page2);
        Username2->setObjectName("Username2");
        Username2->setGeometry(QRect(140, 100, 113, 22));
        pushButton = new QPushButton(page2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 170, 75, 24));

        retranslateUi(page2);

        QMetaObject::connectSlotsByName(page2);
    } // setupUi

    void retranslateUi(QWidget *page2)
    {
        page2->setWindowTitle(QCoreApplication::translate("page2", "Form", nullptr));
        label->setText(QCoreApplication::translate("page2", "Username1", nullptr));
        label_2->setText(QCoreApplication::translate("page2", "Username2", nullptr));
        pushButton->setText(QCoreApplication::translate("page2", "check", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page2: public Ui_page2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE2_H
