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

    createGameBtn_ = new QPushButton("CreateGame");
    startGameBtn_ = new QPushButton("StartGame");
    deleteGameBtn_ = new QPushButton("DeleteGame");
    includeKnightBtn_ = new QPushButton("IncludeKnight");
    includePegasusBtn_ = new QPushButton("IncludePegasus");
    includeSquirrelBtn_ = new QPushButton("IncludeSquirrel");
    loadNPCToFileBtn_ = new QPushButton("LoadNPCToFile");
    exportNPCFromFileBtn_ = new QPushButton("ExportNPCFromFile");
    exitBtn_ = new QPushButton("Exit");
    infoBtn_ = new QPushButton("Info");

    leftLayout_->addWidget(createGameBtn_);
    leftLayout_->addWidget(startGameBtn_);
    leftLayout_->addWidget(deleteGameBtn_);
    leftLayout_->addWidget(includeKnightBtn_);
    leftLayout_->addWidget(includePegasusBtn_);
    leftLayout_->addWidget(includeSquirrelBtn_);
    leftLayout_->addWidget(loadNPCToFileBtn_);
    leftLayout_->addWidget(exportNPCFromFileBtn_);
    leftLayout_->addWidget(exitBtn_);
    leftLayout_->addWidget(infoBtn_);

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
    connect(exitBtn_, &QPushButton::clicked, this, &MainWindow::OnExit);
    connect(infoBtn_, &QPushButton::clicked, this, &MainWindow::OnInfo);

    connect(this, &MainWindow::KnightAdded, gameField_, &GameField::AddKnightPoint);
    connect(this, &MainWindow::PegasusAdded, gameField_, &GameField::AddPegasusPoint);
    connect(this, &MainWindow::SquirrelAdded, gameField_, &GameField::AddSquirrelPoint);

    startGameBtn_->setEnabled(false);
    includeKnightBtn_->setEnabled(false);
    includePegasusBtn_->setEnabled(false);
    includeSquirrelBtn_->setEnabled(false);
    loadNPCToFileBtn_->setEnabled(false);
    stopGameBtn_->setEnabled(false);
}

void MainWindow::OnCreateGame()
{
    terminal_->CreateNewGame();
    startGameBtn_->setEnabled(true);
    includeKnightBtn_->setEnabled(true);
    includePegasusBtn_->setEnabled(true);
    includeSquirrelBtn_->setEnabled(true);
    loadNPCToFileBtn_->setEnabled(true);
}

MainWindow::~MainWindow()
{
    delete terminal_;
}

void MainWindow::OnStartGame()
{
    terminal_->StartGame();
    stackedWidget_->setCurrentIndex(1);
    createGameBtn_->setEnabled(false);
    deleteGameBtn_->setEnabled(false);
    stopGameBtn_->setEnabled(true);
}

void MainWindow::OnStopGame()
{
    terminal_->StopGame();
    stackedWidget_->setCurrentIndex(0);
    createGameBtn_->setEnabled(true);
    deleteGameBtn_->setEnabled(true);
    stopGameBtn_->setEnabled(false);
}

void MainWindow::OnDeleteGame()
{
    terminal_->DeleteThisGame();
    gameField_->ClearNPC();
    createGameBtn_->setEnabled(true);
    startGameBtn_->setEnabled(false);
    includeKnightBtn_->setEnabled(false);
    includePegasusBtn_->setEnabled(false);
    includeSquirrelBtn_->setEnabled(false);
    loadNPCToFileBtn_->setEnabled(false);
}

void MainWindow::OnIncludeKnight()
{
    CoordinateDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        double x = dialog.GetX();
        double y = dialog.GetY();
        std::shared_ptr<NPC> knight = terminal_->IncludeNPCByID(NPCId::KnightId, x, y);
        emit KnightAdded(knight, x, y);
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
        emit PegasusAdded(pegasus, x, y);
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
        emit SquirrelAdded(squirrel, x, y);
    }
}

void MainWindow::OnLoadNPCToFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Load NPCs from file");
    if (!filePath.isEmpty()) 
    {
        try 
        {
            terminal_->LoadNPCToFile(filePath.toStdString());
        }
        catch (const std::exception& e)
        {
            QMessageBox::critical(this, "Error", e.what());
        }
    }
}

void MainWindow::OnExportNPCFromFile()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Export NPCs to file");
    if (!filePath.isEmpty())
    {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::critical(this, "Error", "Could not open file for reading.");
            return;
        }

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
            }
        }

        file.close();
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
