#include "../../../../include/NPC/Factory/knight_factory.hpp"
#include "../../../../include/NPC/Builder/npc_builder_main.hpp"
#include "../../../../include/NPC/Builder/npc_builder.hpp"

std::shared_ptr<NPC> KnightFactory::CreateNPC(double xCord, double yCord)
{
    std::shared_ptr<KnightBuilder> builder = std::make_shared<KnightBuilder>();
    std::shared_ptr<AgressiveNPCBuilderMain> builderMain = std::make_shared<AgressiveNPCBuilderMain>();

    builderMain->BuildNPCKnight(builder);

    std::shared_ptr<NPC> knight = builder->GetResult();

    knight->SetPosition(xCord, yCord);

    return knight;
}
