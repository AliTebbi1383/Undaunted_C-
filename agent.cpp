#include "agent.h"
#include <QRandomGenerator>

// ---------- Agent ----------
Agent::Agent(AgentType type, Owner owner, const QString& cellId, QPushButton* btn)
    : m_type(type), m_owner(owner), m_cellId(cellId), m_btn(btn) {}

AgentType Agent::getType() const { return m_type; }
Owner Agent::getOwner() const { return m_owner; }
QString Agent::getCellId() const { return m_cellId; }
QPushButton* Agent::getButton() const { return m_btn; }
void Agent::setCellId(const QString& newCell) {
    m_cellId = newCell;
}

// ---------- Sniper ----------
Sniper::Sniper(Owner owner, const QString& cellId, QPushButton* btn)
    : Agent(AgentType::SniperType, owner, cellId, btn) {}

bool Sniper::canMoveTo(const QString& targetCell,
                       const QStringList& visibleCells) const
{
    // فقط اگر Scout قبلاً دیده باشد
    return visibleCells.contains(targetCell);
}

QString Sniper::performAction(const QString& actionType,
                              const QString& targetCell)
{
    if (actionType == "move") {
        m_cellId = targetCell;
        return "MOVE_DONE";
    }
    if (actionType == "attack") {
        // 3 تاس 10 وجهی
        bool success = false;
        int attackThreshold = 5; // معیار حمله
        for (int i = 0; i < 3; i++) {
            int dice = QRandomGenerator::global()->bounded(1, 11);
            if (dice > attackThreshold) {
                success = true;
                break;
            }
        }
        return success ? "ATTACK_SUCCESS" : "ATTACK_FAIL";
    }
    return "INVALID_ACTION";
}

// ---------- Scout ----------
Scout::Scout(Owner owner, const QString& cellId, QPushButton* btn)
    : Agent(AgentType::ScoutType, owner, cellId, btn) {}

bool Scout::canMoveTo(const QString& targetCell,
                      const QStringList& visibleCells) const
{
    // اسکات می‌تواند به هر خانه‌ای (حتی دیده نشده) حرکت کند
    // منطق بررسی همسایگی باید در page4 انجام شود
    return true;
}

QString Scout::performAction(const QString& actionType,
                             const QString& targetCell)
{
    if (actionType == "move") {
        m_cellId = targetCell;
        return "MOVE_DONE";
    }
    if (actionType == "scout") {
        // دیده‌بانی خانه (به‌روزرسانی گرافیکی در page4 انجام می‌شود)
        return "SCOUT_DONE";
    }
    if (actionType == "attack") {
        // حمله با 1 تاس 10 وجهی
        bool success = false;
        int attackThreshold = 5; // معیار حمله
        int dice = QRandomGenerator::global()->bounded(1, 11);
        if (dice > attackThreshold) {
            success = true;
        }
        return success ? "ATTACK_SUCCESS" : "ATTACK_FAIL";
    }
    return "INVALID_ACTION";
}

// ---------- Sergeant ----------
Sergeant::Sergeant(Owner owner, const QString& cellId, QPushButton* btn)
    : Agent(AgentType::SergeantType, owner, cellId, btn) {}

bool Sergeant::canMoveTo(const QString& targetCell,
                         const QStringList& visibleCells) const
{
    // سروانت فقط می‌تواند به خانه‌هایی که دیده‌بانی شده‌اند حرکت کند
    return visibleCells.contains(targetCell);
}

QString Sergeant::performAction(const QString& actionType,
                                const QString& targetCell)
{
    if (actionType == "move") {
        m_cellId = targetCell;
        return "MOVE_DONE";
    }
    if (actionType == "control") {
        // کنترل کردن خانه (به‌روزرسانی گرافیکی و منطقی در page4 انجام می‌شود)
        return "CONTROL_DONE";
    }
    if (actionType == "release") {
        // آزادسازی خانه از کنترل دشمن (به‌روزرسانی در page4 انجام می‌شود)
        return "RELEASE_DONE";
    }
    if (actionType == "attack") {
        // حمله با 1 تاس 10 وجهی
        bool success = false;
        int attackThreshold = 5; // معیار حمله
        int dice = QRandomGenerator::global()->bounded(1, 11);
        if (dice > attackThreshold) {
            success = true;
        }
        return success ? "ATTACK_SUCCESS" : "ATTACK_FAIL";
    }
    return "INVALID_ACTION";
}
