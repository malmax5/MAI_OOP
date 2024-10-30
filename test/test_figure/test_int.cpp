#include <gtest/gtest.h>
#include "../includes/Trapezoid.hpp"
#include "../includes/Rectangle.hpp"
#include "../includes/Square.hpp"

TEST(FigureTest, TotalAreaInt) {
    std::vector<Figure<int>*> figures;
    figures.push_back(new Rectangle<int>(Point<int>(0, 4), Point<int>(4, 4), Point<int>(4, 0), Point<int>(0, 0)));
    figures.push_back(new Square<int>(Point<int>(0, 2), Point<int>(2, 2), Point<int>(2, 0), Point<int>(0, 0)));
    figures.push_back(new Trapezoid<int>(Point<int>(0, 0), Point<int>(1, 1), Point<int>(2, 1), Point<int>(3, 0)));

    int totalArea = 0;
    for (const auto& figure : figures) {
        totalArea += static_cast<int>(*figure);
    }

    int expectedArea = 22;

    EXPECT_EQ(totalArea, expectedArea);

    for (auto& figure : figures) {
        delete figure;
    }
}

TEST(FigureTest, RemoveFigureInt) {
    std::vector<Figure<int>*> figures;
    figures.push_back(new Rectangle<int>(Point<int>(0, 4), Point<int>(4, 4), Point<int>(4, 0), Point<int>(0, 0)));
    figures.push_back(new Square<int>(Point<int>(0, 2), Point<int>(2, 2), Point<int>(2, 0), Point<int>(0, 0)));

    size_t indexToRemove = 1;
    delete figures[indexToRemove];
    figures.erase(figures.begin() + static_cast<std::vector<Figure<int>*>::difference_type>(indexToRemove));

    EXPECT_EQ(figures.size(), 1);
    EXPECT_NE(figures[0], nullptr);

    for (auto& figure : figures) {
        delete figure;
    }
}