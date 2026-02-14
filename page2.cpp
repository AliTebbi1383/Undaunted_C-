#include "page2.h"
#include "ui_page2.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QDialog>
#include <QListWidget>
#include <QVBoxLayout>
#include <QMessageBox>
#include "page4.h"
// Global variables
QString Username1, Username2;

page2::page2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::page2)
{
    ui->setupUi(this);

    // Set white background and black text for the dialog
    this->setStyleSheet("background-color: white; color: black;");

    // Connect textChanged signals to live validation slots
    connect(ui->Username1, &QLineEdit::textChanged, this, &page2::validateLiveUsername1);
    connect(ui->Username2, &QLineEdit::textChanged, this, &page2::validateLiveUsername2);
}

page2::~page2()
{
    delete ui;
}

void page2::on_check_clicked()
{
    Username1 = ui->Username1->text();
    Username2 = ui->Username2->text();

    QString errorMsg;

    // Validate Username1
    bool valid1 = validateUsername(Username1, errorMsg);
    if (!valid1) {
        ui->Username1->setStyleSheet("color: red; border: 2px solid red;");
        QMessageBox::warning(this, "Player 1 Error", errorMsg);
    } else {
        ui->Username1->setStyleSheet("color: green; border: 2px solid green;");
    }

    // Validate Username2
    bool valid2 = validateUsername(Username2, errorMsg);
    if (!valid2) {
        ui->Username2->setStyleSheet("color: red; border: 2px solid red;");
        QMessageBox::warning(this, "Player 2 Error", errorMsg);
    } else {
        ui->Username2->setStyleSheet("color: green; border: 2px solid green;");
    }

    // If both usernames are valid, proceed to map selection
    if (valid1 && valid2) {
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
            page4 *game = new page4(chosenMap, Username1, Username2, this);
            game->show();   // نمایش غیرمودال
            // اگر بخواهی مودال باشد:
            // game->exec();
            this->hide();
            modalDialog.accept();  // بستن مودال
        });

        // نمایش مودال
        modalDialog.exec();
    }
}

bool page2::validateUsername(const QString &username, QString &errorMsg)
{
    // Rule 1: Minimum length of 8 characters
    if (username.length() < 8) {
        errorMsg = "Username must be at least 8 characters long.";
        return false;
    }

    // Rule 2: Must not start with a digit or special character
    if (username[0].isDigit() || !username[0].isLetter()) {
        errorMsg = "Username must not start with a digit or special character.";
        return false;
    }

    // Rule 3: Must contain at least one digit
    QRegularExpression hasDigit("\\d");
    if (!hasDigit.match(username).hasMatch()) {
        errorMsg = "Username must contain at least one digit.";
        return false;
    }

    // Rule 4: Must contain at least one special character
    QRegularExpression hasSpecial("[^a-zA-Z0-9]");
    if (!hasSpecial.match(username).hasMatch()) {
        errorMsg = "Username must contain at least one special character.";
        return false;
    }

    // Rule 5: Must contain both uppercase and lowercase letters
    QRegularExpression hasUpper("[A-Z]");
    QRegularExpression hasLower("[a-z]");
    if (!hasUpper.match(username).hasMatch() || !hasLower.match(username).hasMatch()) {
        errorMsg = "Username must contain both uppercase and lowercase letters.";
        return false;
    }

    return true;
}

// Live validation for Username1
void page2::validateLiveUsername1()
{
    QString errorMsg;
    QString text = ui->Username1->text();

    if (validateUsername(text, errorMsg)) {
        ui->Username1->setStyleSheet("color: green; border: 2px solid green;");
    } else {
        ui->Username1->setStyleSheet("color: red; border: 2px solid red;");
    }
}

// Live validation for Username2
void page2::validateLiveUsername2()
{
    QString errorMsg;
    QString text = ui->Username2->text();

    if (validateUsername(text, errorMsg)) {
        ui->Username2->setStyleSheet("color: green; border: 2px solid green;");
    } else {
        ui->Username2->setStyleSheet("color: red; border: 2px solid red;");
    }
}
