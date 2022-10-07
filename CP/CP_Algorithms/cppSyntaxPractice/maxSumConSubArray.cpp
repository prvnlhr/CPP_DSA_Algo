#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumSubArray(vector<int> &arr)
{

    int max_sum_so_far = arr[0];
    int max_sum_end_here = arr[0];

    for (int i = 1; i < arr.size(); i++)

    {
        max_sum_end_here = max(arr[i], arr[i] + max_sum_end_here);
        max_sum_so_far = max(max_sum_end_here, max_sum_so_far);
    }

    return max_sum_so_far;
}

int main()
{

    vector<int> arr;
    // arr = [1, 2, -3, 4, 5, -2, 6, 5]

    int a, n;
    cin >> n;
    while (n--)
    {

        cin >> a;
        arr.push_back(a);
    }

    int ans = maxSumSubArray(arr);

    cout << ans << " ";
}