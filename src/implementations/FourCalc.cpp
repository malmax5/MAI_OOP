#include <iostream>
#include "implementations/FourCalc.h"
#include "C:\Users\CrazyBlackFire\Documents\Code\oop\Lab2\includes\implementations\Vector.h"

void Four::setNumber (const Vector<unsigned char>& digitsToSet)
{
    digits = digitsToSet;
    validateDigits();
}

Vector<unsigned char> Four::getNumber() const
{
    return digits;
}

Vector<unsigned char> Four::add(const Four& other) const
{
    Vector<unsigned char> otherDigits = other.getNumber();
    Vector<unsigned char> result;

    int sum = 0;
    size_t i = 0, j = 0;

    while (i < digits.Size() || j < otherDigits.Size() || sum)
    {
        if (i < digits.Size()) sum += digits[i++];
        if (j < otherDigits.Size()) sum += otherDigits[j++];
        
        result.PushBack(static_cast<unsigned char>(sum % 4));
        sum /= 4;
    }

    return result;
}

Vector<unsigned char> Four::subtract(const Four& other) const
{
    if (other > *this)
        throw std::invalid_argument("Subtraction result would be negative");
    
    Vector<unsigned char> otherDigits = other.getNumber();
    Vector<unsigned char> result;

    int diff = 0;
    size_t i = 0, j = 0;

    while (i < digits.Size() || j < otherDigits.Size())
    {
        if (i < digits.Size()) diff += digits[i++];
        if (j < otherDigits.Size()) diff -= otherDigits[j++];

        if (diff < 0)
        {
            diff += 4;
            result.PushBack(static_cast<unsigned char>(diff));
            diff = -1;
        }
        else
        {
            result.PushBack(static_cast<unsigned char>(diff));
            diff = 0;
        }
    }

    while (result.Size() > 1 && result.Back() == 0)
    {
        result.PopBack();
    }

    return result;
}

void Four::validateDigits()
{
    for (size_t i = 0; i < digits.Size(); i++)
    {
        if (digits[i] > 3)
        {
            throw std::invalid_argument("Invalid digit in base-4 number");
        }
    }
}
