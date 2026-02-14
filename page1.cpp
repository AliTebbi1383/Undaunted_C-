#include "page1.h"
#include "./ui_page1.h"
#include "page2.h"

page1::page1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::page1)
{
    ui->setupUi(this);
  this->setStyleSheet("background-color: white; color: black;");
}
page1::~page1()
{
    delete ui;
}

void page1::on_groupBox_clicked()
{

}


void page1::on_pushButton_clicked()
{
    page2 *w2 =new page2;
    w2->show();
    this->hide();
}

