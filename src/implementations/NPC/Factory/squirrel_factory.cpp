#include "../../../../include/NPC/Factory/squirrel_factory.hpp"
#include "../../../../include/NPC/Builder/npc_builder_main.hpp"
#include "../../../../include/NPC/Builder/npc_builder.hpp"

std::shared_ptr<NPC> SquirrelFactory::CreateNPC(double xCord, double yCord)
{
    std::shared_ptr<SquirrelBuilder> builder = std::make_shared<SquirrelBuilder>();
    std::shared_ptr<AgressiveNPCBuilderMain> builderMain = std::make_shared<AgressiveNPCBuilderMain>();

    builderMain->BuildNPCSquirrel(builder);

    std::shared_ptr<NPC> squirrel = builder->GetResult();

    squirrel->SetPosition(xCord, yCord);

    return squirrel;
}
