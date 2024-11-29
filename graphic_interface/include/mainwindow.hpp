#pragma once

#include <memory>

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QDialog>

#include "gamefield.hpp"
#include "infodialog.hpp"

#include "../../include/Terminal/terminal.hpp"
#include "../../include/NPC/Base/npc.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void KnightAdded(std::shared_ptr<NPC> knight, int x, int y);
    void PegasusAdded(std::shared_ptr<NPC> pegasus, int x, int y);
    void SquirrelAdded(std::shared_ptr<NPC> squirrel, int x, int y);

private slots:
    void OnCreateGame();
    void OnStartGame();
    void OnStopGame();
    void OnDeleteGame();
    void OnIncludeKnight();
    void OnIncludePegasus();
    void OnIncludeSquirrel();
    void OnLoadNPCToFile();
    void OnExportNPCFromFile();
    void OnExit();
    void OnInfo();

private:
    QWidget *leftPanel_;
    QVBoxLayout *leftLayout_;
    QPushButton *createGameBtn_;
    QPushButton *startGameBtn_;
    QPushButton *stopGameBtn_;
    QPushButton *deleteGameBtn_;
    QPushButton *includeKnightBtn_;
    QPushButton *includePegasusBtn_;
    QPushButton *includeSquirrelBtn_;
    QPushButton *loadNPCToFileBtn_;
    QPushButton *exportNPCFromFileBtn_;
    QPushButton *exitBtn_;
    QPushButton *infoBtn_;
    QStackedWidget *stackedWidget_;
    QWidget *normalModePage_;
    QWidget *gameModePage_;
    GameField *gameField_;
    Terminal *terminal_;
};
