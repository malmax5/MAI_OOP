#include <gtest/gtest.h>
#include "../includes/Rectangle.hpp"

TEST(RectangleTest, CheckOnRightFigure_int) {
    Point<int> topLeft(0, 4);
    Point<int> topRight(4, 4);
    Point<int> downRight(4, 0);
    Point<int> downLeft(0, 0);

    Rectangle<int> trap(topLeft, topRight, downRight, downLeft);
    EXPECT_NO_THROW(trap.CheckOnRightFigure());

    Point<int> badTopLeft(0, 4);
    Point<int> badTopRight(5, 4);
    Point<int> badDownRight(4, 0);
    Point<int> badDownLeft(0, 0);

    EXPECT_THROW(Rectangle<int>(badTopLeft, badTopRight, badDownRight, badDownLeft), BadFigure);
}

TEST(RectangleTest, CalculateCentroid_int) {
    Point<int> topLeft(0, 4);
    Point<int> topRight(4, 4);
    Point<int> downRight(4, 0);
    Point<int> downLeft(0, 0);

    Rectangle<int> trap(topLeft, topRight, downRight, downLeft);
    Point<double> centroid = trap.CalculateCentroid();

    double expectedCordX = 2.0;
    double expectedCordY = 2.0;

    EXPECT_NEAR(centroid.GetX(), expectedCordX, 1e-6);
    EXPECT_NEAR(centroid.GetY(), expectedCordY, 1e-6);
}

TEST(RectangleTest, CalculateArea_int) {
    Point<int> topLeft(0, 4);
    Point<int> topRight(4, 4);
    Point<int> downRight(4, 0);
    Point<int> downLeft(0, 0);

    Rectangle<int> trap(topLeft, topRight, downRight, downLeft);
    double area = trap.CalculateArea();

    double expectedArea = 16.0;

    EXPECT_NEAR(area, expectedArea, 1e-6);
}