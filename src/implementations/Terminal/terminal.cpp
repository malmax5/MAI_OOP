#include "../../../include/Terminal/terminal.hpp"

Terminal::Terminal() : knightFactory_(new KnightFactory),
                       pegasusFactory_(new PegasusFactory),
                       squirrelFactory_(new SquirrelFactory)
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
        
        default:
            break;
        }

        if(command == 123)
            break;
    }
}

void Terminal::CreateNewGame()
{
    game_ = new Game;
}

void Terminal::StartGame()
{
    //Preparing before start
    game_->Start();
}

void Terminal::StopGame()
{
    //Preparing before stopping
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
