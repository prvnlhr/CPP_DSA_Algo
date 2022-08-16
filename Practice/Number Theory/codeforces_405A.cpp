#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}
