#ifndef PAGE4_H
#define PAGE4_H

#include <QDialog>
#include <QLineEdit>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui { class page4; }
QT_END_NAMESPACE

class page4 : public QDialog
{
    Q_OBJECT

public:
    explicit page4(const QString &mapName,
                   const QString &user1,
                   const QString &user2,
                   const QString &filePath,
                   QWidget *parent = nullptr);
    ~page4();

    // متدهای مورد نیاز
    int randomtern();
    void disableclick(int tern);
    void assignRandomCards();

private:
    Ui::page4 *ui;
    int tern; // متغیر نگهدارنده نوبت
    QString filePath_soljer; // مسیر فایل مهره‌ها
};

#endif // PAGE4_H
