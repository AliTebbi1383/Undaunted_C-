#include "page4.h"
#include "ui_page4.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QPushButton>
#include <QRandomGenerator>
#include <QMap>

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
        qDebug() << "Turn: Player 1";
        this->setStyleSheet("QDialog { background-color: rgb(255, 191, 255); color: black; }");
        disableclick(tern);
    } else {
        qDebug() << "Turn: Player 2";
        this->setStyleSheet("QDialog { background-color: rgb(190, 253, 187); color: black; }");
        disableclick(tern);
    }

    ui->lineEdit->setText(mapName);
    ui->Username1->setText(user1);
    ui->Username2->setText(user2);
    ui->Username1->setEnabled(false);
    ui->Username2->setEnabled(false);
    ui->lineEdit->setEnabled(false);

    // --- نگهداری مختصات خانه‌ها برای استفاده در فایل سربازان ---
    QMap<QString, QPoint> cellCoordinates;

    // --- خواندن فایل نقشه و ساخت کارت‌ها ---
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

            // --- نکته مهم: حذف عدد بعد از دو نقطه برای تطبیق با فایل سربازان ---
            // مثال: تبدیل "A16:1" به "A16"
            QString cellKey = text;
            if (cellKey.contains(':')) {
                cellKey = cellKey.split(':').first(); // بخش اول را می‌گیرد
            }
            // --------------------------------------------------------------------

            // ذخیره مختصات این خانه با کلید اصلاح شده
            cellCoordinates[cellKey] = QPoint(x, y);

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

    // تعیین مسیر فایل مهره‌ها
    if (filePath == "C:/Users/Pc/Desktop/d/QT/QT_Proj/map/1.txt") filePath_soljer = "C:/Users/Pc/Desktop/d/QT/QT_Proj/mohre/1.txt";
    else if (filePath == "C:/Users/Pc/Desktop/d/QT/QT_Proj/map/2.txt") filePath_soljer  = "C:/Users/Pc/Desktop/d/QT/QT_Proj/mohre/2.txt";
    else if (filePath == "C:/Users/Pc/Desktop/d/QT/QT_Proj/map/3.txt") filePath_soljer  = "C:/Users/Pc/Desktop/d/QT/QT_Proj/mohre/3.txt";
    else if (filePath == "C:/Users/Pc/Desktop/d/QT/QT_Proj/map/4.txt") filePath_soljer  = "C:/Users/Pc/Desktop/d/QT/QT_Proj/mohre/4.txt";
    else if (filePath == "C:/Users/Pc/Desktop/d/QT/QT_Proj/map/5.txt") filePath_soljer = "C:/Users/Pc/Desktop/d/QT/QT_Proj/mohre/5.txt";

    // ---------- فایل مهره‌ها ----------
    QFile fileSol(filePath_soljer);
    if (fileSol.exists()) {
        if (fileSol.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream inSol(&fileSol);
            int pieceCounter = 0;

            while (!inSol.atEnd()) {
                QString line = inSol.readLine().trimmed();
                if (line.isEmpty()) continue;

                // مثال خط: A14:B,Seargeant
                QStringList mainParts = line.split(",");
                if (mainParts.size() != 2) continue;

                QString positionPart = mainParts[0]; // A14:B
                QString typePart     = mainParts[1]; // Seargeant

                // اصلاح شرط: اگر هیچکدام از این‌ها نبود، ادامه بده
                if (typePart != "Seargeant" && typePart != "Sniper" && typePart != "Scout") {
                    continue;
                }

                // نمایش پیام تایید تشخیص سرباز
                QMessageBox::warning(this, "تشخیص سرباز", "نوع سرباز تشخیص داده شد: " + typePart);

                // جدا کردن A14 و B
                QStringList posParts = positionPart.split(":");
                if (posParts.size() != 2) continue;

                QString cell = posParts[0];   // A14
                QString player = posParts[1]; // A یا B

                // ---------- دریافت مختصات از نقشه ----------
                QPoint cellPos = cellCoordinates.value(cell);
                if (cellPos.isNull()) {
                    qDebug() << "Coordinates not found for cell:" << cell;
                    QMessageBox::warning(this, "Error", "مختصات برای خانه " + cell + " پیدا نشد!");
                    continue;
                }
                // -----------------------------------------

                // ---------- ساخت دکمه ----------
                QPushButton *btn = new QPushButton(this);
                btn->setFixedSize(70, 55);
                btn->move(cellPos); // استفاده از مختصات ذخیره شده

                // ---------- رنگ بر اساس بازیکن ----------
                if (player == "A") {
                    btn->setStyleSheet("background-color:red; border-radius:8px; color: white;");
                } else if (player == "B") {
                    btn->setStyleSheet("background-color:blue; border-radius:8px; color: white;");
                }

                // ---------- متن بر اساس نوع سرباز ----------
                if (typePart == "Seargeant") {
                    btn->setText("S");
                }
                else if (typePart == "Scout") {
                    btn->setText("Sc");
                }
                else if (typePart == "Sniper") {
                    btn->setText("Sn");
                }
                else {
                    delete btn;
                    continue;
                }

                btn->show();
                pieceCounter++;
            }
            fileSol.close();
        } else {
            QMessageBox::warning(this, "Error", "Cannot open soldier file");
        }
    }
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
