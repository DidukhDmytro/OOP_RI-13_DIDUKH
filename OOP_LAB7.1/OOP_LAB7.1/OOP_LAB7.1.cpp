#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <numeric>

using namespace std;

int RandomNumber()
{
    return rand() % 101 - 50;
}

void print(const vector<int>& a)
{
    for_each(a.begin(), a.end(),
        [](int x)
        {
            cout << x << " ";
        });

    cout << endl;
}

double averageIndexesOfMinMax(const vector<int>& a)
{
    auto minIt = min_element(a.begin(), a.end());
    auto maxIt = max_element(a.begin(), a.end());

    int minIndex = distance(a.begin(), minIt);
    int maxIndex = distance(a.begin(), maxIt);

    cout << "Min element = " << *minIt << endl;
    cout << "Min index = " << minIndex << endl;

    cout << "Max element = " << *maxIt << endl;
    cout << "Max index = " << maxIndex << endl;

    vector<int> indexes = { minIndex, maxIndex };

    int sum = accumulate(indexes.begin(), indexes.end(), 0);

    return sum / 2.0;
}

int main()
{
    srand((unsigned int)time(NULL));

    int n;

    cout << "n = ";
    cin >> n;

    vector<int> a(n);

    generate(a.begin(), a.end(), RandomNumber);

    cout << "Array:" << endl;
    print(a);

    double avg = averageIndexesOfMinMax(a);

    cout << "Average of indexes = " << avg << endl;

    return 0;
}