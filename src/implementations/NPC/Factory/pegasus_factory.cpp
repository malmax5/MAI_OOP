#include "../../../../include/NPC/Factory/pegasus_factory.hpp"
#include "../../../../include/NPC/Builder/npc_builder_main.hpp"
#include "../../../../include/NPC/Builder/npc_builder.hpp"

NPC* PegasusFactory::CreateNPC(double xCord, double yCord)
{
    PegasusBuilder builder;
    PeacefulNPCBuilderMain builderMain;

    builderMain.BuildNPCPegasus(&builder);

    PeacefulNPC* pegasus = builder.GetResult();

    pegasus->SetPosition(xCord, yCord);

    return pegasus;
}
