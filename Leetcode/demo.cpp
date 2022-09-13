#include <iostream>
#include <vector>
using namespace std;

int lower_bound(vector<int> &nums, int target)
{

    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int mid = (r + l) / 2;

        if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

int main()
{

    int n = 5;
    vector<int> arr{1, 2, 3, 4, 5};
    // vector<int>arr{1,2,2,4,5};
    // vector<int> arr{2, 2, 2, 2, 2};
    // vector<int> arr{2, 2};
    // vector<int> arr{1, 2};

    cout << lower_bound(arr, 6) << endl;
}

/ << endl;

vector<int> searchRange(vector<int> &nums, int target)
{
    int idx1 = lower_bound(nums, target);
    int idx2 = lower_bound(nums, target + 1) - 1;
    if (idx1 < nums.size() && nums[idx1] == target)
        return {idx1, idx2};
    else
        return {-1, -1};
}

int lower_bound(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int mid = (r - l) / 2 + l;
        if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}