#include <gtest/gtest.h>
#include "../includes/Trapezoid.hpp"
#include "../includes/Rectangle.hpp"
#include "../includes/Square.hpp"

TEST(FigureTest, TotalArea) {
    std::vector<Figure<double>*> figures;
    figures.push_back(new Rectangle<double>(Point<double>(0, 4), Point<double>(4, 4), Point<double>(4, 0), Point<double>(0, 0)));
    figures.push_back(new Square<double>(Point<double>(0, 2), Point<double>(2, 2), Point<double>(2, 0), Point<double>(0, 0)));
    figures.push_back(new Trapezoid<double>(Point<double>(0, 0), Point<double>(1, 1), Point<double>(2, 1), Point<double>(3, 0)));

    double totalArea = 0;
    for (const auto& figure : figures) {
        totalArea += static_cast<double>(*figure);
    }

    double expectedArea = 22.0;

    EXPECT_NEAR(totalArea, expectedArea, 1e-6);

    for (auto& figure : figures) {
        delete figure;
    }
}

TEST(FigureTest, RemoveFigure) {
    std::vector<Figure<double>*> figures;
    figures.push_back(new Rectangle<double>(Point<double>(0, 4), Point<double>(4, 4), Point<double>(4, 0), Point<double>(0, 0)));
    figures.push_back(new Square<double>(Point<double>(0, 2), Point<double>(2, 2), Point<double>(2, 0), Point<double>(0, 0)));

    size_t indexToRemove = 1;
    delete figures[indexToRemove];
    figures.erase(figures.begin() + static_cast<std::vector<Figure<double>*>::difference_type>(indexToRemove));

    EXPECT_EQ(figures.size(), 1);
    EXPECT_NE(figures[0], nullptr);

    for (auto& figure : figures) {
        delete figure;
    }
}