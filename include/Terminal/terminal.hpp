#pragma once

#include <iostream>
#include <memory>

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

    void LoadNPCToFile(std::string filePath);
    void ExportNPCFromFile(std::string filePath);

    void PrintObjects();

private:
    void TerminalUpdate();

    std::shared_ptr<Game> game_;
    std::shared_ptr<KnightFactory> knightFactory_;
    std::shared_ptr<PegasusFactory> pegasusFactory_;
    std::shared_ptr<SquirrelFactory> squirrelFactory_;

    std::shared_ptr<FileLogger> fileLogger;
    std::shared_ptr<ScreenLogger> screenLogger;

    static std::string loggerFilePath;
    static std::string npcFilePath;
};