#include "CircularBuffer.hpp"
#include <stdexcept>
#include <vector>
#include <gtest/gtest.h>
#include <gmock/gmock.h>


class CircularBuffer_test : public testing::Test
{
public:
    void SetUp() override
    {

    }

    void TearDown() override
    {

    }
};

TEST_F(CircularBuffer_test, TEST_PUSHBACK_CHECK_HEAD)
{
    CircularBuffer<int, 5>buffer;
    buffer.push_back(1);
    EXPECT_EQ(buffer.head(), 1);
    EXPECT_EQ(buffer.tail(), 0);
    buffer.push_back(2);

    EXPECT_EQ(buffer.getsize(), 2);
    EXPECT_FALSE(buffer.empty());
}

TEST_F(CircularBuffer_test, TEST_PUSHBACK_CHECK_OVERLAP)
{
    CircularBuffer<int, 5>buffer;
    for(int i = 0; i <= 5; i++)
    {
        buffer.push_back(i);
    }
    EXPECT_EQ(buffer.head(), 1);
    EXPECT_EQ(buffer.getsize(), 5);

}

TEST_F(CircularBuffer_test, TEST_PUSHBACK_CHECK_OVERLAP_2)
{
    CircularBuffer<int, 5>buffer;
    for(int i = 0; i <= 10; i++)
    {
        buffer.push_back(i);
    }
    EXPECT_EQ(buffer.head(), 6);
}

TEST_F(CircularBuffer_test, TEST_PUSHBACK_BACK_POP)
{
    CircularBuffer<int, 5>buffer;
    std::vector<int> Expected_res{5, 6, 7, 8, 9};
    std::vector<int>result;
    for(int i = 0; i < 10; i++)
    {
        buffer.push_back(i);
    }
    while(!buffer.empty())
    {
        result.push_back(buffer.head());
        buffer.pop();
    }
    EXPECT_EQ(result, Expected_res);
}


TEST_F(CircularBuffer_test, TEST_PUSHBACK_BACK_POP_2)
{
    CircularBuffer<int, 5>buffer;
    std::vector<int> Expected_res{6, 7, 8, 9, 10};
    std::vector<int>result;
    for(int i = 0; i <= 10; i++)
    {
        buffer.push_back(i);
    }
    while(!buffer.empty())
    {
        result.push_back(buffer.head());
        buffer.pop();
    }
    EXPECT_EQ(result, Expected_res);
    EXPECT_EQ(buffer.empty(), true);
}



TEST_F(CircularBuffer_test, TEST_PUSHBACK_BACK_POP_OVERPOP_THROW)
{
    CircularBuffer<int, 5>buffer;
    std::vector<int> Expected_res{6, 7, 8, 9, 10};
    std::vector<int>result;
    for(int i = 0; i <= 10; i++)
    {
        buffer.push_back(i);
    }
    while(!buffer.empty())
    {
        result.push_back(buffer.head());
        buffer.pop();
    }
    EXPECT_EQ(result, Expected_res);
    EXPECT_THROW(buffer.pop(), std::runtime_error);
}

TEST_F(CircularBuffer_test, TEST_PUSHBACK_BACK_POP_OVERPOP_THROW_2)
{
    CircularBuffer<int, 5>buffer;
    EXPECT_THROW(buffer.pop(), std::runtime_error);
}