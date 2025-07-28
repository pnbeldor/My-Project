#pragma once

namespace nearlymath
{
    class NearlyMath
    {
    public:
        int Add(int val1, int val2);
        int Subtract(int val1, int val2);
        int Sum();

        void SetValue(const int val1, const int val2);

        int GetValue1() const;
        int getValue2() const;

    private:
        int Value1;
        int Value2;

    };
} //namespace nearlymath

