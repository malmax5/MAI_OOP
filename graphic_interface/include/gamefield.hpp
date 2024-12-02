#pragma once

#include <QWidget>
#include <QTimer>
#include "../../include/Game/game_settings.hpp"
#include "../../include/NPC/Base/npc.hpp"

using GameSettings::NPCId;

class GameField : public QWidget
{
    Q_OBJECT

public:
    GameField(QWidget *parent = nullptr);
    ~GameField();

    void ClearNPC();

protected:
    void paintEvent(QPaintEvent *event) override;

public slots:
    void AddKnightPoint(std::shared_ptr<NPC> knight, double x, double y);
    void AddPegasusPoint(std::shared_ptr<NPC> pegasus, double x, double y);
    void AddSquirrelPoint(std::shared_ptr<NPC> squirrel, double x, double y);
    void UpdateNPCs();

private:
    QList<std::shared_ptr<NPC>> npcs_;
    QMap<NPCId, QColor> colorMap_;
    QTimer *timer_;
};