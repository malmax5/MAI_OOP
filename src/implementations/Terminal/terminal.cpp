#include "../../../include/Terminal/terminal.hpp"

std::string Terminal::loggerFilePath = "log.txt";
std::string Terminal::npcFilePath = "npc.txt";

Terminal::Terminal() : knightFactory_(std::make_shared<KnightFactory>()),
                       pegasusFactory_(std::make_shared<PegasusFactory>()),
                       squirrelFactory_(std::make_shared<SquirrelFactory>())
{
    std::srand(time(0));
    TerminalUpdate();
}

void Terminal::TerminalUpdate()
{
    //User interaction
    int command = -1;
    double xCord, yCord;
    while(true)
    {
        std::cout << "Comand: ";
        std::cin >> command;
        switch (command)
        {
        case 0:
            CreateNewGame();
            break;
        case 1:
            StartGame();
            break;
        case 2:
            StopGame();
            break;
        case 3:
            std::cout << "X: ";
            std::cin >> xCord;
            std::cout << "Y: ";
            std::cin >> yCord;
            IncludeKnight(xCord, yCord);
            break;
        case 4:
            std::cout << "X: ";
            std::cin >> xCord;
            std::cout << "Y: ";
            std::cin >> yCord;
            IncludePegasus(xCord, yCord);
            break;
        case 5:
            std::cout << "X: ";
            std::cin >> xCord;
            std::cout << "Y: ";
            std::cin >> yCord;
            IncludeSquirrel(xCord, yCord);
            break;
        case 6:
            PrintObjects();
            break;
        case 7:
            ExportNPCFromFile(npcFilePath);
            break;
        case 8:
            LoadNPCToFile(npcFilePath);
            break;
        
        default:
            break;
        }

        if(command == 123)
            break;
        
    }
}

void Terminal::CreateNewGame()
{
    game_ = std::make_shared<Game>();
}

void Terminal::StartGame()
{
    //Preparing before start
    fileLogger = std::make_shared<FileLogger>(loggerFilePath);
    screenLogger = std::make_shared<ScreenLogger>();
    game_->Attach(fileLogger);
    game_->Attach(screenLogger);
    game_->Start();
}

void Terminal::StopGame()
{
    //Preparing before stopping
    game_->Detach(fileLogger);
    game_->Detach(screenLogger);
    game_->End();
}

void Terminal::IncludeKnight(double xCord, double yCord)
{
    game_->AddNPC(knightFactory_->CreateNPC(xCord, yCord));
}

void Terminal::IncludePegasus(double xCord, double yCord)
{
    game_->AddNPC(pegasusFactory_->CreateNPC(xCord, yCord));
}

void Terminal::IncludeSquirrel(double xCord, double yCord)
{
    game_->AddNPC(squirrelFactory_->CreateNPC(xCord, yCord));
}

void Terminal::PrintObjects()
{
    game_->PrintNPC();
}

void Terminal::LoadNPCToFile(std::string filePath)
{
    std::ofstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << filePath << std::endl;
        return;
    }

    for (const auto& npc : game_->npcInGame_)
    {
        file << npc->GetTypeId() << " " << npc->GetXCord() << " " << npc->GetYCord() << "\n";
    }

    file.close();
}

void Terminal::ExportNPCFromFile(std::string filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << filePath << std::endl;
        return;
    }

    int typeId;
    double xCord, yCord;
    while (file >> typeId >> xCord >> yCord)
    {
        switch (typeId) {
            case 0:
                IncludeKnight(xCord, yCord);
                break;
            case 1:
                IncludePegasus(xCord, yCord);
                break;
            case 2:
                IncludeSquirrel(xCord, yCord);
                break;
            default:
                std::cerr << "Error: Unknown NPC type ID " << typeId << std::endl;
                break;
        }
    }

    file.close();
}
