#ifndef AGENT_H
#define AGENT_H

#include <QString>
#include <QStringList>
#include <QPushButton>

// --- Enum ها ---
enum Owner { PlayerA, PlayerB };
enum AgentType { SniperType, ScoutType, SergeantType };

// --- کلاس پایه Agent ---
class Agent {
public:
    Agent(AgentType type, Owner owner, const QString& cellId, QPushButton* btn);
    virtual ~Agent() = default;

    AgentType getType() const;
    Owner getOwner() const;
    QString getCellId() const;
    QPushButton* getButton() const;
    void setCellId(const QString& newCell);

    // --- اکشن‌ها ---
    virtual bool canMoveTo(const QString& targetCell,
                           const QStringList& visibleCells) const = 0;
    virtual QString performAction(const QString& actionType,
                                  const QString& targetCell = "") = 0;

protected:
    AgentType m_type;
    Owner m_owner;
    QString m_cellId;
    QPushButton* m_btn;
};

// --- Sniper ---
class Sniper : public Agent {
public:
    Sniper(Owner owner, const QString& cellId, QPushButton* btn);
    bool canMoveTo(const QString& targetCell,
                   const QStringList& visibleCells) const override;
    QString performAction(const QString& actionType,
                          const QString& targetCell = "") override;
};

// --- Scout ---
class Scout : public Agent {
public:
    Scout(Owner owner, const QString& cellId, QPushButton* btn);
    bool canMoveTo(const QString& targetCell,
                   const QStringList& visibleCells) const override;
    QString performAction(const QString& actionType,
                          const QString& targetCell = "") override;
};

// --- Sergeant ---
class Sergeant : public Agent {
public:
    Sergeant(Owner owner, const QString& cellId, QPushButton* btn);
    bool canMoveTo(const QString& targetCell,
                   const QStringList& visibleCells) const override;
    QString performAction(const QString& actionType,
                          const QString& targetCell = "") override;
};

#endif // AGENT_H
