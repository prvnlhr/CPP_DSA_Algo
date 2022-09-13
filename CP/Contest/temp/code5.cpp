

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        ll n;
        cin >> n;
        vector<ll> arr(n);

        map<ll, ll> mpp;
        for (int i = 0; i < n; i++)
        {

            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {

            mpp[arr[i]]++;
        }

        ll ans = 0;
        for (auto x : mpp)
        {

            if (x.second >= 2)
            {

                ll val = x.second - 1;
                ll v = (val * (val + 1)) / 2;
                // for (int i = x.second - 1; i >= 0; i--)
                // {

                //     val += i;
                // }
                ans += v;
            }

            // cout << x.first << " " << x.second << endl;
        }

        cout << ans << endl;
    }
}
