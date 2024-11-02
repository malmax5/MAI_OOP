#include <gtest/gtest.h>
#include "../includes/figures/Trapezoid.hpp"
#include "../includes/figures/Rectangle.hpp"
#include "../includes/figures/Square.hpp"
#include "../includes/Array.hpp"

TEST(FigureTest, TotalAreaInt) {
    Array<Figure<int>> figures;
    figures.push_back(std::make_shared<Rectangle<int>>(Point<int>(0, 4), Point<int>(4, 4), Point<int>(4, 0), Point<int>(0, 0)));
    figures.push_back(std::make_shared<Square<int>>(Point<int>(0, 2), Point<int>(2, 2), Point<int>(2, 0), Point<int>(0, 0)));
    figures.push_back(std::make_shared<Trapezoid<int>>(Point<int>(0, 0), Point<int>(1, 1), Point<int>(2, 1), Point<int>(3, 0)));

    double totalArea = figures.totalArea();

    int expectedArea = 22;

    EXPECT_EQ(totalArea, expectedArea);
}

TEST(FigureTest, RemoveFigureInt) {
    Array<Figure<int>> figures;
    figures.push_back(std::make_shared<Rectangle<int>>(Point<int>(0, 4), Point<int>(4, 4), Point<int>(4, 0), Point<int>(0, 0)));
    figures.push_back(std::make_shared<Square<int>>(Point<int>(0, 2), Point<int>(2, 2), Point<int>(2, 0), Point<int>(0, 0)));

    size_t indexToRemove = 1;
    figures.remove(indexToRemove);

    EXPECT_EQ(figures.getSize(), 1);
}