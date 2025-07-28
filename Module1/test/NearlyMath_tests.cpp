#include <gtest/gtest.h>

#include "NearlyMath.hpp"
#include "NearlyMath.hpp"


class NearlyMath_test_fixture: public ::testing::Test
{
protected:
    void SetUp() override
    {

    }
    void TearDown() override
    {

    }
};

TEST_F(NearlyMath_test_fixture, ConstructorTest)
{
    nearlymath::NearlyMath MyNearlyMath;
    //ASSERT_EQ(MyNearlyMath.GetValue1(), 0);
    //ASSERT_EQ(MyNearlyMath.getValue2(), 0);  
}
