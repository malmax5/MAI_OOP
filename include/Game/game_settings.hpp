#pragma once

namespace GameSettings {

    enum class EquipTypeId
    {
        HelmetId = 0,
        ChestplateId = 1,
        BootsId = 2
    };

    enum class NPCId
    {
        KnightId = 0,
        PegasusId = 1,
        SquirrelId = 2
    };

    enum class MaterialId
    {
        NoMaterialMaterial = 0,
        DecorativeMaterial = 1,
        IronMaterial = 2,
        GoldMaterial = 3,
        DiamondMaterial = 4
    };

    enum class WeaponId
    {
        AutomaticRifleId = 0,
        KatanaId = 1,
        KnifeId = 2,
        MachineGunId = 3,
        PistolId = 4,
        SniperRifleId = 5
    };

    struct ArmorMultiple
    {
        static constexpr double NoMaterialMultiple = 0.0;
        static constexpr double DecorativeMultiple = 1.0;
        static constexpr double IronMultiple = 2.0;
        static constexpr double GoldMultiple = 3.0;
        static constexpr double DiamondMultiple = 4.0;
    };

    struct EquipArmor
    {
        static constexpr double HelmetArmor = 10.0;
        static constexpr double ChestplateArmor = 20.0;
        static constexpr double BootsArmor = 5.0;
    };

    struct WeaponStats
    {
        double attackDamege;
        double attackDistance;
        double reloadingTime;
    };

    inline const WeaponStats AutomaticRifleStat = 
    {
        .attackDamege = 3,
        .attackDistance = 5,
        .reloadingTime = 0.3
    };

    inline const WeaponStats KatanaStat = 
    {
        .attackDamege = 7,
        .attackDistance = 1,
        .reloadingTime = 1.2
    };

    inline const WeaponStats KnifeStat = 
    {
        .attackDamege = 5,
        .attackDistance = 1,
        .reloadingTime = 1
    };

    inline const WeaponStats MachineGunStat = 
    {
        .attackDamege = 5,
        .attackDistance = 5,
        .reloadingTime = 0.5
    };

    inline const WeaponStats PistolStat = 
    {
        .attackDamege = 10,
        .attackDistance = 5,
        .reloadingTime = 2
    };

    inline const WeaponStats SniperRifleStat = 
    {
        .attackDamege = 20,
        .attackDistance = 20,
        .reloadingTime = 10
    };

    struct NPCStats
    {
        double hp;
        double armor;
        double speed;
        double attackDamage;
        double attackDistance;
        int attackReloading;
    };

    inline const NPCStats KnightStat =
    {
        .hp = 100.0,
        .armor = 50.0,
        .speed = 5.0,
    };

    inline const NPCStats SquirrelStat =
    {
        .hp = 50.0,
        .armor = 30.0,
        .speed = 7.0,
    };

    inline const NPCStats PegasusStat =
    {
        .hp = 20.0,
        .armor = 10.0,
        .speed = 1.0
    };
}