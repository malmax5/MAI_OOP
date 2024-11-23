#include "../Enums/type_id_enum.hpp"
#include "../Base/agressive_npc.hpp"

class Squirrel : public AgressiveNPC
{
public:
    Squirrel();
    void AcceptVisitor(std::shared_ptr<Visitor> visitor) final;
    void Reload() final;
};