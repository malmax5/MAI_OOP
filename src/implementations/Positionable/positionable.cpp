#include "../../../include/Positionable/positionable.hpp"

double Position::GetXCord()
{
    return xCord_;
}

double Position::GetYCord()
{
    return yCord_;
}

void Position::SetXCord(double xCord)
{
    xCord_ = xCord;
}

void Position::SetYCord(double yCord)
{
    yCord_ = yCord;
}

void Position::SetPosition(double xCord, double yCord)
{
    xCord_ = xCord;
    yCord_ = yCord;
}
