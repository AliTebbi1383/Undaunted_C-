#include "page4.h"
#include "ui_page4.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
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

    // تنظیمات اولیه استایل
    this->setStyleSheet(
        "QLineEdit {"
        " border: 5px solid green;"
        " border-radius: 22px;"
        " padding: 5px;"
        " color: black;"
        " background-color: #f9f9f9;"
        "}"
        );

    // تعیین نوبت اولیه
    tern = randomtern();

    // تنظیم رنگ پس‌زمینه و غیرفعال کردن کلیک‌ها بر اساس نوبت
    if (tern == 0) {
        // نوبت بازیکن اول
        qDebug() << "Turn: Player 1";
        // رنگ: Red: 255, Green: 191, Blue: 255
        this->setStyleSheet("QDialog { background-color: rgb(255, 191, 255); color: black; }");
        disableclick(tern);
    } else {
        // نوبت بازیکن دوم
        qDebug() << "Turn: Player 2";
        // رنگ: Red: 190, Green: 253, Blue: 187
        this->setStyleSheet("QDialog { background-color: rgb(190, 253, 187); color: black; }");
        disableclick(tern);
    }

    ui->lineEdit->setText(mapName);
    ui->Username1->setText(user1);
    ui->Username2->setText(user2);
    ui->Username1->setEnabled(false);
    ui->Username2->setEnabled(false);
    ui->lineEdit->setEnabled(false);

    // --- خواندن فایل و ساخت کارت‌ها (کد اصلی شما بدون هیچ تغییری) ---
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
            x += 71;
        }
        rowIndex++;
    }
    file.close();
    // ---------------------------------------------------------------

    // تخصیص کارت‌های بازی به کارت‌های موجود در فرم (card1 و card2)
    assignRandomCards();
}

page4::~page4()
{
    delete ui;
}

int page4::randomtern()
{
    // تولید عدد تصادفی ۰ یا ۱
    return QRandomGenerator::global()->bounded(2);
}

void page4::disableclick(int tern)
{
    // اگر نوبت بازیکن ۱ است (tern == 0)، کارت‌های بازیکن ۲ را غیرفعال کن
    if (tern == 0) {
        for (int i = 1; i <= 10; i++) {
            QLineEdit *card = this->findChild<QLineEdit*>(QString("card2_%1").arg(i));
            if (card) card->setEnabled(false);

            // اطمینان از فعال بودن کارت‌های بازیکن ۱
            QLineEdit *card1 = this->findChild<QLineEdit*>(QString("card1_%1").arg(i));
            if (card1) card1->setEnabled(true);
        }
    }
    // اگر نوبت بازیکن ۲ است (tern == 1)، کارت‌های بازیکن ۱ را غیرفعال کن
    else {
        for (int i = 1; i <= 10; i++) {
            QLineEdit *card = this->findChild<QLineEdit*>(QString("card1_%1").arg(i));
            if (card) card->setEnabled(false);

            // اطمینان از فعال بودن کارت‌های بازیکن ۲
            QLineEdit *card2 = this->findChild<QLineEdit*>(QString("card2_%1").arg(i));
            if (card2) card2->setEnabled(true);
        }
    }
}

void page4::assignRandomCards()
{
    // --- تخصیص برای بازیکن اول (card1_1 تا card1_10) ---
    int count_Scout = 4;
    int count_Sniper = 3;
    int count_Sergeant = 3;

    for (int i = 1; i <= 10; i++) {
        int randType = QRandomGenerator::global()->bounded(1, 4); // عدد تصادفی بین ۱ تا ۳

        QString cardName = QString("card1_%1").arg(i);
        QLineEdit *card = this->findChild<QLineEdit*>(cardName);
        if (!card) continue;

        if (randType == 1 && count_Scout > 0) {
            card->setText("Scout");
            count_Scout--;
        } else if (randType == 2 && count_Sniper > 0) {
            card->setText("Sniper");
            count_Sniper--;
        } else if (randType == 3 && count_Sergeant > 0) {
            card->setText("Sergeant");
            count_Sergeant--;
        } else {
            // مدیریت حالت‌هایی که شمارنده صفر شده است
            if (count_Scout > 0) {
                card->setText("Scout");
                count_Scout--;
            } else if (count_Sniper > 0) {
                card->setText("Sniper");
                count_Sniper--;
            } else if (count_Sergeant > 0) {
                card->setText("Sergeant");
                count_Sergeant--;
            }
        }
    }

    // --- تخصیص برای بازیکن دوم (card2_1 تا card2_10) ---
    count_Scout = 4;
    count_Sniper = 3;
    count_Sergeant = 3;

    for (int i = 1; i <= 10; i++) {
        int randType = QRandomGenerator::global()->bounded(1, 4); // عدد تصادفی بین ۱ تا ۳

        QString cardName = QString("card2_%1").arg(i);
        QLineEdit *card = this->findChild<QLineEdit*>(cardName);
        if (!card) continue;

        if (randType == 1 && count_Scout > 0) {
            card->setText("Scout");
            count_Scout--;
        } else if (randType == 2 && count_Sniper > 0) {
            card->setText("Sniper");
            count_Sniper--;
        } else if (randType == 3 && count_Sergeant > 0) {
            card->setText("Sergeant");
            count_Sergeant--;
        } else {
            // مدیریت حالت‌هایی که شمارنده ها تمام شده
            if (count_Scout > 0) {
                card->setText("Scout");
                count_Scout--;
            } else if (count_Sniper > 0) {
                card->setText("Sniper");
                count_Sniper--;
            } else if (count_Sergeant > 0) {
                card->setText("Sergeant");
                count_Sergeant--;
            }
        }
    }
}
