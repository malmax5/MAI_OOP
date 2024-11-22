#pragma once

#include <cmath>

class Position
{
    friend class PegasusFactory;
    friend class KnightFactory;
    friend class SquirrelFactory;
    friend class MoveCommand;
public:
    double GetXCord();
    double GetYCord();

protected:
    void SetXCord(double xCord);
    void SetYCord(double yCord);
    void SetPosition(double xCord, double yCord);
    void Move(double xDirection, double yDirection, double speed);

private:
    double xCord_;
    double yCord_;
};