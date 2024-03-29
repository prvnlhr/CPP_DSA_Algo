#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans; // 2 D vector to store our answer
    void solve(int i, vector<int> &arr, vector<int> &temp, int target)
    {
        cout << i << endl;
        // if our target becomes zero at any point, then yess!! we wil find a possible combination
        if (target == 0)
        {
            ans.push_back(temp); // include that combination in our answer
            return;              // and then return, we are now not gonna explore more possiblity
        }

        // if at any point target becomes less than zero, then simply return, saying that no it is notpossible to our target combination sum
        if (target < 0)
            return;

        // if index crosses the last index, we will return saying that no more element is left to choosee
        if (i == arr.size())
            return;

        // As we dicussed for every element we have two choices whether to include in our answer or not include in our answer.
        // so now, we are doing that

        // we are not taking the ith element,
        // so without decreasing sum we will move to next index because it will not contribute in making our sum
        solve(i + 1, arr, temp, target);
        temp.push_back(arr[i]);               // including ith element
        solve(i, arr, temp, target - arr[i]); // decreasing sum,and call again function
        temp.pop_back();                      // backtrack
    }
    vector<vector<int>> combinationSum(vector<int> &arr, int target)
    {
        ans.clear(); // clear global array, make to sure that no garbage value is present in it

        vector<int> temp; // temporary vector that tries all possible combination

        solve(0, arr, temp, target); // calling function, and see we start from index zero

        return ans; // finally return the answer array
    }
};

int main()
{

    // vector<int> candidates{2, 3, 6, 7};
    vector<int> candidates{2, 3, 5};
    int target = 8;

    Solution *obj = new Solution();

    auto op = obj->combinationSum(candidates, target);

    for (auto x : op)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}
