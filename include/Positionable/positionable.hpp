#pragma once

#include <cmath>

#include "../Game/time.hpp"

class Position
{

public:
    double GetXCord();
    double GetYCord();
    double GetSpeed();
    void Move(double xDirection, double yDirection);
    void SetPosition(double xCord, double yCord);

protected:
    void SetXCord(double xCord);
    void SetYCord(double yCord);
    void SetSpeed(double speed);

private:
    double xCord_;
    double yCord_;
    double speed_;
};