#include <gtest/gtest.h>
#include <UpdatedString.h>

TEST(ProjectTests, DefaultConstructor)
{
    UpdatedString str;

    std::string res = str.get();

    EXPECT_EQ(res, "");
}

TEST(ProjectTests, StdStringConstructor)
{
    std::string test_str = "Hello";
    UpdatedString str(test_str);

    std::string ret = str.get();

    EXPECT_EQ(ret, "Hello");
}

TEST(ProjectTests, CStringConstructor)
{
    const char* test_str = "Hello";
    UpdatedString str(test_str);

    std::string res = str.get();

    EXPECT_EQ(res, "Hello");
}

TEST(ProjectTests, CopyConstructor)
{
    UpdatedString original("Hello");
    UpdatedString copy(original);

    std::string res = copy.get();

    EXPECT_EQ(res, "Hello");
}

TEST(ProjectTests, CopyAssignmentOperator)
{
    UpdatedString original("Hello");
    UpdatedString copy;
    copy = original;

    std::string res = copy.get();

    EXPECT_EQ(res, "Hello");
}

TEST(ProjectTests, MoveConstructor)
{
    UpdatedString original("Hello");
    UpdatedString moved(std::move(original));

    std::string resOr = original.get();
    std::string resMo = moved.get();

    EXPECT_EQ(resMo, "Hello");
    EXPECT_EQ(resOr, "");
}

TEST(ProjectTests, MoveAssignmentOperator)
{
    UpdatedString original("Hello");
    UpdatedString moved;
    moved = std::move(original);

    std::string resOr = original.get();
    std::string resMo = moved.get();

    EXPECT_EQ(resMo, "Hello");
    EXPECT_EQ(resOr, "");
}

TEST(ProjectTests, ClearMethod)
{
    UpdatedString str("Hello");
    str.clear();

    std::string res = str.get();

    EXPECT_EQ(res, "");
}

TEST(ProjectTests, GetMethod)
{
    UpdatedString str("Hello");

    std::string res = str.get();

    EXPECT_EQ(res, "Hello");
}