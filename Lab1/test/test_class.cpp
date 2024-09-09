#include <gtest/gtest.h>
#include <UpdatedString.h>

TEST(ProjectTests, DefaultConstructor)
{
    UpdatedString str;
    EXPECT_EQ(str.get(), "");
}

TEST(ProjectTests, StdStringConstructor)
{
    std::string test_str = "Hello";

    UpdatedString str(test_str);

    EXPECT_EQ(str.get(), "Hello");
}

TEST(ProjectTests, CStringConstructor)
{
    const char* test_str = "Hello";

    UpdatedString str(test_str);

    EXPECT_EQ(str.get(), "Hello");
}

TEST(ProjectTests, CopyConstructor)
{
    UpdatedString original("Hello");

    UpdatedString copy(original);

    EXPECT_EQ(copy.get(), "Hello");
}

TEST(ProjectTests, CopyAssignmentOperator)
{
    UpdatedString original("Hello");
    UpdatedString copy;

    copy = original;

    EXPECT_EQ(copy.get(), "Hello");
}

TEST(ProjectTests, MoveConstructor)
{
    UpdatedString original("Hello");

    UpdatedString moved(std::move(original));

    EXPECT_EQ(moved.get(), "Hello");
    EXPECT_EQ(original.get(), "");
}

TEST(ProjectTests, MoveAssignmentOperator)
{
    UpdatedString original("Hello");
    UpdatedString moved;

    moved = std::move(original);

    EXPECT_EQ(moved.get(), "Hello");
    EXPECT_EQ(original.get(), "");
}

TEST(ProjectTests, ClearMethod)
{
    UpdatedString str("Hello");

    str.clear();

    EXPECT_EQ(str.get(), "");
}

TEST(ProjectTests, GetMethod)
{
    UpdatedString str("Hello");
    
    EXPECT_EQ(str.get(), "Hello");
}