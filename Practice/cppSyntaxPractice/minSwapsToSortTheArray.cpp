#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

// arr = [8, 3, 14, 17, 15, 1, 12]

int getIndexFromMap(int ele, map<int, int> mpp)
{
    return mpp[ele];
}

void swapEle(int i, int j, vector<int> &arr)
{

    swap(arr[i], arr[j]);
}

int minSwapsToSortArray(vector<int> &arr)
{

    vector<int> sortedArr = arr;

    sort(sortedArr.begin(), sortedArr.end());

    map<int, int> mpp;

    for (int i = 0; i < arr.size(); i++)
    {
        mpp[arr[i]] = i;
    }

    int numSwaps = 0;

    for (int currIndex = 0; currIndex < arr.size(); currIndex++)
    {

        if (arr[currIndex] != sortedArr[currIndex])
        {
            numSwaps++;

            int originalEle = arr[currIndex];
            int replaceWithEle = sortedArr[currIndex];

            int new_index = getIndexFromMap(replaceWithEle, mpp);

            swapEle(currIndex, new_index, arr);
            mpp[originalEle] = new_index;
            mpp[replaceWithEle] = currIndex;
        }
    }
    return numSwaps;
}

int main()
{

    // int n, a;

    // cin >> n;

    vector<int> arr{8, 3, 14, 17, 15, 1, 12};

    // while (n--)
    // {

    //     cin >> a;
    //     arr.push_back(a);
    // }

    int ans = minSwapsToSortArray(arr);

    cout << "number of swaps to sort array :" << ans;
}