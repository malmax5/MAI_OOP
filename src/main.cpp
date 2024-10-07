#include <iostream>
#include <memory>
#include <vector>
#include <C:\Users\CrazyBlackFire\Documents\Code\oop\Lab3\includes\Trapezoid.hpp>
#include <C:\Users\CrazyBlackFire\Documents\Code\oop\Lab3\includes\Rectangle.hpp>
#include <C:\Users\CrazyBlackFire\Documents\Code\oop\Lab3\includes\Square.hpp>
#include <C:\Users\CrazyBlackFire\Documents\Code\oop\Lab3\includes\Figure.hpp>
// #include <C:\Users\CrazyBlackFire\Documents\Code\oop\Lab3\includes\Rectangle.hpp>

int main()
{
    Point<double> topLeft(0, 0);
    Point<double> topRight(1, 1);
    Point<double> downRight(2, 1);
    Point<double> downLeft(3, 0);

    Trapezoid<double> trap(topLeft, topRight, downRight, downLeft);
    Point<double> centroid = trap.CalculateCentroid();

    std::cout << centroid;

    // Trapezoid<double> trap;
    // Square<double> sq;
    // Rectangle<double> re;
    // std::cin >> trap >> sq >> re;
    // std::cout << "Trapezoid: " << trap << "\nSquare: " << sq << "\nRectangle: " << re << "\n";
    // std::cout << "Trapezoid: " << (double)trap << "\nSquare: " << (double)sq << "\nRectangle: " << (double)re << "\n";
    // std::cout << "Trapezoid: " << trap.CalculateCentroid() << "\nSquare: " << sq.CalculateCentroid() << "\nRectangle: " << re.CalculateCentroid() << "\n";

    // std::vector<Figure<double>*> figures;
    // figures.push_back(&trap);
    // figures.push_back(&sq);
    // figures.push_back(&re);
    // std::cout << "\n";
    // for (int i = 0; i < figures.size(); i++)
    //     std::cout << (*figures[i]) << "\n";
    
    // for (int i = 0; i < figures.size(); i++)
    //     std::cout << figures[i]->CalculateArea() << "\n";
    
    // for (int i = 0; i < figures.size(); i++)
    //     std::cout << figures[i]->CalculateCentroid() << "\n";
}