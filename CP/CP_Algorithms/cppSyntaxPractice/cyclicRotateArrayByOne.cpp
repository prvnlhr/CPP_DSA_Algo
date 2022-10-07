

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void rotateByOne(vector<int> &arr)
{

    int i = 0;
    int j = arr.size() - 1;

    while (i < arr.size())
    {

        swap(arr[i], arr[j]);

        i++;
    }
}

int main()
{

    vector<int> arr;

    int n, a;
    cin >> n;
    while (n--)
    {
        cin >> a;
        arr.push_back(a);
    }

    rotateByOne(arr);

    for (auto ele : arr)
    {
        cout << ele << " ";
    }
}
