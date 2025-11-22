#include "page4.h"
#include "ui_page4.h"
#include <QMessageBox>

page4::page4(const QString &mapName, const QString &username1, const QString &username2, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::page4)
    , m_mapName(mapName)
    , m_username1(username1)
    , m_username2(username2)
{
    ui->setupUi(this);

    // اگر UI داخلی page4 فیلدهایی برای نمایش دارید، آنها را مقداردهی کنید:
    // e.g., ui->mapLabel->setText(m_mapName);
    //       ui->user1Label->setText(m_username1);
    //       ui->user2Label->setText(m_username2);
}

page4::~page4()
{
    delete ui;
}
