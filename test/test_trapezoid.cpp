#include <gtest/gtest.h>
#include "../includes/Trapezoid.hpp"

TEST(TrapezoidTest, DefaultConstructor) {
    Trapezoid<double> trap;

    Point<double> expected(0, 0);

    EXPECT_EQ(trap.GetTopLeft(), expected);
    EXPECT_EQ(trap.GetTopRight(), expected);
    EXPECT_EQ(trap.GetDownRight(), expected);
    EXPECT_EQ(trap.GetDownLeft(), expected);
}

TEST(TrapezoidTest, ParameterizedConstructor) {
    Point<double> topLeft(0, 0);
    Point<double> topRight(1, 1);
    Point<double> downRight(2, 1);
    Point<double> downLeft(3, 0);

    Trapezoid<double> trap(topLeft, topRight, downRight, downLeft);

    EXPECT_EQ(trap.GetTopLeft(), topRight);
    EXPECT_EQ(trap.GetTopRight(), downRight);
    EXPECT_EQ(trap.GetDownRight(), downLeft);
    EXPECT_EQ(trap.GetDownLeft(), topLeft);
}

TEST(TrapezoidTest, CopyConstructor) {
    Point<double> topLeft(0, 0);
    Point<double> topRight(1, 1);
    Point<double> downRight(2, 1);
    Point<double> downLeft(3, 0);

    Trapezoid<double> trap1(topLeft, topRight, downRight, downLeft);
    Trapezoid<double> trap2(trap1);

    EXPECT_EQ(trap2.GetTopLeft(), topRight);
    EXPECT_EQ(trap2.GetTopRight(), downRight);
    EXPECT_EQ(trap2.GetDownRight(), downLeft);
    EXPECT_EQ(trap2.GetDownLeft(), topLeft);
}

TEST(TrapezoidTest, MoveConstructor) {
    Point<double> topLeft(0, 0);
    Point<double> topRight(1, 1);
    Point<double> downRight(2, 1);
    Point<double> downLeft(3, 0);

    Trapezoid<double> trap1(topLeft, topRight, downRight, downLeft);
    Trapezoid<double> trap2(std::move(trap1));

    EXPECT_EQ(trap2.GetTopLeft(), topRight);
    EXPECT_EQ(trap2.GetTopRight(), downRight);
    EXPECT_EQ(trap2.GetDownRight(), downLeft);
    EXPECT_EQ(trap2.GetDownLeft(), topLeft);
}

TEST(TrapezoidTest, CheckOnRightFigure) {
    Point<double> topLeft(0, 0);
    Point<double> topRight(1, 1);
    Point<double> downRight(2, 1);
    Point<double> downLeft(3, 0);

    Trapezoid<double> trap(topLeft, topRight, downRight, downLeft);
    EXPECT_NO_THROW(trap.CheckOnRightFigure());

    Point<double> badTopLeft(0, 3);
    Point<double> badTopRight(2, 3);
    Point<double> badDownRight(2, 0);
    Point<double> badDownLeft(0, 0);

    EXPECT_THROW(Trapezoid<double>(badTopLeft, badTopRight, badDownRight, badDownLeft), BadFigure);
}

TEST(TrapezoidTest, CalculateCentroid) {
    Point<double> topLeft(0, 0);
    Point<double> topRight(1, 1);
    Point<double> downRight(2, 1);
    Point<double> downLeft(3, 0);

    Trapezoid<double> trap(topLeft, topRight, downRight, downLeft);
    Point<double> centroid = trap.CalculateCentroid();

    double expectedCordX = 1.5;
    double expectedCordY = 0.5;

    EXPECT_NEAR(centroid.GetX(), expectedCordX, 1e-6);
    EXPECT_NEAR(centroid.GetY(), expectedCordY, 1e-6);
}

TEST(TrapezoidTest, CalculateArea) {
    Point<double> topLeft(0, 0);
    Point<double> topRight(1, 1);
    Point<double> downRight(2, 1);
    Point<double> downLeft(3, 0);

    Trapezoid<double> trap(topLeft, topRight, downRight, downLeft);
    double area = trap.CalculateArea();

    double expectedArea = 2.0;

    EXPECT_NEAR(area, expectedArea, 1e-6);
}

TEST(TrapezoidTest, CopyAssignmentOperator) {
    Point<double> topLeft(0, 0);
    Point<double> topRight(1, 1);
    Point<double> downRight(2, 1);
    Point<double> downLeft(3, 0);

    Trapezoid<double> trap1(topLeft, topRight, downRight, downLeft);
    Trapezoid<double> trap2;
    trap2 = trap1;

    EXPECT_EQ(trap2.GetTopLeft(), topRight);
    EXPECT_EQ(trap2.GetTopRight(), downRight);
    EXPECT_EQ(trap2.GetDownRight(), downLeft);
    EXPECT_EQ(trap2.GetDownLeft(), topLeft);
}

TEST(TrapezoidTest, MoveAssignmentOperator) {
    Point<double> topLeft(0, 0);
    Point<double> topRight(1, 1);
    Point<double> downRight(2, 1);
    Point<double> downLeft(3, 0);

    Trapezoid<double> trap1(topLeft, topRight, downRight, downLeft);
    Trapezoid<double> trap2;
    trap2 = std::move(trap1);

    EXPECT_EQ(trap2.GetTopLeft(), topRight);
    EXPECT_EQ(trap2.GetTopRight(), downRight);
    EXPECT_EQ(trap2.GetDownRight(), downLeft);
    EXPECT_EQ(trap2.GetDownLeft(), topLeft);
}

TEST(TrapezoidTest, EqualityOperator) {
    Point<double> topLeft(0, 0);
    Point<double> topRight(1, 1);
    Point<double> downRight(2, 1);
    Point<double> downLeft(3, 0);

    Point<double> topLeft_bad(1, 4);
    Point<double> topRight_bad(2, 4);
    Point<double> downRight_bad(3, 3);
    Point<double> downLeft_bad(3, 2);

    Trapezoid<double> trap1(topLeft, topRight, downRight, downLeft);
    Trapezoid<double> trap2(topLeft, topRight, downRight, downLeft);
    Trapezoid<double> trap3(topLeft_bad, topRight_bad, downRight_bad, downLeft_bad);

    EXPECT_TRUE(trap1 == trap2);
    EXPECT_FALSE(trap1 == trap3);
}

TEST(TrapezoidTest, ConversionOperator) {
    Point<double> topLeft(0, 0);
    Point<double> topRight(1, 1);
    Point<double> downRight(2, 1);
    Point<double> downLeft(3, 0);

    Trapezoid<double> trap(topLeft, topRight, downRight, downLeft);
    double area = (double)(trap);

    double expectedArea = 2.0;

    EXPECT_NEAR(area, expectedArea, 1e-6);
}

TEST(TrapezoidTest, InputOperator) {
    std::stringstream ss;
    ss << "0 0 1 1 2 1 3 0";

    Trapezoid<double> trap;
    ss >> trap;

    Point<double> topLeft(0, 0);
    Point<double> topRight(1, 1);
    Point<double> downRight(2, 1);
    Point<double> downLeft(3, 0);

    EXPECT_EQ(trap.GetTopLeft(), topRight);
    EXPECT_EQ(trap.GetTopRight(), downRight);
    EXPECT_EQ(trap.GetDownRight(), downLeft);
    EXPECT_EQ(trap.GetDownLeft(), topLeft);
}

TEST(TrapezoidTest, OutputOperator) {
    Point<double> topLeft(0, 0);
    Point<double> topRight(1, 1);
    Point<double> downRight(2, 1);
    Point<double> downLeft(3, 0);

    Trapezoid<double> trap(topLeft, topRight, downRight, downLeft);

    std::stringstream ss;
    ss << trap;

    std::string expected = "(1, 1) (2, 1) (3, 0) (0, 0)";

    EXPECT_EQ(ss.str(), expected);
}

TEST(TrapezoidTest, Clone) {
    Point<double> topLeft(0, 0);
    Point<double> topRight(1, 1);
    Point<double> downRight(2, 1);
    Point<double> downLeft(3, 0);

    Trapezoid<double> trap(topLeft, topRight, downRight, downLeft);
    std::unique_ptr<Figure<double>> clonedTrap = trap.Clone();

    EXPECT_EQ(clonedTrap->GetTopLeft(), topRight);
    EXPECT_EQ(clonedTrap->GetTopRight(), downRight);
    EXPECT_EQ(clonedTrap->GetDownRight(), downLeft);
    EXPECT_EQ(clonedTrap->GetDownLeft(), topLeft);
}

TEST(TrapezoidTest, Move) {
    Point<double> topLeft(0, 0);
    Point<double> topRight(1, 1);
    Point<double> downRight(2, 1);
    Point<double> downLeft(3, 0);

    Trapezoid<double> trap(topLeft, topRight, downRight, downLeft);
    std::unique_ptr<Figure<double>> movedTrap = trap.Move();

    EXPECT_EQ(movedTrap->GetTopLeft(), topRight);
    EXPECT_EQ(movedTrap->GetTopRight(), downRight);
    EXPECT_EQ(movedTrap->GetDownRight(), downLeft);
    EXPECT_EQ(movedTrap->GetDownLeft(), topLeft);
}