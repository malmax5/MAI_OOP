#include "../../../../include/NPC/Factory/pegasus_factory.hpp"
#include "../../../../include/NPC/Builder/npc_builder_main.hpp"
#include "../../../../include/NPC/Builder/npc_builder.hpp"

NPC* PegasusFactory::CreateNPC()
{
    NPCBuilder builder;
    NPCBuilderMain builderMain;

    builderMain.BuildNPCPegasus(&builder);

    return builder.GetResult();
}
