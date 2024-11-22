#include "../../../../include/Game/Visitor/get_info_visitor.hpp"

#include "../../../../include/NPC/Derived/knight.hpp"
#include "../../../../include/NPC/Derived/pegasus.hpp"
#include "../../../../include/NPC/Derived/squirrel.hpp"

void GetInfoVisitor::Visit(Knight* knight)
{
    std::cout << "In Game Knight:\n" <<
                 "   TypeId: " << knight->GetTypeId() << "\n" <<
                 "   CurrentId: " << knight->GetCurrentId() << "\n" <<
                 "   Hp: " << knight->GetHp() << "\n" <<
                 "   Position X: " << knight->GetXCord() << "\n" <<
                 "   Position Y: " << knight->GetYCord() << "\n";
}

void GetInfoVisitor::Visit(Pegasus* pegasus)
{
    std::cout << "In Game Pegasus:\n" <<
                 "   TypeId: " << pegasus->GetTypeId() << "\n" <<
                 "   CurrentId: " << pegasus->GetCurrentId() << "\n" <<
                 "   Hp: " << pegasus->GetHp() << "\n" <<
                 "   Position X: " << pegasus->GetXCord() << "\n" <<
                 "   Position Y: " << pegasus->GetYCord() << "\n";
}

void GetInfoVisitor::Visit(Squirrel* squirrel)
{
    std::cout << "In Game Squirrel:\n" <<
                 "   TypeId: " << squirrel->GetTypeId() << "\n" <<
                 "   CurrentId: " << squirrel->GetCurrentId() << "\n" <<
                 "   Hp: " << squirrel->GetHp() << "\n" <<
                 "   Position X: " << squirrel->GetXCord() << "\n" <<
                 "   Position Y: " << squirrel->GetYCord() << "\n";
}
