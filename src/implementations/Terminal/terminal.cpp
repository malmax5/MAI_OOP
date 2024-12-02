#include "../../../include/Terminal/terminal.hpp"

std::string Terminal::loggerFilePath = "log.txt";
std::string Terminal::npcFilePath = "npc.txt";

Terminal::Terminal() : factories_(FactoryRegister::GetInstance()),
                       fileLogger(std::make_shared<FileLogger>(loggerFilePath)),
                       screenLogger(std::make_shared<ScreenLogger>()),
                       game_(nullptr)
{
    std::srand(time(0));
    // TerminalUpdate();
}

Terminal::~Terminal()
{
    if (game_)
    {
        DeleteThisGame();
    }
}

// void Terminal::TerminalUpdate()
// {
//     //User interaction
//     std::cout << "Print 10 to see a commands\n";

//     int command = -1;
//     double xCord, yCord;
//     while(true)
//     {
//         std::cout << "Comand: ";
//         std::cin >> command;
        
//         if (std::cin.fail())
//         {
//             std::cin.clear();
//             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//             command = 10;
//         }

//         switch (command)
//         {
//         case 0:
//             CreateNewGame();
//             break;
//         case 1:
//             StartGame();
//             break;
//         case 2:
//             StopGame();
//             break;
//         case 3:
//             DeleteThisGame();
//             break;
//         case 4:
//             std::cout << "X: ";
//             std::cin >> xCord;
//             std::cout << "Y: ";
//             std::cin >> yCord;
//             IncludeNPCByID(NPCId::KnightId, xCord, yCord);
//             break;
//         case 5:
//             std::cout << "X: ";
//             std::cin >> xCord;
//             std::cout << "Y: ";
//             std::cin >> yCord;
//             IncludeNPCByID(NPCId::PegasusId, xCord, yCord);
//             break;
//         case 6:
//             std::cout << "X: ";
//             std::cin >> xCord;
//             std::cout << "Y: ";
//             std::cin >> yCord;
//             IncludeNPCByID(NPCId::SquirrelId, xCord, yCord);
//             break;
//         case 7:
//             PrintObjects();
//             break;
//         case 8:
//             ExportNPCFromFile(npcFilePath);
//             break;
//         case 9:
//             LoadNPCToFile(npcFilePath);
//             break;
//         case 10:
//             Help();
//             break;
        
//         default:
//             break;
//         }

//         if(command == 123)
//             break;
        
//     }
// }

int Terminal::CreateNewGame()
{
    if (game_)
    {
        std::cout << "Need to delete last game to start new game\n";
        return 0;
    }

    game_ = std::make_shared<Game>();
    game_->Attach(fileLogger);

    game_->Notify("!New Session!");

    std::cout << "--Game created--\n";
    return 1;
}

int Terminal::StartGame()
{
    //Preparing before start
    if (!game_)
    {
        std::cout << "Need to create game before start\n";
        return 0;
    }

    // game_->Attach(screenLogger);
    game_->shouldStop_.store(false);
    game_->Start();

    std::cout << "--Game started--\n";
    return 1;
}

int Terminal::StopGame()
{
    //Preparing before stopping
    if (!game_)
    {
        std::cout << "Need to create game\n";
        return 0;
    }
    if (!game_->isThreadRunning)
    {
        std::cout << "Need to start game before stopping\n";
        return 0;
    }

    game_->shouldStop_.store(true);
    if (game_->gameThread.joinable())
    {
        game_->gameThread.join();
    }
    game_->isThreadRunning = false;

    std::cout << "--Game stopped--\n";
    return 1;
}

int Terminal::DeleteThisGame()
{
    if (!game_)
    {
        std::cout << "Need to create game before deliting\n";
        return 0;
    }

    StopGame();
    game_->Detach(fileLogger);
    game_ = nullptr;

    std::cout << "--Game deleted--\n";
    return 1;
}

std::shared_ptr<NPC> Terminal::IncludeNPCByID(NPCId id, double xCord, double yCord)
{
    if (!game_)
    {
        std::cout << "Need to create game\n";
        return nullptr;
    }
    if (game_->isThreadRunning)
    {
        std::cout << "Game in proccess can't add a squirrel\n";
        return nullptr;
    }

    if (xCord > GameSettings::GameFieldSettings::xMax || xCord < GameSettings::GameFieldSettings::xMin ||
        yCord > GameSettings::GameFieldSettings::yMax || yCord < GameSettings::GameFieldSettings::yMin)
    {
        std::cout << "Can't add this npc, because of game field size\n";
        return nullptr;
    }

    std::shared_ptr<NPC> npcToAdd = factories_.GetFactoryByNPCTypeId(id)->CreateNPC(xCord, yCord);

    game_->AddNPC(npcToAdd);
    std::cout << "--" << npcToAdd->GetClassName() << " included--\n";

    return npcToAdd;
}

void Terminal::PrintObjects()
{
    if (!game_)
    {
        std::cout << "Need to create game\n";
        return;
    }

    game_->PrintNPC();
}

int Terminal::LoadNPCToFile(std::string filePath)
{
    if (!game_)
    {
        std::cout << "Need to create game\n";
        return 0;
    }

    std::ofstream file(filePath, std::ofstream::out | std::ofstream::trunc);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << filePath << "\n";
        return 0;
    }

    for (const auto& npc : game_->npcInGame_)
    {
        file << (int)npc->GetTypeId() << " " << npc->GetXCord() << " " << npc->GetYCord() << "\n";
    }

    file.close();
    std::cout << "--Exported--\n";
    return 1;
}

int Terminal::ExportNPCFromFile(std::string filePath)
{
    if (!game_)
    {
        std::cout << "Need to create game\n";
        return 0;
    }

    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cout << "Error: Unable to open file " << filePath << "\n";
        return 0;
    }

    int typeId;
    double xCord, yCord;
    while (file >> typeId >> xCord >> yCord)
    {
        try
        {
            IncludeNPCByID((NPCId)typeId, xCord, yCord);
        }
        catch(const std::exception& e)
        {
            std::cout << "Error: Unknown NPC type ID " << typeId << "\n";
        }
    }

    file.close();
    std::cout << "--Loaded--\n";
    return 1;
}

void Terminal::Help()
{
    std::cout << "0 - Create a new game\n" <<
                 "1 - Start the game\n" <<
                 "2 - Stop the game\n" <<
                 "3 - Delete the game\n" <<
                 "4 - Include knight in the game\n" <<
                 "5 - Include pegasus in the game\n" <<
                 "6 - Include squirrel in the game\n" <<
                 "7 - Print included npc\n" <<
                 "8 - Load npc from file\n" <<
                 "9 - Export npc in file\n" <<
                 "10 - Help\n";
}
