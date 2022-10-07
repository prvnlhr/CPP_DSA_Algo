

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {
        int p, q, r;
        cin >> p >> q >> r;

        ll res = 1;

        for (int i = 0; i < 20; i++)
        {

            int cnt = 0;

            int mask = (1 << i);

            cnt += (p & mask) > 0;
            cnt += (q & mask) > 0;
            cnt += (r & mask) > 0;

            if (cnt == 0)
            {
                res *= 1;
            }
            else if (cnt == 1)
            {
                res = 0;
            }
            else if (cnt == 2)
            {
                res *= 1;
            }
            else if (cnt == 3)
            {
                res *= 4;
            }
        }
        cout << res << endl;
    }
}
