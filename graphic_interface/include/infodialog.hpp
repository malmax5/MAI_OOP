#pragma once

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QColor>
#include <QMap>
#include <QPainter>
#include <QWidget>


#include "../../include/Game/game_settings.hpp"

using GameSettings::NPCId;
using GameSettings::WeaponId;

class ColorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ColorWidget(const QMap<NPCId, QColor>& npcColorMap, const QMap<WeaponId, QColor>& weaponColorMap, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QMap<NPCId, QColor> npcColorMap_;
    QMap<WeaponId, QColor> weaponColorMap_;
};

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();

private:
    QLabel *infoLabel_;
    QMap<NPCId, QColor> npcColorMap_;
    QMap<WeaponId, QColor> weaponColorMap_;
    ColorWidget *colorWidget_;
};
