#include <gtest/gtest.h>
#include "../includes/figures/Trapezoid.hpp"
#include "../includes/figures/Rectangle.hpp"
#include "../includes/figures/Square.hpp"
#include "../includes/Array.hpp"

TEST(ArrayTest, TotalArea) {
    Array<Figure<double>> figures;
    figures.push_back(std::make_shared<Rectangle<double>>(Point<double>(0, 4), Point<double>(4, 4), Point<double>(4, 0), Point<double>(0, 0)));
    figures.push_back(std::make_shared<Square<double>>(Point<double>(0, 2), Point<double>(2, 2), Point<double>(2, 0), Point<double>(0, 0)));
    figures.push_back(std::make_shared<Trapezoid<double>>(Point<double>(0, 0), Point<double>(1, 1), Point<double>(2, 1), Point<double>(3, 0)));

    double totalArea = figures.totalArea();
    double expectedArea = 22.0;

    EXPECT_NEAR(totalArea, expectedArea, 1e-9);
}

TEST(ArrayTest, RemoveFigure) {
    Array<Figure<double>> figures;
    figures.push_back(std::make_shared<Rectangle<double>>(Point<double>(0, 4), Point<double>(4, 4), Point<double>(4, 0), Point<double>(0, 0)));
    figures.push_back(std::make_shared<Square<double>>(Point<double>(0, 2), Point<double>(2, 2), Point<double>(2, 0), Point<double>(0, 0)));

    size_t indexToRemove = 1;
    figures.remove(indexToRemove);

    EXPECT_EQ(figures.getSize(), 1);
}
