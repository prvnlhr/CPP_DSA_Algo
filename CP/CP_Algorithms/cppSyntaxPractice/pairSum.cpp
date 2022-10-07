#include <iostream>
#include <vector>
#include <map>

using namespace std;

int pairSum(vector<int> &arr, int num)
{

    map<int, int> mpp;

    int pairCount = 0;

    for (auto ele : arr)

    {

        if (mpp.find(num - ele) != mpp.end())
        {
            pairCount = pairCount + mpp[num - ele];
        }

        if (mpp.find(ele) != mpp.end())
        {

            mpp[ele] = mpp[ele] + 1;
        }
        else
        {
            mpp[ele] = 1;
        }
    }
    return pairCount;
}

int main()
{

    int n, a, num;
    cin >> n;

    vector<int> arr;
    while (n--)
    {
        cin >> a;
        arr.push_back(a);
    }
    cin >> num;
    int ans = pairSum(arr, num);
    cout << ans << endl;
}