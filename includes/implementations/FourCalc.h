#ifndef FOURCALC_H
#define FOURCALC_H

#include "interfaces\IFour.h"
#include "implementations\Vector.h"
#include <string>

class Four : public IFour<Four, unsigned char> {
public:
    explicit Four () : digits(0) {}

    explicit Four(const size_t& n, unsigned char a)
    {
        digits = Vector<unsigned char>(n, a);
        validateDigits();
    }

    Four(const std::initializer_list<unsigned char>& a)
    {
        for (size_t i = a.size(); i > 0; i--)
            digits.PushBack(*(a.begin() + (i - 1)));
        validateDigits();
    }

    explicit Four (const Vector<unsigned char>& a)
    {
        for (size_t i = 0; i < a.Size(); i++)
            digits.PushBack(a[i]);
        validateDigits();
    }

    explicit Four(const std::string& a)
    {
        for (size_t i = a.size(); i > 0; i--)
            digits.PushBack(a[i - 1] - '0');
        validateDigits();
    }

    ~Four () {}

    Four (const Four& other) : digits(other.digits) {}

    Four& operator=(const Four& other) override
    {
        if (this != &other)
        {
            digits = other.getNumber();
        }

        return *this;
    }

    Four (Four&& other) noexcept : digits(std::move(other.digits)) {}

    Four& operator=(Four&& other) noexcept override
    {
        if (this != &other)
        {
            digits = std::move(other.digits);
        }
        return *this;
    }

    Four operator+(const Four& other) const override
    {
        return Four(add(other));
    }

    Four operator-(const Four& other) const override
    {
        return Four(subtract(other));
    }

    bool operator>(const Four& other) const override
    {
        Vector<unsigned char> otherDigits = other.getNumber();

        if (digits.Size() != otherDigits.Size())
        {
            return digits.Size() > otherDigits.Size();
        }

        for (size_t i = digits.Size(); i > 0; --i)
        {
            if (digits[i - 1] > otherDigits[i - 1])
            {
                return true;
            }
            else if (digits[i - 1] < otherDigits[i - 1])
            {
                return false;
            }
        }

        return false;
    }

    bool operator<(const Four& other) const override
    {
        return !(*this > other);
    }

    bool operator==(const Four& other) const override
    {
        return digits == other.getNumber();
    }

    Four& operator+=(const Four& other) override
    {
        *this = *this + other;

        return *this;
    }

    Four& operator-=(const Four& other) override
    {
        *this = *this - other;

        return *this; 
    }

    friend std::ostream& operator<<(std::ostream& os, const Four& four);

    void setNumber(const Vector<unsigned char>& digits) override;
    Vector<unsigned char> getNumber() const override;

private:
    Vector<unsigned char> add(const Four& other) const override;
    Vector<unsigned char> subtract(const Four& other) const override;
    void validateDigits();

private:
    Vector<unsigned char> digits;
};

#endif