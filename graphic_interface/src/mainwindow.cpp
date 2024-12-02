#include "../include/mainwindow.hpp"
#include "../include/coordinatedialog.hpp"
#include "../include/filedialog.hpp"
#include "../include/infodialog.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), terminal_(new Terminal)
{
    stackedWidget_ = new QStackedWidget(this);

    normalModePage_ = new QWidget;
    QVBoxLayout *normalLayout = new QVBoxLayout;

    leftPanel_ = new QWidget;
    leftLayout_ = new QVBoxLayout(leftPanel_);

    createGameBtn_ = new QPushButton("Create game");
    startGameBtn_ = new QPushButton("Start game");
    deleteGameBtn_ = new QPushButton("Delete game");
    includeKnightBtn_ = new QPushButton("Include knight");
    includePegasusBtn_ = new QPushButton("Include pegasus");
    includeSquirrelBtn_ = new QPushButton("Include squirrel");
    loadNPCToFileBtn_ = new QPushButton("Export NPC to file");
    exportNPCFromFileBtn_ = new QPushButton("Load NPC from file");
    randomBtn_ = new QPushButton("Random filling");
    infoBtn_ = new QPushButton("Info");
    exitBtn_ = new QPushButton("Exit");

    int maxButtonHeight = 100;
    int maxButtonWidth = 500;
    QSize buttonSize(maxButtonWidth, maxButtonHeight);
    createGameBtn_->setMaximumSize(buttonSize);
    startGameBtn_->setMaximumSize(buttonSize);
    deleteGameBtn_->setMaximumSize(buttonSize);
    includeKnightBtn_->setMaximumSize(buttonSize);
    includePegasusBtn_->setMaximumSize(buttonSize);
    includeSquirrelBtn_->setMaximumSize(buttonSize);
    loadNPCToFileBtn_->setMaximumSize(buttonSize);
    exportNPCFromFileBtn_->setMaximumSize(buttonSize);
    randomBtn_->setMaximumSize(buttonSize);
    infoBtn_->setMaximumSize(buttonSize);
    exitBtn_->setMaximumSize(buttonSize);

    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(createGameBtn_->sizePolicy().hasHeightForWidth());
    createGameBtn_->setSizePolicy(sizePolicy);
    startGameBtn_->setSizePolicy(sizePolicy);
    deleteGameBtn_->setSizePolicy(sizePolicy);
    includeKnightBtn_->setSizePolicy(sizePolicy);
    includePegasusBtn_->setSizePolicy(sizePolicy);
    includeSquirrelBtn_->setSizePolicy(sizePolicy);
    loadNPCToFileBtn_->setSizePolicy(sizePolicy);
    exportNPCFromFileBtn_->setSizePolicy(sizePolicy);
    randomBtn_->setSizePolicy(sizePolicy);
    infoBtn_->setSizePolicy(sizePolicy);
    exitBtn_->setSizePolicy(sizePolicy);

    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(createGameBtn_);
    buttonLayout->addWidget(startGameBtn_);
    buttonLayout->addWidget(deleteGameBtn_);
    buttonLayout->addWidget(includeKnightBtn_);
    buttonLayout->addWidget(includePegasusBtn_);
    buttonLayout->addWidget(includeSquirrelBtn_);
    buttonLayout->addWidget(loadNPCToFileBtn_);
    buttonLayout->addWidget(exportNPCFromFileBtn_);
    buttonLayout->addWidget(randomBtn_);
    buttonLayout->addWidget(infoBtn_);
    buttonLayout->addWidget(exitBtn_);

    QHBoxLayout *centerLayout = new QHBoxLayout;
    centerLayout->addStretch();
    centerLayout->addLayout(buttonLayout);
    centerLayout->addStretch();

    leftLayout_->addLayout(centerLayout);

    gameField_ = new GameField(this);

    QHBoxLayout *normalHBoxLayout = new QHBoxLayout;
    normalHBoxLayout->addWidget(leftPanel_);
    normalHBoxLayout->addWidget(gameField_);
    normalLayout->addLayout(normalHBoxLayout);
    normalModePage_->setLayout(normalLayout);

    gameModePage_ = new QWidget;
    QVBoxLayout *gameLayout = new QVBoxLayout;
    gameLayout->addWidget(gameField_);
    stopGameBtn_ = new QPushButton("StopGame");
    gameLayout->addWidget(stopGameBtn_);
    gameModePage_->setLayout(gameLayout);

    stackedWidget_->addWidget(normalModePage_);
    stackedWidget_->addWidget(gameModePage_);

    setCentralWidget(stackedWidget_);

    connect(createGameBtn_, &QPushButton::clicked, this, &MainWindow::OnCreateGame);
    connect(startGameBtn_, &QPushButton::clicked, this, &MainWindow::OnStartGame);
    connect(stopGameBtn_, &QPushButton::clicked, this, &MainWindow::OnStopGame);
    connect(deleteGameBtn_, &QPushButton::clicked, this, &MainWindow::OnDeleteGame);
    connect(includeKnightBtn_, &QPushButton::clicked, this, &MainWindow::OnIncludeKnight);
    connect(includePegasusBtn_, &QPushButton::clicked, this, &MainWindow::OnIncludePegasus);
    connect(includeSquirrelBtn_, &QPushButton::clicked, this, &MainWindow::OnIncludeSquirrel);
    connect(loadNPCToFileBtn_, &QPushButton::clicked, this, &MainWindow::OnLoadNPCToFile);
    connect(exportNPCFromFileBtn_, &QPushButton::clicked, this, &MainWindow::OnExportNPCFromFile);
    connect(randomBtn_, &QPushButton::clicked, this, &MainWindow::OnRandom);
    connect(exitBtn_, &QPushButton::clicked, this, &MainWindow::OnExit);
    connect(infoBtn_, &QPushButton::clicked, this, &MainWindow::OnInfo);

    connect(this, &MainWindow::KnightAdded, gameField_, &GameField::AddKnightPoint);
    connect(this, &MainWindow::PegasusAdded, gameField_, &GameField::AddPegasusPoint);
    connect(this, &MainWindow::SquirrelAdded, gameField_, &GameField::AddSquirrelPoint);

    createGameBtn_->setEnabled(true);
    startGameBtn_->setEnabled(false);
    deleteGameBtn_->setEnabled(false);
    includeKnightBtn_->setEnabled(false);
    includePegasusBtn_->setEnabled(false);
    includeSquirrelBtn_->setEnabled(false);
    exportNPCFromFileBtn_->setEnabled(false);
    loadNPCToFileBtn_->setEnabled(false);
    randomBtn_->setEnabled(false);
    infoBtn_->setEnabled(true);
    exitBtn_->setEnabled(true);
    stopGameBtn_->setEnabled(false);
}

void MainWindow::OnCreateGame()
{
    if(terminal_->CreateNewGame())
    {
        QMessageBox::information(this, "Information", "New game created successfully.");
    }
    else
    {
        QMessageBox::information(this, "Information", "New game doesn't created.");
    }

    createGameBtn_->setEnabled(false);
    startGameBtn_->setEnabled(true);
    deleteGameBtn_->setEnabled(true);
    includeKnightBtn_->setEnabled(true);
    includePegasusBtn_->setEnabled(true);
    includeSquirrelBtn_->setEnabled(true);
    exportNPCFromFileBtn_->setEnabled(true);
    loadNPCToFileBtn_->setEnabled(true);
    randomBtn_->setEnabled(true);
    infoBtn_->setEnabled(true);
    exitBtn_->setEnabled(true);
    stopGameBtn_->setEnabled(false);
}

MainWindow::~MainWindow()
{
    terminal_->DeleteThisGame();
    delete terminal_;
}

void MainWindow::OnStartGame()
{
    if(!terminal_->StartGame())
    {
        QMessageBox::information(this, "Information", "Can't start the game.");
    }

    stackedWidget_->setCurrentIndex(1);
    createGameBtn_->setEnabled(false);
    startGameBtn_->setEnabled(false);
    deleteGameBtn_->setEnabled(false);
    includeKnightBtn_->setEnabled(false);
    includePegasusBtn_->setEnabled(false);
    includeSquirrelBtn_->setEnabled(false);
    exportNPCFromFileBtn_->setEnabled(false);
    loadNPCToFileBtn_->setEnabled(false);
    randomBtn_->setEnabled(false);
    infoBtn_->setEnabled(false);
    exitBtn_->setEnabled(false);
    stopGameBtn_->setEnabled(true);
}

void MainWindow::OnStopGame()
{
    if(!terminal_->StopGame())
    {
        QMessageBox::information(this, "Information", "Can't stop the game.");
    }

    stackedWidget_->setCurrentIndex(0);
    createGameBtn_->setEnabled(false);
    startGameBtn_->setEnabled(true);
    deleteGameBtn_->setEnabled(true);
    includeKnightBtn_->setEnabled(true);
    includePegasusBtn_->setEnabled(true);
    includeSquirrelBtn_->setEnabled(true);
    exportNPCFromFileBtn_->setEnabled(true);
    loadNPCToFileBtn_->setEnabled(true);
    randomBtn_->setEnabled(true);
    infoBtn_->setEnabled(true);
    exitBtn_->setEnabled(true);
    stopGameBtn_->setEnabled(false);
}

void MainWindow::OnDeleteGame()
{
    if(terminal_->DeleteThisGame())
    {
        QMessageBox::information(this, "Information", "Game deleted successfully.");
    }
    else
    {
        QMessageBox::information(this, "Information", "Game doesn't deleted.");
    }

    gameField_->ClearNPC();
    createGameBtn_->setEnabled(true);
    startGameBtn_->setEnabled(false);
    deleteGameBtn_->setEnabled(false);
    includeKnightBtn_->setEnabled(false);
    includePegasusBtn_->setEnabled(false);
    includeSquirrelBtn_->setEnabled(false);
    exportNPCFromFileBtn_->setEnabled(false);
    loadNPCToFileBtn_->setEnabled(false);
    randomBtn_->setEnabled(false);
    infoBtn_->setEnabled(true);
    exitBtn_->setEnabled(true);
    stopGameBtn_->setEnabled(false);
}

void MainWindow::OnIncludeKnight()
{
    CoordinateDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        double x = dialog.GetX();
        double y = dialog.GetY();
        std::shared_ptr<NPC> knight = terminal_->IncludeNPCByID(NPCId::KnightId, x, y);
        if (knight)
        {
            emit KnightAdded(knight, x, y);
        }
        else
        {
            QMessageBox::warning(this, "Warning", "Failed to add Knight.");
        }
    }
}

void MainWindow::OnIncludePegasus()
{
    CoordinateDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        double x = dialog.GetX();
        double y = dialog.GetY();
        std::shared_ptr<NPC> pegasus = terminal_->IncludeNPCByID(NPCId::PegasusId, x, y);
        if (pegasus)
        {
            emit PegasusAdded(pegasus, x, y);
        }
        else
        {
            QMessageBox::warning(this, "Warning", "Failed to add Pegasus.");
        }
    }
}

void MainWindow::OnIncludeSquirrel()
{
    CoordinateDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        double x = dialog.GetX();
        double y = dialog.GetY();
        std::shared_ptr<NPC> squirrel = terminal_->IncludeNPCByID(NPCId::SquirrelId, x, y);
        if (squirrel)
        {
            emit SquirrelAdded(squirrel, x, y);
        }
        else
        {
            QMessageBox::warning(this, "Warning", "Failed to add Squirrel.");
        }
    }
}

void MainWindow::OnLoadNPCToFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Export NPCs to file");
    if (!filePath.isEmpty()) 
    {
        try 
        {
            if(!terminal_->LoadNPCToFile(filePath.toStdString()))
            {
                QMessageBox::warning(this, "Warning", "Can't to export npc in this file.");
            }
        }
        catch (const std::exception& e)
        {
            QMessageBox::critical(this, "Error", e.what());
        }
    }
}

void MainWindow::OnExportNPCFromFile()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Load NPCs from file");
    if (!filePath.isEmpty())
    {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::critical(this, "Error", "Could not open file for reading.");
            return;
        }

        QString errorMsg;
        int lineNumber = 1;
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parts = line.split(" ");
            if (parts.size() == 3)
            {
                NPCId id = static_cast<NPCId>(parts[0].toInt());
                double x = parts[1].toDouble();
                double y = parts[2].toDouble();

                std::shared_ptr<NPC> npc = terminal_->IncludeNPCByID(id, x, y);

                if (npc)
                {
                    switch (id)
                    {
                    case NPCId::KnightId:
                        emit KnightAdded(npc, x, y);
                        break;
                    case NPCId::PegasusId:
                        emit PegasusAdded(npc, x, y);
                        break;
                    case NPCId::SquirrelId:
                        emit SquirrelAdded(npc, x, y);
                        break;
                    default:
                        break;
                    }
                }
                else
                {
                    errorMsg += "Failed to include NPC on line " + QString::number(lineNumber) + ".\n";
                }
            }
            else
            {
                errorMsg += "Invalid format on line " + QString::number(lineNumber) + ".\n";
            }
            lineNumber++;
        }
        file.close();

        if (!errorMsg.isEmpty())
        {
            QMessageBox::warning(this, "Warnings", errorMsg);
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Empty file.");
    }
}

void MainWindow::OnRandom()
{
    for (int i = 0; i < 10; i++)
    {
        NPCId randNPC = static_cast<NPCId>(std::rand() % (2 - 0 + 1) + 0);
        double xCord = static_cast<double>(std::rand() % (int)(GameFieldSettings::xMax - GameFieldSettings::xMin + 1) + (int)GameFieldSettings::xMin);
        double yCord = static_cast<double>(std::rand() % (int)(GameFieldSettings::yMax - GameFieldSettings::yMin + 1) + (int)GameFieldSettings::yMin);

        std::shared_ptr<NPC> npcToAdd = terminal_->IncludeNPCByID(randNPC, xCord, yCord);
        if (npcToAdd)
        {
            switch (randNPC)
            {
            case NPCId::KnightId:
                emit KnightAdded(npcToAdd, xCord, yCord);
                break;
            case NPCId::PegasusId:
                emit PegasusAdded(npcToAdd, xCord, yCord);
                break;
            case NPCId::SquirrelId:
                emit SquirrelAdded(npcToAdd, xCord, yCord);
                break;

            default:
                break;
            }
        }
    }

}

void MainWindow::OnExit()
{
    terminal_->StopGame();
    close();
}

void MainWindow::OnInfo()
{
    InfoDialog dialog(this);
    dialog.exec();
}
