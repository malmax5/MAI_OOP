#include<iostream>
#include<string>
#include<vector>
#include "implementations\FourCalc.h"

int main()
{
    std::string ee = "100";
    std::string eee = "333";
    Four four1(ee);
    Four four2(eee);
    // four1 += four2;
    Four four3(3, 3);
    four3 -= four1;
    std::vector<unsigned char> res = four3.getNumber();
    for (size_t i = 0; i < res.size(); i++)
    {
        std::cout << (int)res[i] << " ";
    }
}