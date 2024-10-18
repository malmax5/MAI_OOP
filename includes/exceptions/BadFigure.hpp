#ifndef BADFIGURE_HPP
#define BADFIGURE_HPP

#include <iostream>
#include <exception>
#include <string>

class BadFigure : public std::exception
{
public:
    BadFigure(const std::string& message): message(message) {}

    const char* what() const noexcept override
    {
        return message.c_str();
    }

private:
    std::string message;
};

#endif