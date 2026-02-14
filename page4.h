#ifndef PAGE4_H
#define PAGE4_H

#include <QDialog>
#include <QVector>
#include <QStringList>
#include <QMap>
#include <QPoint>
#include "agent.h"

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

    int randomtern();
    void disableclick(int tern);
    void assignRandomCards();

    // متدهای کمکی برای منطق بازی
    QStringList getNeighbors(const QString &cellId);
    void updateCellVisuals(const QString &cellId);
void updateTurnVisuals();
private:
    Ui::page4 *ui;

    int tern;
    QString filePath_soljer;

    QVector<Agent*> agentsList;

    // لیست خانه‌های دیده‌بانی شده توسط هر بازیکن
    QStringList visibleCellsA;
    QStringList visibleCellsB;

    // نقشه‌ی مختصات خانه‌ها برای پیدا کردن موقعیت دکمه‌ها
    QMap<QString, QPoint> cellCoordinates;

    // لیست خانه‌های تحت کنترل هر بازیکن
    QMap<QString, Owner> controlledCells;
};

#endif // PAGE4_H
