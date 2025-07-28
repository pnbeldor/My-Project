#include <iostream>
#include "NearlyMath.hpp"


using namespace nearlymath;

int NearlyMath::Add(int val1, int val2)
{
    return val1 + val2;
}

int NearlyMath::Subtract(int val1, int val2)
{
    return val1 - val2;
}

int NearlyMath::Sum()
{
    return Value1 + Value2;
}

void NearlyMath::SetValue(const int val1, const int val2)
{
    Value1 = val1;
    Value2 = val2;
}