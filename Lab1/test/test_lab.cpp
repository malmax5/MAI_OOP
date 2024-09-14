#include <gtest/gtest.h>
#include <UpdatedString.h>

TEST(ProjectTests, IsPalindrom_1)
{
    UpdatedString str;

    bool res = str.isPalindrom();

    bool expected = true;

    ASSERT_TRUE(res == expected);
}

TEST(ProjectTests, IsPalindrom_2)
{
    UpdatedString str("");

    bool res = str.isPalindrom();

    bool expected = true;

    ASSERT_TRUE(res == expected);
}

TEST(ProjectTests, IsPalindrom_3)
{
    UpdatedString str("a");

    bool res = str.isPalindrom();

    bool expected = true;

    ASSERT_TRUE(res == expected);
}

TEST(ProjectTests, IsPalindrom_4)
{
    UpdatedString str("aa");

    bool res = str.isPalindrom();

    bool expected = true;

    ASSERT_TRUE(res == expected);
}

TEST(ProjectTests, IsPalindrom_5)
{
    UpdatedString str("aba");

    bool res = str.isPalindrom();

    bool expected = true;

    ASSERT_TRUE(res == expected);
}

TEST(ProjectTests, IsPalindrom_6)
{
    UpdatedString str("ab");

    bool res = str.isPalindrom();

    bool expected = false;

    ASSERT_TRUE(res == expected);
}

TEST(ProjectTests, IsPalindrom_7)
{
    UpdatedString str("acba");

    bool res = str.isPalindrom();

    bool expected = false;

    ASSERT_TRUE(res == expected);
}

TEST(ProjectTests, IsPalindrom_8)
{
    UpdatedString str("acfba");

    bool res = str.isPalindrom();

    bool expected = false;

    ASSERT_TRUE(res == expected);
}