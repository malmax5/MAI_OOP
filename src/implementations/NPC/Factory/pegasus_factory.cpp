#include "../../../../include/NPC/Factory/pegasus_factory.hpp"
#include "../../../../include/NPC/Builder/npc_builder_main.hpp"
#include "../../../../include/NPC/Builder/npc_builder.hpp"

std::shared_ptr<NPC> PegasusFactory::CreateNPC(double xCord, double yCord)
{
    std::shared_ptr<PegasusBuilder> builder = std::make_shared<PegasusBuilder>();
    std::shared_ptr<PeacefulNPCBuilderMain> builderMain = std::make_shared<PeacefulNPCBuilderMain>();

    builderMain->BuildNPCPegasus(builder);

    std::shared_ptr<PeacefulNPC> pegasus = builder->GetResult();

    pegasus->SetPosition(xCord, yCord);

    return pegasus;
}
