#include "../../../../include/NPC/Factory/squirrel_factory.hpp"
#include "../../../../include/NPC/Builder/npc_builder_main.hpp"
#include "../../../../include/NPC/Builder/npc_builder.hpp"

NPC* SquirrelFactory::CreateNPC()
{
    NPCBuilder builder;
    NPCBuilderMain builderMain;

    builderMain.BuildNPCSquirrel(&builder);

    return builder.GetResult();
}
