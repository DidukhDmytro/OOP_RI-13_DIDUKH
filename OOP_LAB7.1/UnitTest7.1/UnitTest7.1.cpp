#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <algorithm>
#include <numeric>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

double averageIndexesOfMinMax(const vector<int>& a)
{
    auto minIt = min_element(a.begin(), a.end());
    auto maxIt = max_element(a.begin(), a.end());

    int minIndex = distance(a.begin(), minIt);
    int maxIndex = distance(a.begin(), maxIt);

    vector<int> indexes = { minIndex, maxIndex };

    int sum = accumulate(indexes.begin(), indexes.end(), 0);

    return sum / 2.0;
}

namespace UnitTestLab71
{
    TEST_CLASS(AverageIndexTests)
    {
    public:

        TEST_METHOD(AverageIndexesCommonCase)
        {
            vector<int> a = { 5, 10, 3, 8 };

            double result = averageIndexesOfMinMax(a);

            Assert::AreEqual(1.5, result);
        }

        TEST_METHOD(MinBeforeMax)
        {
            vector<int> a = { -10, 4, 7, 100, 2 };

            double result = averageIndexesOfMinMax(a);

            Assert::AreEqual(1.5, result);
        }

        TEST_METHOD(MaxBeforeMin)
        {
            vector<int> a = { 50, 4, 7, -20, 2 };

            double result = averageIndexesOfMinMax(a);

            Assert::AreEqual(1.5, result);
        }

        TEST_METHOD(OneElementVector)
        {
            vector<int> a = { 25 };

            double result = averageIndexesOfMinMax(a);

            Assert::AreEqual(0.0, result);
        }

        TEST_METHOD(MinAndMaxAtEnds)
        {
            vector<int> a = { -5, 10, 15, 20 };

            double result = averageIndexesOfMinMax(a);

            Assert::AreEqual(1.5, result);
        }

        TEST_METHOD(AllElementsEqual)
        {
            vector<int> a = { 7, 7, 7, 7 };

            double result = averageIndexesOfMinMax(a);

            Assert::AreEqual(0.0, result);
        }
    };
}