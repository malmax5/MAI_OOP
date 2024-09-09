#include <gtest/gtest.h>
#include <UpdatedString.h>

TEST(ProjectTests, IsPalindrom_1)
{
    UpdatedString str;
    EXPECT_EQ(str.isPalindrom(), 1);
}

TEST(ProjectTests, IsPalindrom_2)
{
    UpdatedString str("");
    EXPECT_EQ(str.isPalindrom(), 1);
}

TEST(ProjectTests, IsPalindrom_3)
{
    UpdatedString str("a");
    EXPECT_EQ(str.isPalindrom(), 1);
}

TEST(ProjectTests, IsPalindrom_4)
{
    UpdatedString str("aa");
    EXPECT_EQ(str.isPalindrom(), 1);
}

TEST(ProjectTests, IsPalindrom_5)
{
    UpdatedString str("aba");
    EXPECT_EQ(str.isPalindrom(), 1);
}

TEST(ProjectTests, IsPalindrom_6)
{
    UpdatedString str("ab");
    EXPECT_EQ(str.isPalindrom(), 0);
}

TEST(ProjectTests, IsPalindrom_7)
{
    UpdatedString str("acba");
    EXPECT_EQ(str.isPalindrom(), 0);
}

TEST(ProjectTests, IsPalindrom_8)
{
    UpdatedString str("acfba");
    EXPECT_EQ(str.isPalindrom(), 0);
}