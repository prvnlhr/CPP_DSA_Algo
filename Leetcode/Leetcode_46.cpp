#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void helper(vector<int> arr, int indx, vector<vector<int>> &ans)
    {
        if (indx == arr.size())
        {
            ans.push_back(arr);
        }
        else
        {

            for (int i = indx; i < arr.size(); i++)
            {

                swap(arr[i], arr[indx]);
                helper(arr, indx + 1, ans);
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {

        vector<vector<int>> ans;
        helper(nums, 0, ans);
        return ans;
    }
};

int main()
{
    vector<int> arr{1, 2, 3};

    Solution *obj = new Solution();
    auto op = obj->permute(arr);
    for (auto x : op)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}
