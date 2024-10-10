#include <gtest/gtest.h>
#include "../includes/Square.hpp"

TEST(SquareTest, DefaultConstructor) {
    Square<double> sq;

    Point<double> expected(0, 0);

    EXPECT_EQ(sq.GetTopLeft(), expected);
    EXPECT_EQ(sq.GetTopRight(), expected);
    EXPECT_EQ(sq.GetDownRight(), expected);
    EXPECT_EQ(sq.GetDownLeft(), expected);
}

// Тест для конструктора с параметрами
TEST(SquareTest, ParameterizedConstructor) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Square<double> sq(topLeft, topRight, downRight, downLeft);

    EXPECT_EQ(sq.GetTopLeft(), topLeft);
    EXPECT_EQ(sq.GetTopRight(), topRight);
    EXPECT_EQ(sq.GetDownRight(), downRight);
    EXPECT_EQ(sq.GetDownLeft(), downLeft);
}

// Тест для копирующего конструктора
TEST(SquareTest, CopyConstructor) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Square<double> sq1(topLeft, topRight, downRight, downLeft);
    Square<double> sq2(sq1);

    EXPECT_EQ(sq2.GetTopLeft(), topLeft);
    EXPECT_EQ(sq2.GetTopRight(), topRight);
    EXPECT_EQ(sq2.GetDownRight(), downRight);
    EXPECT_EQ(sq2.GetDownLeft(), downLeft);
}

TEST(SquareTest, MoveConstructor) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Square<double> sq1(topLeft, topRight, downRight, downLeft);
    Square<double> sq2(std::move(sq1));

    EXPECT_EQ(sq2.GetTopLeft(), topLeft);
    EXPECT_EQ(sq2.GetTopRight(), topRight);
    EXPECT_EQ(sq2.GetDownRight(), downRight);
    EXPECT_EQ(sq2.GetDownLeft(), downLeft);
}

// Тест для метода CheckOnRightFigure
TEST(SquareTest, CheckOnRightFigure) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Square<double> sq(topLeft, topRight, downRight, downLeft);
    EXPECT_NO_THROW(sq.CheckOnRightFigure());

    Point<double> badTopLeft(0, 3);
    Point<double> badTopRight(2, 3);
    Point<double> badDownRight(2, 0);
    Point<double> badDownLeft(0, 0);

    EXPECT_THROW(Square<double>(badTopLeft, badTopRight, badDownRight, badDownLeft), BadFigure);
}

// Тест для метода CalculateCentroid
TEST(SquareTest, CalculateCentroid) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Square<double> sq(topLeft, topRight, downRight, downLeft);
    Point<double> centroid = sq.CalculateCentroid();

    double expectedCordX = 2.0;
    double expectedCordY = 2.0;

    EXPECT_NEAR(centroid.GetX(), expectedCordX, 1e-6);
    EXPECT_NEAR(centroid.GetY(), expectedCordY, 1e-6);
}

// Тест для метода CalculateArea
TEST(SquareTest, CalculateArea) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Square<double> sq(topLeft, topRight, downRight, downLeft);
    double area = sq.CalculateArea();

    double expectedArea = 16.0;

    EXPECT_NEAR(area, expectedArea, 1e-6);
}

// Тест для оператора присваивания копированием
TEST(SquareTest, CopyAssignmentOperator) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Square<double> sq1(topLeft, topRight, downRight, downLeft);
    Square<double> sq2;
    sq2 = sq1;

    EXPECT_EQ(sq2.GetTopLeft(), topLeft);
    EXPECT_EQ(sq2.GetTopRight(), topRight);
    EXPECT_EQ(sq2.GetDownRight(), downRight);
    EXPECT_EQ(sq2.GetDownLeft(), downLeft);
}

// Тест для оператора присваивания перемещением
TEST(SquareTest, MoveAssignmentOperator) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Square<double> sq1(topLeft, topRight, downRight, downLeft);
    Square<double> sq2;
    sq2 = std::move(sq1);

    EXPECT_EQ(sq2.GetTopLeft(), topLeft);
    EXPECT_EQ(sq2.GetTopRight(), topRight);
    EXPECT_EQ(sq2.GetDownRight(), downRight);
    EXPECT_EQ(sq2.GetDownLeft(), downLeft);
}

// Тест для оператора сравнения
TEST(SquareTest, EqualityOperator) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Point<double> topLeft_bad(0, 2);
    Point<double> topRight_bad(2, 2);
    Point<double> downRight_bad(2, 0);
    Point<double> downLeft_bad(0, 0);

    Square<double> sq1(topLeft, topRight, downRight, downLeft);
    Square<double> sq2(topLeft, topRight, downRight, downLeft);
    Square<double> sq3(topLeft_bad, topRight_bad, downRight_bad, downLeft_bad);

    EXPECT_TRUE(sq1 == sq2);
    EXPECT_FALSE(sq1 == sq3);
}

// Тест для оператора преобразования к double
TEST(SquareTest, ConversionOperator) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Square<double> sq(topLeft, topRight, downRight, downLeft);
    double area = (double)(sq);

    double expectedArea = 16.0;

    EXPECT_NEAR(area, expectedArea, 1e-6);
}

// Тест для оператора ввода
TEST(SquareTest, InputOperator) {
    std::stringstream ss;
    ss << "0 4 4 4 4 0 0 0";

    Square<double> sq;
    ss >> sq;

    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    EXPECT_EQ(sq.GetTopLeft(), topLeft);
    EXPECT_EQ(sq.GetTopRight(), topRight);
    EXPECT_EQ(sq.GetDownRight(), downRight);
    EXPECT_EQ(sq.GetDownLeft(), downLeft);
}

// Тест для оператора вывода
TEST(SquareTest, OutputOperator) {
    Point<double> topLeft(0, 4);
    Point<double> topRight(4, 4);
    Point<double> downRight(4, 0);
    Point<double> downLeft(0, 0);

    Square<double> sq(topLeft, topRight, downRight, downLeft);

    std::stringstream ss;
    ss << sq;

    std::string expected = "(0, 4) (4, 4) (4, 0) (0, 0)";

    EXPECT_EQ(ss.str(), expected);
}