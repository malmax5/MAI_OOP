#include <gtest/gtest.h>
#include "../includes/Rectangle.hpp"

TEST(RectangleTest, DefaultConstructor) {
    Rectangle<double> trap;

    Point<double> expected(0, 0);

    EXPECT_EQ(trap.GetTopLeft(), expected);
    EXPECT_EQ(trap.GetTopRight(), expected);
    EXPECT_EQ(trap.GetDownRight(), expected);
    EXPECT_EQ(trap.GetDownLeft(), expected);
}

TEST(RectangleTest, ParameterizedConstructor) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Rectangle<double> trap(topLeft, topRight, downRight, downLeft);

    EXPECT_EQ(trap.GetTopLeft(), topLeft);
    EXPECT_EQ(trap.GetTopRight(), topRight);
    EXPECT_EQ(trap.GetDownRight(), downRight);
    EXPECT_EQ(trap.GetDownLeft(), downLeft);
}

TEST(RectangleTest, CopyConstructor) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Rectangle<double> trap1(topLeft, topRight, downRight, downLeft);
    Rectangle<double> trap2(trap1);

    EXPECT_EQ(trap2.GetTopLeft(), topLeft);
    EXPECT_EQ(trap2.GetTopRight(), topRight);
    EXPECT_EQ(trap2.GetDownRight(), downRight);
    EXPECT_EQ(trap2.GetDownLeft(), downLeft);
}

TEST(RectangleTest, MoveConstructor) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Rectangle<double> trap1(topLeft, topRight, downRight, downLeft);
    Rectangle<double> trap2(std::move(trap1));

    EXPECT_EQ(trap2.GetTopLeft(), topLeft);
    EXPECT_EQ(trap2.GetTopRight(), topRight);
    EXPECT_EQ(trap2.GetDownRight(), downRight);
    EXPECT_EQ(trap2.GetDownLeft(), downLeft);
}

TEST(RectangleTest, CheckOnRightFigure) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Rectangle<double> trap(topLeft, topRight, downRight, downLeft);
    EXPECT_NO_THROW(trap.CheckOnRightFigure());

    Point<double> badTopLeft(0, 4);
    Point<double> badTopRight(5, 4);
    Point<double> badDownRight(4, 0);
    Point<double> badDownLeft(0, 0);

    EXPECT_THROW(Rectangle<double>(badTopLeft, badTopRight, badDownRight, badDownLeft), BadFigure);
}

TEST(RectangleTest, CalculateCentroid) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Rectangle<double> trap(topLeft, topRight, downRight, downLeft);
    Point<double> centroid = trap.CalculateCentroid();

    double expectedCordX = 2.0;
    double expectedCordY = 2.0;

    EXPECT_NEAR(centroid.GetX(), expectedCordX, 1e-6);
    EXPECT_NEAR(centroid.GetY(), expectedCordY, 1e-6);
}

TEST(RectangleTest, CalculateArea) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Rectangle<double> trap(topLeft, topRight, downRight, downLeft);
    double area = trap.CalculateArea();

    double expectedArea = 16.0;

    EXPECT_NEAR(area, expectedArea, 1e-6);
}

TEST(RectangleTest, CopyAssignmentOperator) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Rectangle<double> trap1(topLeft, topRight, downRight, downLeft);
    Rectangle<double> trap2;
    trap2 = trap1;

    EXPECT_EQ(trap2.GetTopLeft(), topLeft);
    EXPECT_EQ(trap2.GetTopRight(), topRight);
    EXPECT_EQ(trap2.GetDownRight(), downRight);
    EXPECT_EQ(trap2.GetDownLeft(), downLeft);
}

TEST(RectangleTest, MoveAssignmentOperator) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Rectangle<double> trap1(topLeft, topRight, downRight, downLeft);
    Rectangle<double> trap2;
    trap2 = std::move(trap1);

    EXPECT_EQ(trap2.GetTopLeft(), topLeft);
    EXPECT_EQ(trap2.GetTopRight(), topRight);
    EXPECT_EQ(trap2.GetDownRight(), downRight);
    EXPECT_EQ(trap2.GetDownLeft(), downLeft);
}

TEST(RectangleTest, EqualityOperator) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Point<double> topLeft_bad(0, 3);
    Point<double> topRight_bad(2, 3);
    Point<double> downRight_bad(2, 0);
    Point<double> downLeft_bad(0, 0);

    Rectangle<double> trap1(topLeft, topRight, downRight, downLeft);
    Rectangle<double> trap2(topLeft, topRight, downRight, downLeft);
    Rectangle<double> trap3(topLeft_bad, topRight_bad, downRight_bad, downLeft_bad);

    EXPECT_TRUE(trap1 == trap2);
    EXPECT_FALSE(trap1 == trap3);
}

TEST(RectangleTest, ConversionOperator) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Rectangle<double> trap(topLeft, topRight, downRight, downLeft);
    double area = (double)(trap);

    double expectedArea = 16.0;

    EXPECT_NEAR(area, expectedArea, 1e-6);
}

TEST(RectangleTest, InputOperator) {
    std::stringstream ss;
    ss << "0 4 4 4 4 0 0 0";

    Rectangle<double> trap;
    ss >> trap;

    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    EXPECT_EQ(trap.GetTopLeft(), topLeft);
    EXPECT_EQ(trap.GetTopRight(), topRight);
    EXPECT_EQ(trap.GetDownRight(), downRight);
    EXPECT_EQ(trap.GetDownLeft(), downLeft);
}

TEST(RectangleTest, OutputOperator) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Rectangle<double> trap(topLeft, topRight, downRight, downLeft);

    std::stringstream ss;
    ss << trap;

    std::string expected = "(0, 4) (4, 4) (4, 0) (0, 0)";

    EXPECT_EQ(ss.str(), expected);
}

TEST(RectangleTest, Clone) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Rectangle<double> rect(topLeft, topRight, downRight, downLeft);
    std::unique_ptr<Figure<double>> clonedRect = rect.Clone();

    EXPECT_EQ(clonedRect->GetTopLeft(), topLeft);
    EXPECT_EQ(clonedRect->GetTopRight(), topRight);
    EXPECT_EQ(clonedRect->GetDownRight(), downRight);
    EXPECT_EQ(clonedRect->GetDownLeft(), downLeft);
}

TEST(RectangleTest, Move) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Rectangle<double> rect(topLeft, topRight, downRight, downLeft);
    std::unique_ptr<Figure<double>> movedRect = rect.Move();

    EXPECT_EQ(movedRect->GetTopLeft(), topLeft);
    EXPECT_EQ(movedRect->GetTopRight(), topRight);
    EXPECT_EQ(movedRect->GetDownRight(), downRight);
    EXPECT_EQ(movedRect->GetDownLeft(), downLeft);
}