#include "../include/gamefield.hpp"
#include <QPainter>
#include <QResizeEvent>

GameField::GameField(QWidget *parent)
    : QWidget(parent)
{
    colorMap_.insert(NPCId::KnightId, Qt::red);
    colorMap_.insert(NPCId::PegasusId, Qt::green);
    colorMap_.insert(NPCId::SquirrelId, QColor(255, 165, 0));

    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &GameField::UpdateNPCs);
    timer_->start(100);
}

GameField::~GameField()
{}

void GameField::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int width = this->width();
    int height = this->height();
    painter.drawLine(0, height / 2, width, height / 2);
    painter.drawLine(width / 2, 0, width / 2, height);

    for (const auto& npc : npcs_)
    {
        QColor color = colorMap_.value(npc->GetTypeId(), Qt::black);
        painter.setBrush(color);
        painter.setPen(Qt::NoPen);
        int screenX = width / 2 + npc->GetXCord();
        int screenY = height / 2 - npc->GetYCord();
        painter.drawEllipse(screenX - 5, screenY - 5, 10, 10);
    }
}

void GameField::AddKnightPoint(std::shared_ptr<NPC> knight, double x, double y)
{
    npcs_.append(knight);
    update();
}

void GameField::AddPegasusPoint(std::shared_ptr<NPC> pegasus, double x, double y)
{
    npcs_.append(pegasus);
    update();
}

void GameField::AddSquirrelPoint(std::shared_ptr<NPC> squirrel, double x, double y)
{
    npcs_.append(squirrel);
    update();
}

void GameField::UpdateNPCs()
{
    for (auto it = npcs_.begin(); it != npcs_.end(); )
    {
        if ((*it)->GetHp() <= 0)
        {
            it = npcs_.erase(it);
        }
        else
        {
            ++it;
        }
    }
    update();
}

void GameField::ClearNPC()
{
    for (auto it = npcs_.begin(); it != npcs_.end(); )
    {
        it = npcs_.erase(it);
    }
}
