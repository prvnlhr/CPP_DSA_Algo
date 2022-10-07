#include <bits/stdc++.h>
using namespace std;

#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = end; i >= start; i--)
#define FOREACH(x, b) for (auto x : b)

#define SUMOFN(arr) accumulate(arr.begin(), arr.end(), 0LL);

#define print1(x) cout << x << endl;
#define print2(x, y) cout << x << " " << y << endl;
#define print3(x, y, z) cout << x << " " << y << " " << z << endl;

typedef vector<int> vi;
typedef vector<int> vl;
typedef set<int> stint;
typedef map<int, int> mpint;
typedef pair<int, int> pi;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {

        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {

            cin >> a[i];
        }

        vector<ll> b(n);

        for (ll i = 0; i < n; i++)
        {

            ll p = abs(a[i] - 1);
            ll q = abs(a[i] - m);
            b[i] = max(p, q);
        }

      
        ll SUM = SUMOFN(b);
        cout << SUM << endl;
    }
}
