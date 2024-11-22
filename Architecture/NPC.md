# Иерархия классов и их полей и функций

## Класс `NPC`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `typeId_`             | `NPCId`              | Идентификатор типа NPC                       |
| `currentId_`          | `unsigned int`       | Текущий идентификатор NPC                    |
| `hp_`                 | `double`             | Здоровье NPC                                 |
| `armor_`              | `double`             | Базовая броня NPC                            |
| `totalArmor_`         | `double`             | Общая броня NPC                              |
| `speed_`              | `double`             | Скорость NPC                                 |
| `equip_`              | `std::shared_ptr<MyEquip>` | Экипировка NPC                      |
| `GetTypeId()`         | `NPCId`              | Возвращает идентификатор типа NPC            |
| `GetCurrentId()`      | `unsigned int`       | Возвращает текущий идентификатор NPC         |
| `GetHp()`             | `double`             | Возвращает здоровье NPC                      |
| `GetArmor()`          | `double`             | Возвращает базовую броню NPC                 |
| `GetSpeed()`          | `double`             | Возвращает скорость NPC                      |
| `GetAttackDistance()` | `double`             | Возвращает дистанцию атаки (виртуальный)      |
| `GetAttackDamage()`   | `double`             | Возвращает урон от атаки (виртуальный)       |
| `AcceptVisitor(std::shared_ptr<Visitor> visitor)` | `void` | Принимает посетителя (виртуальный) |
| `SetTypeId(NPCId typeId)` | `void` | Устанавливает идентификатор типа NPC |
| `SetCurrentId(unsigned int currentId)` | `void` | Устанавливает текущий идентификатор NPC |
| `SetHp(double hp)`    | `void`               | Устанавливает здоровье NPC                   |
| `SetBaseArmor(double armor)` | `void` | Устанавливает базовую броню NPC       |
| `SetEquip(std::shared_ptr<MyEquip> equip)` | `void` | Устанавливает экипировку NPC         |
| `SetSpeed(double speed)` | `void` | Устанавливает скорость NPC            |

## Класс `AgressiveNPC`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `attackDamage_`       | `double`             | Урон от атаки                                |
| `attackDistance_`     | `double`             | Дистанция атаки                              |
| `target_`             | `std::shared_ptr<NPC>` | Цель атаки                                  |
| `GetAttackDamage()`   | `double`             | Возвращает урон от атаки                     |
| `GetAttackDistance()` | `double`             | Возвращает дистанцию атаки                   |
| `GetTarget()`         | `std::shared_ptr<NPC>` | Возвращает цель атаки                       |
| `AcceptVisitor(std::shared_ptr<Visitor> visitor)` | `void` | Принимает посетителя                   |
| `SetAttackDamage(double attackDamage)` | `void` | Устанавливает урон от атаки          |
| `SetAttackDistance(double attackDistance)` | `void` | Устанавливает дистанцию атаки      |
| `SetTarget(std::shared_ptr<NPC> target)` | `void` | Устанавливает цель атаки            |

## Класс `PeacefulNPC`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `AcceptVisitor(std::shared_ptr<Visitor> visitor)` | `void` | Принимает посетителя (виртуальный) |

## Класс `Knight`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `Knight()`            | Конструктор          | Конструктор класса `Knight`                  |
| `AcceptVisitor(std::shared_ptr<Visitor> visitor)` | `void` | Принимает посетителя (финальный)    |

## Класс `Pegasus`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `Pegasus()`           | Конструктор          | Конструктор класса `Pegasus`                 |
| `AcceptVisitor(std::shared_ptr<Visitor> visitor)` | `void` | Принимает посетителя (финальный)    |

## Класс `Squirrel`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `Squirrel()`          | Конструктор          | Конструктор класса `Squirrel`                |
| `AcceptVisitor(std::shared_ptr<Visitor> visitor)` | `void` | Принимает посетителя (финальный)    |

## Класс `IAgressiveNPCBuilder`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `Reset()`             | `void`               | Сбрасывает билдер                             |
| `SetCurrentId(unsigned int currentId)` | `void` | Устанавливает текущий идентификатор NPC |
| `SetHp(double hp)`    | `void`               | Устанавливает здоровье NPC                   |
| `SetBaseArmor(double armor)` | `void` | Устанавливает базовую броню NPC       |
| `SetEquip(std::shared_ptr<MyEquip> equip)` | `void` | Устанавливает экипировку NPC         |
| `SetSpeed(double speed)` | `void` | Устанавливает скорость NPC            |
| `SetAttackDamage(double attackDamage)` | `void` | Устанавливает урон от атаки          |
| `SetAttackDistance(double attackDistance)` | `void` | Устанавливает дистанцию атаки      |

## Класс `IPeacefulNPCBuilder`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `Reset()`             | `void`               | Сбрасывает билдер                             |
| `SetCurrentId(unsigned int currentId)` | `void` | Устанавливает текущий идентификатор NPC |
| `SetHp(double hp)`    | `void`               | Устанавливает здоровье NPC                   |
| `SetBaseArmor(double armor)` | `void` | Устанавливает базовую броню NPC       |
| `SetEquip(std::shared_ptr<MyEquip> equip)` | `void` | Устанавливает экипировку NPC         |
| `SetSpeed(double speed)` | `void` | Устанавливает скорость NPC            |

## Класс `PeacefulNPCBuilder`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `Reset()`             | `void`               | Сбрасывает билдер                             |
| `SetCurrentId(unsigned int currentId)` | `void` | Устанавливает текущий идентификатор NPC |
| `SetHp(double hp)`    | `void`               | Устанавливает здоровье NPC                   |
| `SetBaseArmor(double armor)` | `void` | Устанавливает базовую броню NPC       |
| `SetEquip(std::shared_ptr<MyEquip> equip)` | `void` | Устанавливает экипировку NPC         |
| `SetSpeed(double speed)` | `void` | Устанавливает скорость NPC            |
| `GetResult()`         | `std::shared_ptr<PeacefulNPC>` | Возвращает результат билдера       |

## Класс `AgressiveNPCBuilder`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `Reset()`             | `void`               | Сбрасывает билдер                             |
| `SetCurrentId(unsigned int currentId)` | `void` | Устанавливает текущий идентификатор NPC |
| `SetHp(double hp)`    | `void`               | Устанавливает здоровье NPC                   |
| `SetBaseArmor(double armor)` | `void` | Устанавливает базовую броню NPC       |
| `SetEquip(std::shared_ptr<MyEquip> equip)` | `void` | Устанавливает экипировку NPC         |
| `SetSpeed(double speed)` | `void` | Устанавливает скорость NPC            |
| `SetAttackDamage(double attackDamage)` | `void` | Устанавливает урон от атаки          |
| `SetAttackDistance(double attackDistance)` | `void` | Устанавливает дистанцию атаки      |
| `GetResult()`         | `std::shared_ptr<AgressiveNPC>` | Возвращает результат билдера       |

## Класс `PegasusBuilder`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `Reset()`             | `void`               | Сбрасывает билдер                             |

## Класс `KnightBuilder`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `Reset()`             | `void`               | Сбрасывает билдер                             |

## Класс `SquirrelBuilder`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `Reset()`             | `void`               | Сбрасывает билдер                             |

## Класс `UsageNPCFactory`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `npcCount`            | `unsigned int`       | Счетчик NPC                                  |
| `equipFactory`        | `std::shared_ptr<StandartEquipmentFactoryRandom>` | Фабрика экипировки              |

## Класс `PeacefulNPCBuilderMain`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `BuildNPCPegasus(std::shared_ptr<PeacefulNPCBuilder> builder)` | `void` | Создает NPC Pegasus           |

## Класс `AgressiveNPCBuilderMain`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `BuildNPCKnight(std::shared_ptr<AgressiveNPCBuilder> builder)` | `void` | Создает NPC Knight             |
| `BuildNPCSquirrel(std::shared_ptr<AgressiveNPCBuilder> builder)` | `void` | Создает NPC Squirrel           |

## Класс `INPCFactory`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `CreateNPC(double xCord, double yCord)` | `std::shared_ptr<NPC>` | Создает NPC с заданными координатами |

## Класс `KnightFactory`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `CreateNPC(double xCord, double yCord)` | `std::shared_ptr<NPC>` | Создает Knight с заданными координатами |

## Класс `PegasusFactory`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `CreateNPC(double xCord, double yCord)` | `std::shared_ptr<NPC>` | Создает Pegasus с заданными координатами |

## Класс `SquirrelFactory`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `CreateNPC(double xCord, double yCord)` | `std::shared_ptr<NPC>` | Создает Squirrel с заданными координатами |

## Класс `AttackCommand`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `AttackCommand(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> target)` | Конструктор | Конструктор класса `AttackCommand` |
| `execute(std::function<void(const std::string&)> Notify)` | `void` | Выполняет команду атаки          |
| `CanAttack(std::shared_ptr<NPC> npc1, std::shared_ptr<NPC> npc2)` | `bool` | Проверяет возможность атаки      |
| `attacker_`           | `std::shared_ptr<NPC>` | Атакующий NPC                              |
| `target_`             | `std::shared_ptr<NPC>` | Цель атаки                                  |

## Класс `ICommand`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `~ICommand()`         | Деструктор           | Деструктор интерфейса команды                 |
| `execute(std::function<void(const std::string&)> Notify)` | `void` | Выполняет команду (виртуальный)    |

## Класс `MoveCommand`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `MoveCommand(std::shared_ptr<NPC> npc, double xDirection, double yDirection)` | Конструктор | Конструктор класса `MoveCommand` с направлением |
| `MoveCommand(std::shared_ptr<NPC> npc, std::shared_ptr<NPC> target)` | Конструктор | Конструктор класса `MoveCommand` с целью |
| `execute(std::function<void(const std::string&)> Notify)` | `void` | Выполняет команду движения        |
| `npc_`                | `std::shared_ptr<NPC>` | NPC, который двигается                       |
| `xDirection_`         | `double`             | Направление по оси X                         |
| `yDirection_`         | `double`             | Направление по оси Y                         |

## Класс `CommandExecuter`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `thr`                 | `std::thread`        | Поток для выполнения команд                  |
| `commandQueue`        | `std::queue<std::shared_ptr<ICommand>>` | Очередь команд                |
| `commandQueueMutex`   | `std::mutex`         | Мьютекс для синхронизации доступа к очереди команд |
| `commandQueueCV`      | `std::condition_variable` | Условная переменная для ожидания команд |
| `stopFlag`            | `std::atomic<bool>`  | Флаг для остановки потока выполнения команд   |
| `isThreadRunning`     | `bool`               | Флаг, указывающий, запущен ли поток выполнения команд |
| `CommandExecutionThread(std::function<void(const std::string&)> Notify)` | `void` | Функция потока для выполнения команд |

## Класс `ArmorEnum`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `KnightArmor`         | `int`                | Броня рыцаря                                 |
| `PegasusArmor`        | `int`                | Броня пегаса                                 |
| `SquirrelArmor`       | `int`                | Броня белки                                  |

## Класс `AttackDamageEnum`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `KnightAttackDamage`  | `int`                | Урон от атаки рыцаря                         |
| `SquirrelAttackDamage`| `int`                | Урон от атаки белки                          |

## Класс `AttackDistanceEnum`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `KnightAttackDistance`| `int`                | Дистанция атаки рыцаря                       |
| `SquirrelAttackDistance` | `int`              | Дистанция атаки белки                        |

## Класс `HpEnum`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `KnightHp`            | `int`                | Здоровье рыцаря                              |
| `PegasusHp`           | `int`                | Здоровье пегаса                              |
| `SquirrelHp`          | `int`                | Здоровье белки                               |

## Класс `SpeedEnum`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `KnightSpeed`         | `int`                | Скорость рыцаря                              |
| `PegasusSpeed`        | `int`                | Скорость пегаса                              |
| `SquirrelSpeed`       | `int`                | Скорость белки                               |

## Класс `TypeIdEnum`

| Поле/Функция          | Тип/Возвращаемый тип | Описание                                      |
|-----------------------|----------------------|-----------------------------------------------|
| `KnightId`            | `int`                | Идентификатор рыцаря                         |
| `PegasusId`           | `int`                | Идентификатор пегаса                         |
| `SquirrelId`          | `int`                | Идентификатор белки                          |