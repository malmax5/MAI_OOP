#include "../include/gamefield.hpp"
#include <QPainter>
#include <QResizeEvent>

GameField::GameField(QWidget *parent)
    : QWidget(parent)
{
    colorMap_.insert(NPCId::KnightId, Qt::red);
    colorMap_.insert(NPCId::PegasusId, Qt::green);
    colorMap_.insert(NPCId::SquirrelId, QColor(255, 165, 0));

    weaponColorMap_.insert(WeaponId::AutomaticRifleId, Qt::darkGray);
    weaponColorMap_.insert(WeaponId::KatanaId, Qt::darkYellow);
    weaponColorMap_.insert(WeaponId::KnifeId, Qt::darkCyan);
    weaponColorMap_.insert(WeaponId::MachineGunId, Qt::darkMagenta);
    weaponColorMap_.insert(WeaponId::PistolId, Qt::darkBlue);
    weaponColorMap_.insert(WeaponId::SniperRifleId, Qt::darkGreen);

    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &GameField::UpdateNPCs);
    timer_->start(10);
}

GameField::~GameField()
{
    ClearNPC();
}

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
        painter.drawEllipse(screenX - 5, screenY - 5, 20, 20);

        if (std::dynamic_pointer_cast<AgressiveNPC>(npc))
        {
            QColor weaponColor = weaponColorMap_.value(std::dynamic_pointer_cast<AgressiveNPC>(npc)->GetWeaponId(), Qt::black);
            painter.setBrush(weaponColor);
            painter.drawRect(screenX, screenY, 10, 10);
        }
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

QPointF GameField::NpcToScreenCoords(double x, double y) const
{
    int width = this->width();
    int height = this->height();
    double screenX = width / 2.0 + x;
    double screenY = height / 2.0 - y;
    return QPointF(screenX, screenY);
}

QPointF GameField::ScreenToNpcCoords(double screenX, double screenY) const
{
    int width = this->width();
    int height = this->height();
    double x = screenX - width / 2.0;
    double y = height / 2.0 - screenY;
    return QPointF(x, y);
}

std::shared_ptr<NPC> GameField::FindClosestNPC(const QPointF& mousePos, double threshold) const
{
    std::shared_ptr<NPC> closestNpc;
    double minDistance = std::numeric_limits<double>::max();
    for (const auto& npc : npcs_)
    {
        QPointF npcScreenPos = NpcToScreenCoords(npc->GetXCord(), npc->GetYCord());
        double distance = QLineF(mousePos, npcScreenPos).length();
        if (distance < minDistance)
        {
            minDistance = distance;
            closestNpc = npc;
        }
    }
    if (minDistance < threshold)
        return closestNpc;
    else
        return nullptr;
}

void GameField::mouseMoveEvent(QMouseEvent* event)
{
    QWidget::mouseMoveEvent(event);
    QPointF mousePos(event->pos().x(), event->pos().y());
    std::shared_ptr<NPC> closestNpc = FindClosestNPC(mousePos, 10.0); // 10.0 - порог
    if (closestNpc)
    {
        QString tooltipText;
        if (std::dynamic_pointer_cast<IAttackable>(closestNpc))
        {
            tooltipText = QString("Тип NPC: %1\nHP: %2\nSpeed: %3\nWeapon: %4\nAttackDamage: %5\nAttackDistance: %6")
                .arg(QString::fromStdString(closestNpc->GetClassName()))
                .arg(closestNpc->GetHp())
                .arg(closestNpc->GetSpeed())
                .arg(QString::fromStdString(std::dynamic_pointer_cast<AgressiveNPC>(closestNpc)->GetWeaponName()))
                .arg(std::dynamic_pointer_cast<IAttackable>(closestNpc)->GetAttackDamage())
                .arg(std::dynamic_pointer_cast<IAttackable>(closestNpc)->GetAttackDistance());
        }
        else
        {
            tooltipText = QString("Тип NPC: %1\nHP: %2\nSpeed: %3")
                .arg(QString::fromStdString(closestNpc->GetClassName()))
                .arg(closestNpc->GetHp())
                .arg(closestNpc->GetSpeed());
        }
        QToolTip::showText(event->globalPos(), tooltipText, this);
    }
    else
    {
        QToolTip::hideText();
    }
}

QString GameField::GetNPCName(NPCId id)
{
    switch (id)
    {
        case NPCId::KnightId: return "Рыцарь";
        case NPCId::PegasusId: return "Пегас";
        case NPCId::SquirrelId: return "Белка";
        default: return "Неизвестно";
    }
}
