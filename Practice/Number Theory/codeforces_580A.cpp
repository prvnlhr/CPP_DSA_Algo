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

    int cnt = 1;
    int ANS = INT_MIN;

    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];

        if (i >= 1)
        {
            // cout << arr[i - 1] << " " << arr[i] << endl;

            if (arr[i] >= arr[i - 1])
            {
                cnt++;
            }
            else
            {
                // cout << cnt << endl;
                ANS = max(ANS, cnt);
                // cout << "ANS " << ANS << endl;
                cnt = 1;
            }
            // cout << "cnt " << cnt << endl;
        }
    }

    cout << max(ANS, cnt) << endl;
}
