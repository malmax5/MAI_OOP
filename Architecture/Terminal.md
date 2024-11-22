# Иерархия классов и их полей и функций

## Класс `Terminal`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `Terminal()`          | Конструктор          | Конструктор класса `Terminal`.                 |
| `~Terminal()`         | Деструктор           | Деструктор класса `Terminal`.                  |
| `CreateNewGame()`     | `void`               | Создает новую игру.                            |
| `StartGame()`         | `void`               | Запускает игру.                                |
| `StopGame()`          | `void`               | Останавливает игру.                            |
| `DeleteThisGame()`    | `void`               | Удаляет текущую игру.                          |
| `IncludePegasus(double xCord, double yCord)` | `void` | Добавляет Пегаса в игру с заданными координатами. |
| `IncludeKnight(double xCord, double yCord)` | `void` | Добавляет Рыцаря в игру с заданными координатами. |
| `IncludeSquirrel(double xCord, double yCord)` | `void` | Добавляет Белку в игру с заданными координатами. |
| `LoadNPCToFile(std::string filePath)` | `void` | Загружает NPC в файл.                       |
| `ExportNPCFromFile(std::string filePath)` | `void` | Загружает NPC из файла.                       |
| `PrintObjects()`      | `void`               | Выводит информацию о объектах в игре.          |
| `Help()`              | `void`               | Выводит справку по командам.                   |
| `TerminalUpdate()`    | `void`               | Обновляет состояние терминала.                 |
| `game_`               | `std::shared_ptr<Game>` | Указатель на текущую игру.                    |
| `knightFactory_`      | `std::shared_ptr<KnightFactory>` | Указатель на фабрику Рыцарей.          |
| `pegasusFactory_`     | `std::shared_ptr<PegasusFactory>` | Указатель на фабрику Пегасов.           |
| `squirrelFactory_`    | `std::shared_ptr<SquirrelFactory>` | Указатель на фабрику Белки.            |
| `fileLogger`          | `std::shared_ptr<FileLogger>` | Указатель на логгер файлов.             |
| `screenLogger`        | `std::shared_ptr<ScreenLogger>` | Указатель на экранный логгер.           |
| `loggerFilePath`      | `static std::string` | Путь к файлу логгера.                          |
| `npcFilePath`         | `static std::string` | Путь к файлу NPC.                              |