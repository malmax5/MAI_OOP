#include <gtest/gtest.h>
#include "../includes/Trapezoid.hpp"

TEST(TrapezoidTest, CheckOnRightFigure_int) {
    Point<int> topLeft(0, 0);
    Point<int> topRight(1, 1);
    Point<int> downRight(2, 1);
    Point<int> downLeft(3, 0);

    Trapezoid<int> trap(topLeft, topRight, downRight, downLeft);
    EXPECT_NO_THROW(trap.CheckOnRightFigure());

    Point<int> badTopLeft(0, 3);
    Point<int> badTopRight(2, 3);
    Point<int> badDownRight(2, 0);
    Point<int> badDownLeft(0, 0);

    EXPECT_THROW(Trapezoid<int>(badTopLeft, badTopRight, badDownRight, badDownLeft), BadFigure);
}

TEST(TrapezoidTest, CalculateCentroid_int) {
    Point<int> topLeft(0, 0);
    Point<int> topRight(1, 1);
    Point<int> downRight(2, 1);
    Point<int> downLeft(3, 0);

    Trapezoid<int> trap(topLeft, topRight, downRight, downLeft);
    Point<double> centroid = trap.CalculateCentroid();

    double expectedCordX = 1.5;
    double expectedCordY = 0.5;

    EXPECT_NEAR(centroid.GetX(), expectedCordX, 1e-6);
    EXPECT_NEAR(centroid.GetY(), expectedCordY, 1e-6);
}

TEST(TrapezoidTest, CalculateArea_int) {
    Point<int> topLeft(0, 0);
    Point<int> topRight(1, 1);
    Point<int> downRight(2, 1);
    Point<int> downLeft(3, 0);

    Trapezoid<int> trap(topLeft, topRight, downRight, downLeft);
    double area = trap.CalculateArea();
    double expectedArea = 2.0;

    EXPECT_NEAR(area, expectedArea, 1e-6);
}