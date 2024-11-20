#pragma once

#include <iostream>

#include "../Game/game.hpp"

#include "../NPC/Factory/knight_factory.hpp"
#include "../NPC/Factory/pegasus_factory.hpp"
#include "../NPC/Factory/squirrel_factory.hpp"

class Terminal
{
public:
    Terminal();

    void CreateNewGame();
    void StartGame();
    void StopGame();

    void IncludePegasus(double xCord, double yCord);
    void IncludeKnight(double xCord, double yCord);
    void IncludeSquirrel(double xCord, double yCord);

    void PrintObjects();

private:
    void TerminalUpdate();

    Game* game_;
    KnightFactory* knightFactory_;
    PegasusFactory* pegasusFactory_;
    SquirrelFactory* squirrelFactory_;
};