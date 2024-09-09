#include "UpdatedString.h"

class UpdatedString
{
public:
    UpdatedString() : str_() {};
    explicit UpdatedString(std::string str) : str_(str) {}
    explicit UpdatedString(const char* str) : str_(str) {}

    UpdatedString& operator=(const UpdatedString& uStr)
    {
        if (this != &uStr)
            str_ = uStr.get();
        
        return *this;
    }

    UpdatedString(const UpdatedString& uStr) : str_(uStr.get()) {};

    UpdatedString& operator=(UpdatedString&& uStr) noexcept
    {
        if (this != &uStr)
        {
            str_ = std::move(uStr.get());
            uStr.clear();
        }
        
        return *this;
    }

    UpdatedString(UpdatedString&& uStr) noexcept : str_(std::move(uStr.get()))
    {
        uStr.clear();
    }

    inline const std::string get() const
    {
        return str_;
    }

    inline void clear()
    {
        str_.clear();
    }

    inline void print() const
    {
        std::cout << str_ << "\n";
    }

    bool isPalindrom() const
    {
        size_t len = str_.size();
        for (int i = 0; i < len / 2; i++)
        {
            if (str_[i] != str_[len - i - 1])
                return false;
        }
        return true;
    }

private:
    std::string str_;
};