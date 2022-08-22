#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// SOLUTION 1: using simple for loop
vector<vector<int>> mergeInterval(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> stack;

    stack.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {

        if (stack.back()[1] >= intervals[i][0])
        {

            stack.back()[1] = max(stack.back()[1], intervals[i][1]);
        }
        else
            stack.push_back(intervals[i]);
        {
        }
    }
    return stack;
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> stack;

    stack.push_back(intervals[0]);

    for (auto interval : intervals)
    {

        vector<int> stackTop = stack.back();

        if (stackTop[1] < interval[0])
        {
            stack.push_back(interval);
        }
        else
        {
            stack.back()[1] = max(stack.back()[1], interval[1]);
        }
    }

    return stack;
}
int main()
{
    vector<vector<int>> arr;
    int n;
    cin >> n;
    while (n--)
    {

        int x, y;
        cin >> x >> y;

        arr.push_back({x, y});
    }

    // mergeInterval(arr);
    merge(arr);

    // TO PRINT ARRAY OF ARRAY USING FOREACH LOOP
    // for (auto row : arr)
    // {

    //     for (auto ele : row)
    //     {
    //         cout << ele << " ";
    //     }
    //     cout << endl;
    // }
}