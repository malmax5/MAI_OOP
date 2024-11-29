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

    struct NPCStats
    {
        double hp;
        double armor;
        double speed;
        double attackDamage;
        double attackDistance;
        int attackReloading;
    };

    struct ArmorMultiple
    {
        static constexpr double NoMaterialMultiple = 0.0;
        static constexpr double DecorativeMultiple = 1.0;
        static constexpr double IronMultiple = 2.0;
        static constexpr double GoldMultiple = 3.0;
        static constexpr double DiamondMultiple = 4.0;
    };

    inline const NPCStats KnightStat =
    {
        .hp = 100.0,
        .armor = 50.0,
        .speed = 5.0,
        .attackDamage = 10.0,
        .attackDistance = 30.0,
        .attackReloading = 3
    };

    inline const NPCStats SquirrelStat =
    {
        .hp = 50.0,
        .armor = 30.0,
        .speed = 7.0,
        .attackDamage = 5.0,
        .attackDistance = 30.0,
        .attackReloading = 2
    };

    inline const NPCStats PegasusStat =
    {
        .hp = 20.0,
        .armor = 10.0,
        .speed = 1.0
    };
}