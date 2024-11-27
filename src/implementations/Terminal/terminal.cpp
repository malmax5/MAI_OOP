#include "../../../include/Terminal/terminal.hpp"

std::string Terminal::loggerFilePath = "log.txt";
std::string Terminal::npcFilePath = "npc.txt";

Terminal::Terminal() : factories_(FactoryRegister::GetInstance()),
                       fileLogger(std::make_shared<FileLogger>(loggerFilePath)),
                       screenLogger(std::make_shared<ScreenLogger>()),
                       game_(nullptr)
{
    std::srand(time(0));
    TerminalUpdate();
}

Terminal::~Terminal()
{
    if (game_)
    {
        DeleteThisGame();
    }
}

void Terminal::TerminalUpdate()
{
    //User interaction
    std::cout << "Print 10 to see a commands\n";

    int command = -1;
    double xCord, yCord;
    while(true)
    {
        std::cout << "Comand: ";
        std::cin >> command;
        
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            command = 10;
        }

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
            DeleteThisGame();
            break;
        case 4:
            std::cout << "X: ";
            std::cin >> xCord;
            std::cout << "Y: ";
            std::cin >> yCord;
            IncludeKnight(xCord, yCord);
            break;
        case 5:
            std::cout << "X: ";
            std::cin >> xCord;
            std::cout << "Y: ";
            std::cin >> yCord;
            IncludePegasus(xCord, yCord);
            break;
        case 6:
            std::cout << "X: ";
            std::cin >> xCord;
            std::cout << "Y: ";
            std::cin >> yCord;
            IncludeSquirrel(xCord, yCord);
            break;
        case 7:
            PrintObjects();
            break;
        case 8:
            ExportNPCFromFile(npcFilePath);
            break;
        case 9:
            LoadNPCToFile(npcFilePath);
            break;
        case 10:
            Help();
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
    game_->Attach(fileLogger);

    std::cout << "--Game created--\n";
}

void Terminal::StartGame()
{
    //Preparing before start
    if (!game_)
    {
        std::cout << "Need to create game before start\n";
        return;
    }

    // game_->Attach(screenLogger);
    game_->shouldStop_.store(false);
    game_->Start();

    std::cout << "--Game started--\n";
}

void Terminal::StopGame()
{
    //Preparing before stopping
    if (!game_)
    {
        std::cout << "Need to create game\n";
        return;
    }
    if (!game_->isThreadRunning)
    {
        std::cout << "Need to start game before stopping\n";
        return;
    }

    game_->shouldStop_.store(true);
    if (game_->gameThread.joinable())
    {
        game_->gameThread.join();
    }
    game_->isThreadRunning = false;

    // game_->Detach(screenLogger);

    std::cout << "--Game stopped--\n";
}

void Terminal::DeleteThisGame()
{
    if (!game_)
    {
        std::cout << "Need to create game\n";
        return;
    }

    StopGame();

    game_->Detach(fileLogger);
    game_ = nullptr;

    std::cout << "--Game deleted--\n";
}

void Terminal::IncludeKnight(double xCord, double yCord)
{
    if (!game_)
    {
        std::cout << "Need to create game\n";
        return;
    }
    if (game_->isThreadRunning)
    {
        std::cout << "Game in proccess can't add a knight\n";
        return;
    }

    game_->AddNPC(factories_.GetFactoryByNPCTypeId(KnightId)->CreateNPC(xCord, yCord));
    std::cout << "--Knight included--\n";
}

void Terminal::IncludePegasus(double xCord, double yCord)
{
    if (!game_)
    {
        std::cout << "Need to create game\n";
        return;
    }
    if (game_->isThreadRunning)
    {
        std::cout << "Game in proccess can't add a pegasus\n";
        return;
    }

    game_->AddNPC(factories_.GetFactoryByNPCTypeId(PegasusId)->CreateNPC(xCord, yCord));
    std::cout << "--Pegasus included--\n";
}

void Terminal::IncludeSquirrel(double xCord, double yCord)
{
    if (!game_)
    {
        std::cout << "Need to create game\n";
        return;
    }
    if (game_->isThreadRunning)
    {
        std::cout << "Game in proccess can't add a squirrel\n";
        return;
    }

    game_->AddNPC(factories_.GetFactoryByNPCTypeId(SquirrelId)->CreateNPC(xCord, yCord));
    std::cout << "--Squirrel included--\n";
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

void Terminal::LoadNPCToFile(std::string filePath)
{
    if (!game_)
    {
        std::cout << "Need to create game\n";
        return;
    }

    std::ofstream file(filePath, std::ofstream::out | std::ofstream::trunc);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << filePath << "\n";
        return;
    }

    for (const auto& npc : game_->npcInGame_)
    {
        file << npc->GetTypeId() << " " << npc->GetXCord() << " " << npc->GetYCord() << "\n";
    }

    file.close();
    std::cout << "--Exported--\n";
}

void Terminal::ExportNPCFromFile(std::string filePath)
{
    if (!game_)
    {
        std::cout << "Need to create game\n";
        return;
    }

    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << filePath << "\n";
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
                std::cerr << "Error: Unknown NPC type ID " << typeId << "\n";
                break;
        }
    }

    file.close();
    std::cout << "--Loaded--\n";
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
