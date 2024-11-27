#pragma once

class IAttackable
{
public:
    virtual double GetAttackDistance() const = 0;
    virtual double GetAttackDamage() const = 0;
    virtual bool ReadyToAttack() const = 0;
    virtual void Reload() = 0;
protected:
    virtual void SetAttackDamage(double attackDamage) = 0;
    virtual void SetAttackDistance(double attackDistance) = 0;
};