#include "mapdialog.h"
#include "ui_mapdialog.h"
#include <QDir>
#include <QListWidget>
#include <QListWidgetItem>

MapDialog::MapDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MapDialog)
{
    ui->setupUi(this);

    // Try to find a QListWidget named "mapList"; if not found, try common names
    QListWidget *list = this->findChild<QListWidget*>("mapList");
    if (!list) list = this->findChild<QListWidget*>("listWidget");
    if (!list) {
        // Fallback: create one if UI has none
        list = new QListWidget(this);
        list->setObjectName("mapList");
        list->setMinimumSize(300, 200);
        list->show(); // or add to a layout if you have one
        // اگر layout داری:
        // if (auto layout = this->layout()) layout->addWidget(list);
    }

    // Load maps
    QDir dir("C:/Users/Pc/Desktop/QT/QT_Proj/map");
    const QStringList files = dir.entryList(QStringList() << "*.txt", QDir::Files);
    for (const QString &file : files) {
        list->addItem(file);
    }

    // Manual connection for double click
    connect(list, &QListWidget::itemDoubleClicked,
            this, &MapDialog::onItemDoubleClicked);
}

MapDialog::~MapDialog()
{
    delete ui;
}

void MapDialog::onItemDoubleClicked(QListWidgetItem *item)
{
    chosenMap = item->text();
    accept();
}

QString MapDialog::selectedMap() const
{
    return chosenMap;
}
