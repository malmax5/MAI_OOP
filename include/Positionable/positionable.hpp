#pragma once

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

private:
    double xCord_;
    double yCord_;
};