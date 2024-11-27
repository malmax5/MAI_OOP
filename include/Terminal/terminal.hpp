#pragma once

#include <iostream>
#include <memory>

#include "../Game/game.hpp"

#include "../NPC/Factory/factory_register.hpp"

using GameSettings::NPCId;

class Terminal
{
public:
    Terminal();
    ~Terminal();

    void CreateNewGame();
    void StartGame();
    void StopGame();
    void DeleteThisGame();

    void IncludeNPCByID(NPCId id, double xCord, double yCord);

    void LoadNPCToFile(std::string filePath);
    void ExportNPCFromFile(std::string filePath);

    void PrintObjects();

    void Help();

private:
    void TerminalUpdate();

    std::shared_ptr<Game> game_;
    FactoryRegister& factories_;

    std::shared_ptr<FileLogger> fileLogger;
    std::shared_ptr<ScreenLogger> screenLogger;

    static std::string loggerFilePath;
    static std::string npcFilePath;
};