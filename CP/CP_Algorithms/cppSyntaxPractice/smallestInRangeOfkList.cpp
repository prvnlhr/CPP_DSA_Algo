#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> smallestInRange(vector<vector<int>> &arr)
{
    // priority_queue<vector<int>> pq; --> if using this for min_heap then value must be negative
    // OR
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    int MIN = INT_MAX;
    int MAX = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push({arr[i][0], i, 0});
        MIN = min(MIN, arr[i][0]);
        MAX = max(MAX, arr[i][0]);
    }

    vector<int> res{MIN, MAX};

    int range = MAX - MIN;
    int max_end = MAX;

    while (!pq.empty())
    {

        auto top = pq.top();
        pq.pop();

        int val = top[0];
        int i = top[1];
        int j = top[2];
        int nxt_indx = j + 1;

        if (nxt_indx >= arr[i].size())
        {
            return res;
        }

        pq.push({arr[i][nxt_indx], i, nxt_indx});

        int new_min = pq.top()[0];

        max_end = max(max_end, arr[i][nxt_indx]);

        int new_range = max_end - new_min;

        if (new_range < range)
        {
            res[0] = new_min,
            res[1] = max_end;
            range = new_range;
        }
    }
    return res;
}

int main()
{

    vector<vector<int>> arr{{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};

    auto result = smallestInRange(arr);
    cout << result[0] << " " << result[1] << endl;
}