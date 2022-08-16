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
    int SUM = 0;

    // 1 2 3 4 5
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
        SUM = SUM + arr[i];
    }

    sort(arr.begin(), arr.end());

    int MINSUM = 0;
    int cnt = 0;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        MINSUM = MINSUM + arr[i];
        cnt++;

        if (MINSUM > SUM - MINSUM)
        {
            cout << cnt << endl;
            break;
        }
    }
}
