#pragma once

#include <string>
#include <fstream>

static const std::string fileName = "back_log.txt";

template<class TClass>
class CreateLog
{
public:
    void LogCreate()
    {
        std::ofstream file(fileName, std::ios::app);
        if (file.is_open())
        {
            file << typeid(TClass).name() << "\n";
        }
    }
};
