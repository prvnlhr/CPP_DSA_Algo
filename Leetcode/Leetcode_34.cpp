#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int binSearch1(vector<int> &arr, int x, int lo, int hi)
    {

        int ptr = -1;
        while (lo <= hi)
        {

            int mid = (lo + hi) / 2;

            if (arr[mid] >= x)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
            if (arr[mid] == x)
            {
                ptr = mid;
            }
        }

        return ptr;
    }
    int binSearch2(vector<int> &arr, int x, int lo, int hi)
    {

        int ptr = -1;
        while (lo <= hi)
        {

            int mid = (lo + hi) / 2;
            if (arr[mid] <= x)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
            if (arr[mid] == x)
            {
                ptr = mid;
            }
        }
        return ptr;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = binSearch1(nums, target, 0, nums.size() - 1);
        int second = binSearch2(nums, target, 0, nums.size() - 1);
        vector<int> op{first, second};
        return op;
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
    auto op = obj->searchRange(vec, target);
    cout << op[0] << " " << op[1] << endl;
}
