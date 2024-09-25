#include <gtest/gtest.h>
#include "implementations/FourCalc.h"
#include "implementations\Vector.h"

TEST(FourTests, DefaultConstructor)
{
    Four four;
    Vector<unsigned char> res = four.getNumber();

    Vector<unsigned char> expected(0);

    EXPECT_EQ(res, expected);
}

TEST(FourTests, SizeAndValueConstructor)
{
    Four four(3, 2);
    Vector<unsigned char> res = four.getNumber();

    Vector<unsigned char> expected = {2, 2, 2};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, InitializerListConstructor)
{
    Four four({1, 2, 3});
    Vector<unsigned char> res = four.getNumber();

    Vector<unsigned char> expected = {3, 2, 1};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, StringConstructor)
{
    Four four("123");
    Vector<unsigned char> res = four.getNumber();

    Vector<unsigned char> expected = {3, 2, 1};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, GreaterThanOperator)
{
    Four four1({1, 2, 3});
    Four four2({0, 2, 1});

    EXPECT_TRUE(four1 > four2);
    EXPECT_FALSE(four2 > four1);
}

TEST(FourTests, LessThanOperator)
{
    Four four1({0, 2, 1});
    Four four2({1, 2, 3});

    EXPECT_TRUE(four1 < four2);
    EXPECT_FALSE(four2 < four1);
}

TEST(FourTests, EqualToOperator)
{
    Four four1({1, 2, 3});
    Four four2({1, 2, 3});
    Four four3({0, 2, 1});

    EXPECT_TRUE(four1 == four2);
    EXPECT_FALSE(four1 == four3);
}

TEST(FourTests, AdditionOperator_1)
{
    Four four1({1, 2, 3});
    Four four2({2, 1, 0});

    Four result = four1 + four2;
    Vector<unsigned char> res = result.getNumber();

    Vector<unsigned char> expected = {3, 3, 3};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, AdditionOperator_2)
{
    Four four1({1, 2, 3});
    Four four2({2, 1});

    Four result = four1 + four2;
    Vector<unsigned char> res = result.getNumber();

    Vector<unsigned char> expected = {0, 1, 2};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, AdditionOperator_3)
{
    Four four1({3, 3, 3});
    Four four2({1, 1, 1});

    Four result = four1 + four2;
    Vector<unsigned char> res = result.getNumber();

    Vector<unsigned char> expected = {0, 1, 1, 1};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, AdditionOperator_4)
{
    Four four1({3, 3, 3});
    Four four2({1, 1});

    Four result = four1 + four2;
    Vector<unsigned char> res = result.getNumber();

    Vector<unsigned char> expected = {0, 1, 0, 1};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, AdditionOperator_5)
{
    Four four1({1, 2, 3});
    Four four2({0});

    Four result = four1 + four2;
    Vector<unsigned char> res = result.getNumber();

    Vector<unsigned char> expected = {3, 2, 1};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, AdditionOperator_6)
{
    Four four1({0});
    Four four2({0});

    Four result = four1 + four2;
    Vector<unsigned char> res = result.getNumber();

    Vector<unsigned char> expected = {0};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, SubtractionOperator_1)
{
    Four four1({1, 2, 3});
    Four four2({0, 2, 1});

    Four result = four1 - four2;
    Vector<unsigned char> res = result.getNumber();

    Vector<unsigned char> expected = {2, 0, 1};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, SubtractionOperator_2)
{
    Four four1({3, 2, 1});
    Four four2({1, 2, 0});

    Four result = four1 - four2;
    Vector<unsigned char> res = result.getNumber();

    Vector<unsigned char> expected = {1, 0, 2};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, SubtractionOperator_3)
{
    Four four1({2, 1, 0});
    Four four2({1, 0, 3});

    Four result = four1 - four2;
    Vector<unsigned char> res = result.getNumber();

    Vector<unsigned char> expected = {1, 0, 1};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, SubtractionOperator_4)
{
    Four four1({1, 3, 2});
    Four four2({0, 2, 1});

    Four result = four1 - four2;
    Vector<unsigned char> res = result.getNumber();

    Vector<unsigned char> expected = {1, 1, 1};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, SubtractionOperator_5)
{
    Four four1({3, 3, 3});
    Four four2({1, 1, 1});

    Four result = four1 - four2;
    Vector<unsigned char> res = result.getNumber();

    Vector<unsigned char> expected = {2, 2, 2};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, SubtractionOperator_6)
{
    Four four1({2, 2, 2});
    Four four2({0, 0, 2});

    Four result = four1 - four2;
    Vector<unsigned char> res = result.getNumber();

    Vector<unsigned char> expected = {0, 2, 2};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, SubtractionOperator_7)
{
    Four four1({1, 0, 0});
    Four four2({0, 3, 3});

    Four result = four1 - four2;
    Vector<unsigned char> res = result.getNumber();

    Vector<unsigned char> expected = {1};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, SubtractionOperator_8)
{
    Four four1({1, 2, 3});
    Four four2({0, 0, 0});

    Four result = four1 - four2;
    Vector<unsigned char> res = result.getNumber();

    Vector<unsigned char> expected = {3, 2, 1};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, SubtractionOperator_9)
{
    Four four1({0, 0, 0});
    Four four2({0, 0, 0});

    Four result = four1 - four2;
    Vector<unsigned char> res = result.getNumber();

    Vector<unsigned char> expected = {0};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, SubtractionOperator_10)
{
    Four four1({1, 2, 3});
    Four four2({1, 2, 3});

    Four result = four1 - four2;
    Vector<unsigned char> res = result.getNumber();

    Vector<unsigned char> expected = {0};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, AdditionAssignmentOperator)
{
    Four four1({1, 2, 3});
    Four four2({2, 1});

    four1 += four2;
    Vector<unsigned char> res = four1.getNumber();

    Vector<unsigned char> expected = {0, 1, 2};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, SubtractionAssignmentOperator)
{
    Four four1({1, 2, 3});
    Four four2({0, 2, 1});

    four1 -= four2;
    Vector<unsigned char> res = four1.getNumber();

    Vector<unsigned char> expected = {2, 0, 1};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, SetNumberMethod)
{
    Four four;
    Vector<unsigned char> newDigits = {1, 2, 3};

    four.setNumber(newDigits);
    Vector<unsigned char> res = four.getNumber();

    Vector<unsigned char> expected = {3, 2, 1};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, GetNumberMethod)
{
    Four four({1, 2, 3});
    Vector<unsigned char> res = four.getNumber();

    Vector<unsigned char> expected = {3, 2, 1};

    EXPECT_EQ(res, expected);
}

TEST(FourTests, ValidateDigitsMethod)
{
    EXPECT_NO_THROW(Four({1, 2, 3}));
    EXPECT_THROW(Four({4, 2, 1}), std::invalid_argument);
}