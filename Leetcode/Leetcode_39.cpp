#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    void helper(vector<int> &candidates, vector<int> &temp, int x, int indx)
    {

        cout << indx << endl;

        if (x == 0)
        {
            ans.push_back(temp);
            return;
        }

        if (x < 0)
        {
            return;
        }

        if (indx == candidates.size())
        {
            return;
        }

        helper(candidates, temp, x, indx + 1);

        temp.push_back(candidates[indx]);
        helper(candidates, temp, x - candidates[indx], indx);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        ans.clear();

        vector<int> temp;
        helper(candidates, temp, target, 0);
        return ans;
    }
};

int main()
{

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
