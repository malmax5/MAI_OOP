# Иерархия классов и их полей и функций

## Класс `Position`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `xCord_`              | `double`             | Координата X                                  |
| `yCord_`              | `double`             | Координата Y                                  |
| `GetXCord()`          | `double`             | Возвращает координату X                       |
| `GetYCord()`          | `double`             | Возвращает координату Y                       |
| `SetXCord(double xCord)` | `void` | Устанавливает координату X              |
| `SetYCord(double yCord)` | `void` | Устанавливает координату Y              |
| `SetPosition(double xCord, double yCord)` | `void` | Устанавливает координаты X и Y         |
`Friend classes`: `PegasusFactory`, `KnightFactory`, `SquirrelFactory`, `MoveCommand`

## Класс `NPCPositionFuncs`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `DistanceBetNPC(std::shared_ptr<NPC> npc1, std::shared_ptr<NPC> npc2)` | `double` | Вычисляет расстояние между двумя NPC |
