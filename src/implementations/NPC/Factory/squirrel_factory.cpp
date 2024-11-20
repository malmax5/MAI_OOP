#include "../../../../include/NPC/Factory/squirrel_factory.hpp"
#include "../../../../include/NPC/Builder/npc_builder_main.hpp"
#include "../../../../include/NPC/Builder/npc_builder.hpp"

NPC* SquirrelFactory::CreateNPC(double xCord, double yCord)
{
    SquirrelBuilder builder;
    AgressiveNPCBuilderMain builderMain;

    builderMain.BuildNPCSquirrel(&builder);

    AgressiveNPC* squirrel = builder.GetResult();

    squirrel->SetPosition(xCord, yCord);

    return squirrel;
}
