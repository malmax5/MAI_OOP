#include "../include/infodialog.hpp"

ColorWidget::ColorWidget(const QMap<NPCId, QColor>& npcColorMap, const QMap<WeaponId, QColor>& weaponColorMap, QWidget *parent)
    : QWidget(parent), npcColorMap_(npcColorMap), weaponColorMap_(weaponColorMap)
{}

void ColorWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int yOffset = 20;

    painter.drawText(10, yOffset, "NPC Colors:");
    yOffset += 20;
    int xOffset = 10;
    for (auto it = npcColorMap_.begin(); it != npcColorMap_.end(); ++it) {
        QString colorName = it.key() == NPCId::KnightId ? "Knight" :
                            it.key() == NPCId::PegasusId ? "Pegasus" :
                            it.key() == NPCId::SquirrelId ? "Squirrel" : "Unknown";
        painter.setBrush(it.value());
        painter.drawEllipse(xOffset, yOffset, 20, 20);
        painter.drawText(xOffset + 30, yOffset + 15, colorName);
        yOffset += 30;
    }

    yOffset += 20;

    painter.drawText(10, yOffset, "Weapon Colors:");
    yOffset += 20;
    for (auto it = weaponColorMap_.begin(); it != weaponColorMap_.end(); ++it) {
        QString weaponName = it.key() == WeaponId::AutomaticRifleId ? "Automatic Rifle" :
                             it.key() == WeaponId::KatanaId ? "Katana" :
                             it.key() == WeaponId::KnifeId ? "Knife" :
                             it.key() == WeaponId::MachineGunId ? "Machine Gun" :
                             it.key() == WeaponId::PistolId ? "Pistol" :
                             it.key() == WeaponId::SniperRifleId ? "Sniper Rifle" : "Unknown";
        painter.setBrush(it.value());
        painter.drawRect(xOffset, yOffset, 20, 20);
        painter.drawText(xOffset + 30, yOffset + 15, weaponName);
        yOffset += 30;
    }
}

InfoDialog::InfoDialog(QWidget *parent)
    : QDialog(parent)
{
    npcColorMap_.insert(NPCId::KnightId, Qt::red);
    npcColorMap_.insert(NPCId::PegasusId, Qt::green);
    npcColorMap_.insert(NPCId::SquirrelId, QColor(255, 165, 0));

    weaponColorMap_.insert(WeaponId::AutomaticRifleId, Qt::darkGray);
    weaponColorMap_.insert(WeaponId::KatanaId, Qt::darkYellow);
    weaponColorMap_.insert(WeaponId::KnifeId, Qt::darkCyan);
    weaponColorMap_.insert(WeaponId::MachineGunId, Qt::darkMagenta);
    weaponColorMap_.insert(WeaponId::PistolId, Qt::darkBlue);
    weaponColorMap_.insert(WeaponId::SniperRifleId, Qt::darkGreen);

    QString infoText = "<html><body>";
    infoText += "<h3>NPC strategy:</h3>";
    infoText += "<ul>";
    infoText += "<li>Knight attack Squirrel</li>";
    infoText += "<li>Squirrel attack Pegasus</li>";
    infoText += "<li>Pegasus is peaceful</li>";
    infoText += "</ul>";
    infoText += "</body></html>";

    infoLabel_ = new QLabel(infoText, this);
    infoLabel_->setTextFormat(Qt::RichText);

    colorWidget_ = new ColorWidget(npcColorMap_, weaponColorMap_, this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(infoLabel_);
    layout->addWidget(colorWidget_);
}

InfoDialog::~InfoDialog()
{}