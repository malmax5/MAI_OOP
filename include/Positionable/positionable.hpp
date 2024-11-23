#pragma once

#include <cmath>

#include "../Game/time.hpp"

class Position
{
    friend class PegasusFactory;
    friend class KnightFactory;
    friend class SquirrelFactory;
    //friend class MoveCommand;
public:
    double GetXCord();
    double GetYCord();
    double GetSpeed();
    void Move(double xDirection, double yDirection);

protected:
    void SetXCord(double xCord);
    void SetYCord(double yCord);
    void SetSpeed(double speed);
    void SetPosition(double xCord, double yCord);

private:
    double xCord_;
    double yCord_;
    double speed_;
};