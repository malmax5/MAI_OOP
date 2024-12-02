#pragma once

#include <string>
#include <fstream>
#include <memory>
#include <cxxabi.h>

static const std::string fileName = "back_log.txt";

template<class TClass>
class CreateLog
{
public:
    std::string demangle(const char* name)
    {
        int status = -1;
        std::unique_ptr<char, void(*)(void*)> res
        {
            abi::__cxa_demangle(name, NULL, NULL, &status),
            std::free
        };
        return (status==0) ? res.get() : name ;
    }

protected:
    void LogCreate()
    {
        std::ofstream file(fileName, std::ios::app);
        if (file.is_open())
        {
            file << demangle(typeid(TClass).name()) << "\n";
        }
    }
};
