/********************************************************************************
** Form generated from reading UI file 'page3.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE3_H
#define UI_PAGE3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_page3
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *page3)
    {
        if (page3->objectName().isEmpty())
            page3->setObjectName("page3");
        page3->resize(400, 300);
        pushButton = new QPushButton(page3);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 90, 93, 29));

        retranslateUi(page3);

        QMetaObject::connectSlotsByName(page3);
    } // setupUi

    void retranslateUi(QDialog *page3)
    {
        page3->setWindowTitle(QCoreApplication::translate("page3", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("page3", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page3: public Ui_page3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE3_H
