#include "page4.h"
#include "ui_page4.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QLineEdit>
#include <QRegularExpression>
#include <QDebug>

page4::page4(const QString &mapName,
             const QString &user1,
             const QString &user2,
             const QString &filePath,
             QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::page4)
{
    ui->setupUi(this);

    this->setStyleSheet(
        "QLineEdit {"
        " border: 5px solid green;"
        " border-radius: 22px;"
        " padding: 5px;"
        " color: black;"
        " background-color: #f9f9f9;"
        "}"
        "QDialog { background-color: white; color: black; }"
        );

    ui->lineEdit->setText(mapName);
    ui->Username1->setText(user1);
    ui->Username2->setText(user2);

    ui->Username1->setEnabled(false);
    ui->Username2->setEnabled(false);
    ui->lineEdit->setEnabled(false);

    QFile file(filePath);
    if (!file.exists()) {
        QMessageBox::warning(this, "Error", "File not found: " + filePath);
        return;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Cannot open file: " + filePath);
        return;
    }

    QTextStream in(&file);
    int rowIndex = 0;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList parts = line.split("|", Qt::SkipEmptyParts);

        // موقعیت شروع سطر فعلی
        int x = (rowIndex % 2 == 0) ? 180 : 210;
        int y = 180 + (rowIndex * 50);

        for (const QString &part : parts) {
            QString text = part.trimmed();
            if (text.isEmpty()) continue;

            QLineEdit *lineEdit = new QLineEdit(text, this);
             lineEdit->setFixedSize(70, 55);
            lineEdit->setAlignment(Qt::AlignCenter);

            QString bgColor = (rowIndex % 2 == 0) ? "#a8e6cf" : "#81c784";
            lineEdit->setStyleSheet(QString("background-color: %1;").arg(bgColor));

            lineEdit->move(x, y);
             x += 70;
        }

        rowIndex++;
    }

    file.close();
}

page4::~page4()
{
    delete ui;
}



