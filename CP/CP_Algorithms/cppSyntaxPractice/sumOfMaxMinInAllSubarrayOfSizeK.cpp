#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int sumMinMax(vector<int> &arr, int k)
{

    int n = arr.size();

    deque<int> minQ;
    deque<int> maxQ;

    int SUM = 0;

    for (int i = 0; i < n; i++)
    {

        if (!minQ.empty() && minQ.front() <= i - k)
        {
            minQ.pop_front();
        }

        if (!maxQ.empty() && maxQ.front() <= i - k)
        {
            maxQ.pop_front();
        }

        while (!minQ.empty() && arr[minQ.back()] >= arr[i])
        {
            minQ.pop_back();
        }

        while (!maxQ.empty() && arr[maxQ.back()] <= arr[i])
        {
            maxQ.pop_back();
        }

        minQ.push_back(i);
        maxQ.push_back(i);

        if (i >= k - 1)
        {
            int minCurr = arr[minQ.front()];
            int maxCurr = arr[maxQ.front()];
            SUM = SUM + minCurr + maxCurr;
        }
    }

    return SUM;
}

int main()
{

    vector<int> arr{2, 5, -1, 7, -3, -1, -2};

    int k = 4;
    int ans = sumMinMax(arr, k);
    cout << ans << endl; // slow
    cout << ans << "\n"; // fast
}