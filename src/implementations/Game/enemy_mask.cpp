#include "../../../include/Game/enemy_mask.hpp"

bool InMaskAttack(NPCId attacker, NPCId target)
{
    return (EnemyMask.find(attacker) != EnemyMask.end() &&
            EnemyMask[attacker].find(target) != EnemyMask[attacker].end());
}