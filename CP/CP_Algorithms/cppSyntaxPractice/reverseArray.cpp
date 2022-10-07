#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &nums, int len)
{

    int start = 0;
    int end = len - 1;

    while (start < end)
    {

        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;

        start++;
        end--;
    }
}

void reverse()
{

    vector<int> arr{1, 2, 3, 4, 5};

    for (int i = 0; i < arr.size(); i++)
    {

        cout << arr[i];
    }
}

int main()
{

    vector<int> arr;

    int n, num;
    cin >> n;

    while (n > 0)
    {
        cin >> num;
        arr.push_back(num);
        n--;
    }

    reverseArray(arr, arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}