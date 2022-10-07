#include <bits/stdc++.h>
using namespace std;

#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = end; i >= start; i--)
#define FOREACH(x, b) for (auto x : b)

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

        ll n, k, b, s;
        cin >> n >> k >> b >> s;

        ll lastVal = k * b;

        if (lastVal < 0)
        {
            cout << -1 << endl;
        }
        else
        {

            vector<ll> arr(n);

            arr[n - 1] = lastVal;

            ll eachVal = (s - lastVal) / (n - 1);

            ll rem = (s - lastVal) % (n - 1);

            for (ll i = 0; i < n - 1; i++)
            {
                arr[i] = eachVal;
            }
            arr[0] = arr[0] + rem;
                        

            for (auto x : arr)
            {
                cout << x << " ";
            }
        }
    }
}
