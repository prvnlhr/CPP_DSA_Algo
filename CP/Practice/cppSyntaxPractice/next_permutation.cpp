#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void reverseArr()
{
}

void nextPer(vector<int> &nums)
{

    int len = nums.size();

    int i = len - 1;
    while (i > 0 && nums[i - 1] >= nums[i])
    {

        i--;
    }

    i = i - 1;

    int swapIndex = i;
    if (swapIndex < 0)
    {
        return;
    }
    else
    {
        int j = len - 1;
        while (nums[i] >= nums[j])
        {
            j--;
        }
        int swapIndex2 = j;
    }
}

int main()
{
    vector<int> vec1 = {1, 2, 3, 6, 5, 4};
}