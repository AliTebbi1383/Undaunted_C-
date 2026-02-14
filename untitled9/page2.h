#ifndef PAGE2_H
#define PAGE2_H

#include <QDialog>

namespace Ui {
class page2;
}

class page2 : public QDialog
{
    Q_OBJECT

public:
    explicit page2(QWidget *parent = nullptr);
    ~page2();

private:
    Ui::page2 *ui;

    // مقادیر ورودی کاربر
    QString Username1;
    QString Username2;

private slots:
    void on_check_clicked();            // کلیدی برای بررسی مقادیر
    void validateLiveUsername1();       // ویرایش زنده برای Username1
    void validateLiveUsername2();       // ویرایش زنده برای Username2

    // تابع مشترک برای اعتبارسنجی با قوانین مشخص
    bool validateUsername(const QString &username, QString &errorMsg);
};

#endif // PAGE2_H
