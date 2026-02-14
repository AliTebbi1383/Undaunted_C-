#ifndef MAPDIALOG_H
#define MAPDIALOG_H

#include <QDialog>
#include <QListWidget>   // ← needed for QListWidget and QListWidgetItem
#include <QString>

namespace Ui {
class MapDialog;
}

class MapDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MapDialog(QWidget *parent = nullptr);
    ~MapDialog();

    QString selectedMap() const;

private slots:
    // Must be exactly this signature for auto-connection:
    void on_mapList_itemDoubleClicked(QListWidgetItem *item);
void onItemDoubleClicked(QListWidgetItem *item);
private:
    Ui::MapDialog *ui;
    QString chosenMap;
};

#endif // MAPDIALOG_H
