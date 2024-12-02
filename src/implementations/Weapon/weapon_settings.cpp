#include "../../../include/Weapon/weapon_settings.hpp"

std::shared_ptr<Weapon> WeaponByMask(WeaponId weaponId)
{
    std::shared_ptr<Weapon> weapon;
    
    switch (weaponId)
    {
    case WeaponId::AutomaticRifleId:
        weapon = std::make_shared<AutomaticRifle>();
        break;
    case WeaponId::KatanaId:
        weapon = std::make_shared<Katana>();
        break;
    case WeaponId::KnifeId:
        weapon = std::make_shared<Knife>();
        break;
    case WeaponId::MachineGunId:
        weapon = std::make_shared<MachineGun>();
        break;
    case WeaponId::PistolId:
        weapon = std::make_shared<Pistol>();
        break;
    case WeaponId::SniperRifleId:
        weapon = std::make_shared<SniperRifle>();
        break;
    
    default:
        break;
    }

    return weapon;
}