#include<iostream>
#include<string>
#include "implementations\FourCalc.h"
#include "C:\Users\CrazyBlackFire\Documents\Code\oop\Lab2\includes\implementations\Vector.h"

int main()
{
    Four four1({2, 3, 3});
    Four four2({1, 1, 1});

    Four result = four1 - four2;
    std::cout << result;
}