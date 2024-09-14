#include <gtest/gtest.h>
#include <UpdatedString.h>

TEST(ProjectTests, DefaultConstructor)
{
    UpdatedString str;
    std::string res = str.get();

    std::string expected = "";

    EXPECT_EQ(res, expected);
}

TEST(ProjectTests, StdStringConstructor)
{
    std::string test_str = "Hello";
    UpdatedString str(test_str);

    std::string ret = str.get();

    std::string expected = "Hello";

    EXPECT_EQ(ret, expected);
}

TEST(ProjectTests, CStringConstructor)
{
    const char* test_str = "Hello";
    UpdatedString str(test_str);

    std::string res = str.get();

    std::string expected = "Hello";

    EXPECT_EQ(res, expected);
}

TEST(ProjectTests, CopyConstructor)
{
    UpdatedString original("Hello");
    UpdatedString copy(original);

    std::string res = copy.get();

    std::string expected = "Hello";

    EXPECT_EQ(res, expected);
}

TEST(ProjectTests, CopyAssignmentOperator)
{
    UpdatedString original("Hello");
    UpdatedString copy;

    copy = original;
    
    std::string res = copy.get();

    std::string expected = "Hello";

    EXPECT_EQ(res, expected);
}

TEST(ProjectTests, MoveConstructor)
{
    UpdatedString original("Hello");
    UpdatedString moved(std::move(original));

    std::string resOr = original.get();
    std::string resMo = moved.get();

    std::string expectedResOr = "";
    std::string expectedResMo = "Hello";

    EXPECT_EQ(resMo, expectedResMo);
    EXPECT_EQ(resOr, expectedResOr);
}

TEST(ProjectTests, MoveAssignmentOperator)
{
    UpdatedString original("Hello");
    UpdatedString moved;

    moved = std::move(original);

    std::string resOr = original.get();
    std::string resMo = moved.get();

    std::string expectedResOr = "";
    std::string expectedResMo = "Hello";

    EXPECT_EQ(resMo, expectedResMo);
    EXPECT_EQ(resOr, expectedResOr);
}

TEST(ProjectTests, ClearMethod)
{
    UpdatedString str("Hello");

    str.clear();

    std::string res = str.get();

    std::string expected = "";

    EXPECT_EQ(res, expected);
}

TEST(ProjectTests, GetMethod)
{
    UpdatedString str("Hello");

    std::string res = str.get();

    std::string expected = "Hello";

    EXPECT_EQ(res, expected);
}