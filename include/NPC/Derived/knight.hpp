#include "../Enums/type_id_enum.hpp"
#include "../Base/agressive_npc.hpp"

class Knight : public AgressiveNPC
{
public:
    Knight();
    void AcceptVisitor(std::shared_ptr<Visitor> visitor) final;
    void Reload() final;
};