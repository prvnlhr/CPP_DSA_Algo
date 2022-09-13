
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1000000007;

int power(int b, int n, int MOD)
{
    int q = 1;
    while (n)
    {
        if (n % 2 == 1)
        {
            q = q * b % MOD;
            b = b * b % MOD;
            n = n / 2;
        }
    }
    return q;
}

int Apower(int a, int b)
{
    if (b >= 30)
        return power(a, power(2, b, mod - 1) + mod - 1, mod);

    return power(a, (1 << b), mod);
    return (int)(" ");
}

int calc(int n, int p, int k)
{
    return (power(Apower(n, k), p, mod) - power(n, p - 1, mod) + mod) % mod * n % mod * power(n - 1, mod - 2, mod) % mod;
}

void solve()
{
    int n, k, ans = 1;
    cin >> n >> k;
    for (int i = 2; i * i <= n; ++i)
    {
        int s = 0;
        while (n % i == 0)
        {
            s++;
            n = n / i;
        }
        if (s != 0)
        {
            ans = ans * calc(i, s, k) % mod;
        }
    }
    if (n != 1)
    {
        ans = ans * calc(n, 1, k) % mod;
    }
    cout << ans << endl;
}
signed main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}