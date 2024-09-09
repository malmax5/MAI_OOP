#include "UpdatedString.h"

UpdatedString::UpdatedString() : str_() {};
UpdatedString::UpdatedString(std::string str) : str_(str) {}
UpdatedString::UpdatedString(const char* str) : str_(str) {}

UpdatedString& UpdatedString::operator=(const UpdatedString& uStr)
{
    if (this != &uStr)
        str_ = uStr.get();
    
    return *this;
}

UpdatedString::UpdatedString(const UpdatedString& uStr) : str_(uStr.get()) {};

UpdatedString& UpdatedString::operator=(UpdatedString&& uStr) noexcept
{
    if (this != &uStr)
    {
        str_ = std::move(uStr.get());
        uStr.clear();
    }
    
    return *this;
}

UpdatedString::UpdatedString(UpdatedString&& uStr) noexcept : str_(std::move(uStr.get()))
{
    uStr.clear();
}

bool UpdatedString::isPalindrom() const
{
    size_t len = str_.size();
    for (size_t i = 0; i < len / 2; i++)
    {
        if (str_[i] != str_[len - i - 1])
            return false;
    }
    return true;
}