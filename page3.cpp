#include "page3.h"
#include "ui_page3.h"
#include <QDialog>
#include <QListWidget>
#include <QVBoxLayout>
#include <QMessageBox>
#include "page4.h"

page3::page3(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::page3)
{
    ui->setupUi(this);
}

page3::~page3()
{
    delete ui;
}

void page3::on_pushButton_clicked()
{
    // ساخت دیالوگ مودال برای انتخاب نقشه
    QDialog modalDialog(this);
    modalDialog.setWindowTitle("Select a Map");
    modalDialog.setModal(true);
    modalDialog.resize(300, 200);

    // ساخت لیست برای نمایش نقشه‌ها
    QListWidget *list = new QListWidget(&modalDialog);
    list->addItem("Map 1 ");
    list->addItem("Map 2 ");
    list->addItem("Map 3 ");
    list->addItem("Map 4 ");
    list->addItem("Map 5 ");
    // قرار دادن لیست داخل layout
    QVBoxLayout *layout = new QVBoxLayout(&modalDialog);
    layout->addWidget(list);

    // اتصال سیگنال انتخاب
    connect(list, &QListWidget::itemDoubleClicked, [&](QListWidgetItem *item){
        QString chosenMap = item->text();

        // ورود به page4 و نمایش نام نقشه در lineEdit
        page4 *game = new page4(chosenMap, this);
        game->show();   // نمایش غیرمودال
        // اگر بخواهی مودال باشد:
        // game->exec();
this->hide();
        modalDialog.accept();  // بستن مودال
    });

    // نمایش مودال
    modalDialog.exec();
}
