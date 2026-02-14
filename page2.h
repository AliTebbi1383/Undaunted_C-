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

private slots:
    void on_check_clicked();
public slots:
    bool validateUsername(const QString &username, QString &errorMsg);
    void validateLiveUsername1();
    void validateLiveUsername2();
private:
    Ui::page2 *ui;
};

#endif // PAGE2_snx
