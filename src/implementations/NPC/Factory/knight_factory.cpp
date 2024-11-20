#include "../../../../include/NPC/Factory/knight_factory.hpp"
#include "../../../../include/NPC/Builder/npc_builder_main.hpp"
#include "../../../../include/NPC/Builder/npc_builder.hpp"

NPC* KnightFactory::CreateNPC(double xCord, double yCord)
{
    KnightBuilder builder;
    AgressiveNPCBuilderMain builderMain;

    builderMain.BuildNPCKnight(&builder);

    AgressiveNPC* knight = builder.GetResult();

    knight->SetPosition(xCord, yCord);

    return knight;
}
