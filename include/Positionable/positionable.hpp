#pragma once

class Position
{
    friend class PegasusFactory;
    friend class KnightFactory;
    friend class SquirrelFactory;
public:
    double GetXCord();
    double GetYCord();
    void Move(double speed, double xCordEnd, double yCordEnd);

protected:
    void SetXCord(double xCord);
    void SetYCord(double yCord);
    void SetPosition(double xCord, double yCord);

private:
    double xCord_;
    double yCord_;
};