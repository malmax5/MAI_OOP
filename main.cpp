#include "include/NPC/Factory/knight_factory.hpp"

#include <iostream>

int main()
{
    KnightFactory factory;
    NPC* knight = factory.CreateNPC();
    knight = factory.CreateNPC();
    std::cout << knight->GetCurrentId();
}