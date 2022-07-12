#include <iostream>
#define ll long long
using namespace std;
ll binpower(ll a, ll b, ll m)
{

    a = a % m;
    ll res = 1;
    while (b > 0)
    {

        if (b % 2 == 1)
        {

            res = res * a % m;
        }
        a = a * a % m;
        b = b / 2;
    }

    return res;
}
int main()
{

    ll n, k;
    ll mod = 1e7 + 7;

    while (cin >> n >> k)
    {

        if (n == 0 && k == 0)
            return 0;
        ll a, b, c, d;
        a = (2 * binpower((n - 1), k, mod));
        b = (2 * binpower(n - 1, n - 1, mod));
        c = (binpower(n, k, mod));
        d = (binpower(n, n, mod));
        ll res = (a + b + c + d) % mod;
        cout << res << endl;
    }
}
