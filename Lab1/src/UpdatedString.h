#ifndef UPDATEDSTRING_H
#define UPDATEDSTRING_H

#include <string>
#include <iostream>

class UpdatedString {
public:
    UpdatedString();

    explicit UpdatedString(std::string str);

    explicit UpdatedString(const char* str);

    UpdatedString(const UpdatedString& uStr);

    UpdatedString& operator=(const UpdatedString& uStr);

    UpdatedString(UpdatedString&& uStr) noexcept;

    UpdatedString& operator=(UpdatedString&& uStr) noexcept;

    inline const std::string get() const {
        return str_;
    }

    inline void clear() {
        str_.clear();
    }

    inline void print() const {
        std::cout << str_ << "\n";
    }

    bool isPalindrom() const;

private:
    std::string str_;
};

#endif