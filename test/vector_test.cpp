#include <gtest/gtest.h>
#include "vector.hpp"

TEST(VectorTest, DefaultConstructor) {
    clonestl::vector<int> v;
    EXPECT_EQ(v.size(), 0u);
    EXPECT_EQ(v.capacity(), 0u);
}

TEST(VectorTest, PushBackIncreasesSize) {
    clonestl::vector<int> v;
    v.push_back(42);
    EXPECT_EQ(v.size(), 1u);
    EXPECT_EQ(v[0], 42);
}

TEST(VectorTest, PushBackExpandsCapacity) {
    clonestl::vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    EXPECT_GE(v.capacity(), v.size());
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(v[i], i);
    }
}

TEST(VectorTest, ReserveIncreasesCapacity) {
    clonestl::vector<int> v;
    v.reserve(20);
    EXPECT_EQ(v.capacity(), 20u);
}

TEST(VectorTest, ShrinkToSizeReducesCapacity) {
    clonestl::vector<int> v;
    for (int i = 0; i < 5; ++i) v.push_back(i);
    v.reserve(20);
    EXPECT_EQ(v.capacity(), 20u);
    v.shrink_to_size();
    EXPECT_EQ(v.capacity(), v.size());
}

TEST(VectorTest, OperatorIndexing) {
    clonestl::vector<std::string> v;
    v.push_back("hello");
    v.push_back("world");
    EXPECT_EQ(v[0], "hello");
    EXPECT_EQ(v[1], "world");
}