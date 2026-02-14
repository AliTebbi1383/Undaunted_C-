/********************************************************************************
** Form generated from reading UI file 'mapdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPDIALOG_H
#define UI_MAPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_MapDialog
{
public:

    void setupUi(QDialog *MapDialog)
    {
        if (MapDialog->objectName().isEmpty())
            MapDialog->setObjectName("MapDialog");
        MapDialog->resize(400, 300);

        retranslateUi(MapDialog);

        QMetaObject::connectSlotsByName(MapDialog);
    } // setupUi

    void retranslateUi(QDialog *MapDialog)
    {
        MapDialog->setWindowTitle(QCoreApplication::translate("MapDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MapDialog: public Ui_MapDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPDIALOG_H
