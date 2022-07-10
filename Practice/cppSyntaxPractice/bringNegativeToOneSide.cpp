#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// # Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
// #Output : -12, - 6, -13, -5, -3, -7, 5, 6, 11
void negativesToOneSide(vector<int> &arr)
{

    int negIndex = 0;
    int posIndex = arr.size() - 1;

    while (negIndex < posIndex)
    {

        if (arr[negIndex] < 0 && arr[posIndex] < 0)
        {
            negIndex++;
        }
        else if (arr[negIndex] > 0 && arr[posIndex] < 0)
        {
            swap(arr[negIndex], arr[posIndex]);
            negIndex++;
            posIndex--;
        }
        else if (arr[negIndex] < 0 && arr[posIndex] > 0)
        {
            negIndex++;
            posIndex--;
        }
        else if (arr[negIndex] > 0 && arr[posIndex] > 0)
        {
            posIndex--;
        }
    }
}

int main()
{

    int n, a;
    vector<int> arr;
    cin >> n;

    while (n--)
    {
        cin >> a;
        arr.push_back(a);
    }
    negativesToOneSide(arr);

    for (auto c : arr)
    {
        cout << c << " ";
    }
}