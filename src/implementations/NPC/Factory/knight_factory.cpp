#include "../../../../include/NPC/Factory/knight_factory.hpp"
#include "../../../../include/NPC/Builder/npc_builder_main.hpp"
#include "../../../../include/NPC/Builder/npc_builder.hpp"

NPC* KnightFactory::CreateNPC()
{
    NPCBuilder builder;
    NPCBuilderMain builderMain;

    builderMain.BuildNPCKnight(&builder);

    return builder.GetResult();
}
