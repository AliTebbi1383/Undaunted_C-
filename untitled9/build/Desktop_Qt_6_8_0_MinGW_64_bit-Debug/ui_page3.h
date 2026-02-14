/********************************************************************************
** Form generated from reading UI file 'page3.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE3_H
#define UI_PAGE3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_page3
{
public:
    QLineEdit *lineEdit;
    QLineEdit *Username2;
    QLineEdit *Username1;

    void setupUi(QWidget *page3)
    {
        if (page3->objectName().isEmpty())
            page3->setObjectName("page3");
        page3->resize(400, 300);
        lineEdit = new QLineEdit(page3);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(120, 60, 113, 22));
        Username2 = new QLineEdit(page3);
        Username2->setObjectName("Username2");
        Username2->setGeometry(QRect(260, 100, 113, 22));
        Username1 = new QLineEdit(page3);
        Username1->setObjectName("Username1");
        Username1->setGeometry(QRect(0, 120, 113, 22));

        retranslateUi(page3);

        QMetaObject::connectSlotsByName(page3);
    } // setupUi

    void retranslateUi(QWidget *page3)
    {
        page3->setWindowTitle(QCoreApplication::translate("page3", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page3: public Ui_page3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE3_H
