

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll powX(ll a, ll b)
{

    if (b >= 30)
    {
        return binpow(a, binpow(2, b, MOD - 1), MOD);
    }
    return binpow(a, (1 << b), MOD);
    return 0;
}

int solve(int n, int k, int p)
{
    return (binpow(powX(n, k), p, MOD) - binpow(n, p - 1, MOD) % MOD * n % MOD * binpow(n - 1, MOD - 2, MOD) % MOD);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        int res;
        int n, k;
        cin >> n >> k;
        for (int i = 2; i * i <= n; i++)
        {
            int s = 0;
            while (n % i == 0)
            {
                s++;
                n /= i;
            }
            if (s != 0)
            {
                res = res * solve(i, s, k) % MOD;
            }
        }
        if (n != 1)
        {
            res = res * solve(n, 1, k) % MOD;
        }
        cout << res << endl;
    }
}
