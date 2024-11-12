#include <gtest/gtest.h>
#include "../includes/allocators/map_memory_resource.hpp"
#include "../includes/forward_list/forward_list.hpp"

TEST(ForwardListTest, DefaultConstructor)
{
    ForwardList<int> list;
    auto begin = list.Begin();
    auto end = list.End();
    EXPECT_EQ(begin, end);
}

TEST(ForwardListTest, ConstructorWithData)
{
    ForwardList<int> list(42);
    auto begin = list.Begin();
    auto expected = 42;
    EXPECT_EQ(*begin, expected);
}

TEST(ForwardListTest, PushFront)
{
    ForwardList<int> list;
    list.PushFront(1);
    list.PushFront(2);
    auto begin = list.Begin();
    auto expected = 2;
    EXPECT_EQ(*begin, expected);
}

TEST(ForwardListTest, PopFront)
{
    ForwardList<int> list;
    list.PushFront(1);
    list.PushFront(2);
    list.PopFront();
    auto begin = list.Begin();
    auto expected = 1;
    EXPECT_EQ(*begin, expected);
}

TEST(ForwardListTest, GetFront)
{
    ForwardList<int> list;
    list.PushFront(1);
    list.PushFront(2);
    auto front = list.GetFront();
    auto expected = 2;
    EXPECT_EQ(front, expected);
}

TEST(ForwardListTest, Clear)
{
    ForwardList<int> list;
    list.PushFront(1);
    list.PushFront(2);
    list.Clear();
    auto begin = list.Begin();
    auto end = list.End();
    EXPECT_EQ(begin, end);
}

TEST(ForwardListTest, Iterator)
{
    ForwardList<int> list;
    list.PushFront(1);
    list.PushFront(2);
    list.PushFront(3);

    auto it = list.Begin();
    auto expected1 = 3;
    EXPECT_EQ(*it, expected1);
    ++it;
    auto expected2 = 2;
    EXPECT_EQ(*it, expected2);
    ++it;
    auto expected3 = 1;
    EXPECT_EQ(*it, expected3);
    ++it;
    auto end = list.End();
    EXPECT_EQ(it, end);
}

TEST(ForwardListTest, EmptyIterator)
{
    ForwardList<int> list;
    auto begin = list.Begin();
    auto end = list.End();
    EXPECT_EQ(begin, end);
}

TEST(ForwardListTest, PushPopInLoop)
{
    ForwardList<int> list;
    for (int i = 0; i < 10; ++i) {
        list.PushFront(i);
    }
    for (int i = 0; i < 10; ++i) {
        auto front = list.GetFront();
        auto expected = 9 - i;
        EXPECT_EQ(front, expected);
        list.PopFront();
    }
    auto begin = list.Begin();
    auto end = list.End();
    EXPECT_EQ(begin, end);
}

TEST(ForwardListTest, CustomMemoryResource)
{
    MapMemoryResource resource;
    ForwardList<int> list(&resource);
    list.PushFront(1);
    list.PushFront(2);
    auto begin = list.Begin();
    auto expected = 2;
    EXPECT_EQ(*begin, expected);
}

TEST(ForwardListTest, PopFrontEmptyList)
{
    ForwardList<int> list;
    EXPECT_NO_THROW(list.PopFront());
}