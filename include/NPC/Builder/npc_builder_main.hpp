#include "npc_builder.hpp"
#include "../../Equipment/Factory/equipment_factory.hpp"

class NPCBuilderMain
{
public:
    void BuildNPCKnight(NPCBuilder* builder);
    void BuildNPCPegasus(NPCBuilder* builder);
    void BuildNPCSquirrel(NPCBuilder* builder);

private:
    static unsigned int npcCount;
    static StandartEquipmentFactoryRandom* equipFactory;
};