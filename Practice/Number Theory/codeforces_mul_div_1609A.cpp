#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define ll long long
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> arr;

        for (int i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            arr.push_back(a);
        }
        ll temp = 1;
        for (int i = 0; i < n; i++)
        {
            while (arr[i] % 2 == 0)
            {
                arr[i] /= 2;
                temp *= 2;
            }
        }

        sort(arr.begin(), arr.end());

        arr[n - 1] *= temp;

        ll SUM = 0;
        for (auto x : arr)
        {
            SUM = SUM + x;
        }
        cout << SUM << endl;
        cout << accumulate(arr.begin(), arr.end(), 0LL) << endl;
    }
}