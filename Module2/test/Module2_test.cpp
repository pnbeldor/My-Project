#include <gtest/gtest.h>

namespace{
    int CalculateSum(int val1, int val2)
    {
        return val1 + val2;
    }
}

TEST(TestModule2, TestCalculateSum)
{
    EXPECT_EQ(CalculateSum(300, 200), 500);  
}

TEST(TesTopic, TestCalculateSum1)
{
    EXPECT_EQ(CalculateSum(300, 200), 400);  
}