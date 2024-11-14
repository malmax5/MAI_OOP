#include <gtest/gtest.h>
#include "../includes/allocators/map_memory_resource.hpp"

TEST(MapMemoryResourceTest, AllocateSuccess)
{
    MapMemoryResource resource;
    void* ptr = resource.allocate(100, 16);
    auto expected = nullptr;
    EXPECT_NE(ptr, expected);
    resource.deallocate(ptr, 100, 16);
}

TEST(MapMemoryResourceTest, DeallocateSuccess)
{
    MapMemoryResource resource;
    void* ptr = resource.allocate(100, 16);
    auto expected = nullptr;
    EXPECT_NE(ptr, expected);
    resource.deallocate(ptr, 100, 16);
    resource.deallocate(ptr, 100, 16);
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
TEST(MapMemoryResourceTest, AllocateInvalidAlignment)
{
    MapMemoryResource resource;
    auto expected = std::bad_alloc();
    EXPECT_THROW(resource.allocate(100, 0), decltype(expected));
}
#pragma GCC diagnostic pop

TEST(MapMemoryResourceTest, AllocateLargeMemory)
{
    MapMemoryResource resource;
    void* ptr = resource.allocate(1024 * 1024, 16);
    auto expected = nullptr;
    EXPECT_NE(ptr, expected);
    resource.deallocate(ptr, 1024 * 1024, 16);
}

TEST(MapMemoryResourceTest, ReuseDeallocatedMemory)
{
    MapMemoryResource resource;
    void* ptr1 = resource.allocate(100, 16);
    resource.deallocate(ptr1, 100, 16);
    void* ptr2 = resource.allocate(100, 16);
    auto expected = ptr1;
    EXPECT_EQ(ptr2, expected);
    resource.deallocate(ptr2, 100, 16);
}

TEST(MapMemoryResourceTest, IsEqual1)
{
    MapMemoryResource resource1;
    auto expected = true;
    EXPECT_EQ(resource1.is_equal(resource1), expected);
}

TEST(MapMemoryResourceTest, IsEqual2)
{
    MapMemoryResource resource1;
    MapMemoryResource resource2;
    auto expected = false;
    EXPECT_EQ(resource1.is_equal(resource2), expected);
}

TEST(MapMemoryResourceTest, AllocateDeallocateInLoop)
{
    MapMemoryResource resource;
    std::vector<void*> pointers;
    for (int i = 0; i < 100; ++i) {
        void* ptr = resource.allocate(100, 16);
        auto expected = nullptr;
        EXPECT_NE(ptr, expected);
        pointers.push_back(ptr);
    }
    for (void* ptr : pointers) {
        resource.deallocate(ptr, 100, 16);
    }
}

TEST(MapMemoryResourceTest, AllocateWithDifferentAlignments)
{
    MapMemoryResource resource;
    void* ptr1 = resource.allocate(100, 16);
    void* ptr2 = resource.allocate(100, 32);
    void* ptr3 = resource.allocate(100, 64);
    auto expected = nullptr;
    EXPECT_NE(ptr1, expected);
    EXPECT_NE(ptr2, expected);
    EXPECT_NE(ptr3, expected);
    resource.deallocate(ptr1, 100, 16);
    resource.deallocate(ptr2, 100, 32);
    resource.deallocate(ptr3, 100, 64);
}

TEST(MapMemoryResourceTest, PolymorphicAllocator)
{
    MapMemoryResource resource;
    std::pmr::polymorphic_allocator<int> alloc(&resource);
    int* ptr = alloc.allocate(10);
    auto expected = nullptr;
    EXPECT_NE(ptr, expected);
    alloc.deallocate(ptr, 10);
}