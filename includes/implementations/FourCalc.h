#ifndef FOURCALC_H
#define FOURCALC_H

#include "interfaces\IFour.h"
#include <vector>
#include <string>

class Four : public IFour<Four, unsigned char> {
public:
    explicit Four () : digits(0) {}

    explicit Four(const size_t& n, unsigned char a)
    {
        digits = std::vector<unsigned char>(n, a);
        validateDigits();
    }

    explicit Four (const std::initializer_list<unsigned char>& a) : digits(a) 
    {
        validateDigits();
    }

    explicit Four (const std::vector<unsigned char>& a) : digits(a) 
    {
        validateDigits();
    }

    explicit Four (const std::string& a)
    {
        digits.reserve(a.size());
        for (char c : a)
        {
            digits.push_back((unsigned char)(c - '0'));
        }
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
        std::vector<unsigned char> otherDigits = other.getNumber();

        if (digits.size() != otherDigits.size())
        {
            return digits.size() > otherDigits.size();
        }

        return digits > otherDigits;
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

    void setNumber(const std::vector<unsigned char>& digits) override;
    std::vector<unsigned char> getNumber() const override;

private:
    std::vector<unsigned char> add(const Four& other) const override;
    std::vector<unsigned char> subtract(const Four& other) const override;
    void validateDigits();

private:
    std::vector<unsigned char> digits;
};

#endif