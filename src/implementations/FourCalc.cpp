#include <iostream>
#include "implementations/FourCalc.h"

void Four::setNumber (const std::vector<unsigned char>& digitsToSet)
{
    digits = digitsToSet;
    validateDigits();
}

std::vector<unsigned char> Four::getNumber() const
{
    return digits;
}

std::vector<unsigned char> Four::add(const Four& other) const
{
    std::vector<unsigned char> otherDigits = other.getNumber();
    std::vector<unsigned char> result;

    int sum = 0;
    size_t i = 0, j = 0;

    while (i < digits.size() || j < otherDigits.size() || sum)
    {
        if (i < digits.size()) sum += digits[i++];
        if (j < otherDigits.size()) sum += otherDigits[j++];
        
        result.push_back(static_cast<unsigned char>(sum % 4));
        sum /= 4;
    }

    return result;
}

std::vector<unsigned char> Four::subtract(const Four& other) const
{
    if (other > *this)
        throw std::invalid_argument("Subtraction result would be negative");
    
    std::vector<unsigned char> otherDigits = other.getNumber();
    std::vector<unsigned char> result;

    int diff = 0;
    size_t i = 0, j = 0;

    while (i < digits.size() || j < otherDigits.size())
    {
        if (i < digits.size()) diff += digits[i++];
        if (j < otherDigits.size()) diff -= otherDigits[j++];

        if (diff < 0)
        {
            diff += 4;
            result.push_back(static_cast<unsigned char>(diff));
            diff = -1;
        }
        else
        {
            result.push_back(static_cast<unsigned char>(diff));
            diff = 0;
        }
    }

    while (result.size() > 1 && result.back() == 0)
    {
        result.pop_back();
    }

    return result;
}

void Four::validateDigits()
{
    for (unsigned char digit : digits)
    {
        if (digit > 3)
        {
            throw std::invalid_argument("Invalid digit in base-4 number");
        }
    }
}
