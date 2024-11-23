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

void Position::Move(double xDirection, double yDirection)
{
    double kNorm =sqrt(pow(xDirection, 2) + pow(yDirection, 2));
    double newX = xCord_ + (xDirection / kNorm) * speed_ * Time::GetDeltaTime();
    double newY = yCord_ + (yDirection / kNorm) * speed_ * Time::GetDeltaTime();
    SetPosition(newX, newY);
}

double Position::GetSpeed()
{
    return speed_;
}

void Position::SetSpeed(double speed)
{
    speed_ = speed;
}
