#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int binSeacrh(vector<int> &arr, int lo, int hi, int x)
    {

        if (lo > hi)
        {
            return -1;
        }
        int mid = (lo + hi) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }

        if (arr[lo] <= arr[mid])
        {
            if (arr[lo] <= x && x <= arr[mid])
            {

                return binSeacrh(arr, lo, mid - 1, x);
            }
            else
            {
                return binSeacrh(arr, mid + 1, hi, x);
            }
        }

        else if (arr[mid] <= arr[hi])
        {
            if (arr[mid] <= x && x <= arr[hi])
            {
                return binSeacrh(arr, mid + 1, hi, x);
            }
            else
            {
                return binSeacrh(arr, lo, mid - 1, x);
            }
        }

        return -1;
    }

    int search(vector<int> &nums, int target)
    {

        return binSeacrh(nums, 0, nums.size() - 1, target);
    }
};

int main()
{

    Solution *obj = new Solution();

    int n;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
    {

        cin >> vec[i];
    }

    int target;
    cin >> target;
    cout << obj->search(vec, target) << endl;
}