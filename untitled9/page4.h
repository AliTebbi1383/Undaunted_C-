#ifndef PAGE4_H
#define PAGE4_H

#include <QWidget>

namespace Ui {
class page4;
}

class page4 : public QWidget
{
    Q_OBJECT

public:
    // امضای سازنده: mapName و usernameها را به صفحه4 می‌دهیم
    explicit page4(const QString &mapName = QString(),
                   const QString &username1 = QString(),
                   const QString &username2 = QString(),
                   QWidget *parent = nullptr);
    ~page4();

private:
    Ui::page4 *ui;
    QString m_mapName;
    QString m_username1;
    QString m_username2;
};

#endif // PAGE4_H
