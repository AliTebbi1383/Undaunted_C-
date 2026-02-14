#ifndef PAGE3_H
#define PAGE3_H

#include <QDialog>

namespace Ui {
class page3;
}

class page3 : public QDialog
{
    Q_OBJECT

public:
    explicit page3(QWidget *parent = nullptr);
    ~page3();

private slots:
    void on_pushButton_clicked();

private:
    Ui::page3 *ui;
};

#endif // PAGE3_H
