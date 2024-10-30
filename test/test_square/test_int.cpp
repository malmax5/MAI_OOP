#include <gtest/gtest.h>
#include "../includes/Square.hpp"

TEST(SquareTest, CheckOnRightFigure_int) {
    Point<int> topLeft(0, 4);
    Point<int> topRight(4, 4);
    Point<int> downRight(4, 0);
    Point<int> downLeft(0, 0);

    Square<int> sq(topLeft, topRight, downRight, downLeft);
    EXPECT_NO_THROW(sq.CheckOnRightFigure());

    Point<int> badTopLeft(0, 3);
    Point<int> badTopRight(2, 3);
    Point<int> badDownRight(2, 0);
    Point<int> badDownLeft(0, 0);

    EXPECT_THROW(Square<int>(badTopLeft, badTopRight, badDownRight, badDownLeft), BadFigure);
}

TEST(SquareTest, CalculateCentroid_int) {
    Point<int> topLeft(0, 4);
    Point<int> topRight(4, 4);
    Point<int> downRight(4, 0);
    Point<int> downLeft(0, 0);

    Square<int> sq(topLeft, topRight, downRight, downLeft);
    Point<double> centroid = sq.CalculateCentroid();

    double expectedCordX = 2.0;
    double expectedCordY = 2.0;

    EXPECT_NEAR(centroid.GetX(), expectedCordX, 1e-6);
    EXPECT_NEAR(centroid.GetY(), expectedCordY, 1e-6);
}

TEST(SquareTest, CalculateArea_int) {
    Point<int> topLeft(0, 4);
    Point<int> topRight(4, 4);
    Point<int> downRight(4, 0);
    Point<int> downLeft(0, 0);

    Square<int> sq(topLeft, topRight, downRight, downLeft);
    double area = sq.CalculateArea();

    double expectedArea = 16.0;

    EXPECT_NEAR(area, expectedArea, 1e-6);
}