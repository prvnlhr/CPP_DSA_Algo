
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = end; i >= start; i--)
#define FOREACH(x, b) for (auto x : b)

#define COUT(x) cout << x << endl;
#define N << endl;

typedef vector<int> vi;
typedef vector<int> vl;
typedef set<int> stint;
typedef map<int, int> mpint;
typedef pair<int, int> pi;
const int MOD = 1000000007;
typedef long long ll;

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

ll expon(int a, int b)
{
    if (b >= 30)
        return binpow(a, binpow(2, b, MOD - 1) + MOD - 1, MOD);

    return binpow(a, (1 << b), MOD);
}

ll euler(ll n, ll p, ll k)

{

    // int val1 = binpow(n - 1, MOD - 2, MOD) % MOD;
    // int val2 = (binpow(expon(n, k), p, MOD) - binpow(n, p - 1, MOD) + MOD) % MOD * n % MOD;

    // int pow1 = binpow(expon(n, k), p, MOD);
    // int pow2 = binpow(n, p - 1, MOD);
    // int pow3 = binpow(n - 1, MOD - 2, MOD);

    // cout << pow1 << " " << pow2 << " " << pow3 << endl;

    // int val_x = (binpow(expon(n, k), p, MOD) - binpow(n, p - 1, MOD) + MOD) % MOD * n % MOD;
    // int val_y = binpow(n - 1, MOD - 2, MOD) % MOD;

    // int val = ((pow1 - pow2 + MOD) % MOD) * (n % MOD) * (pow3 % MOD) % MOD;

    // cout << val << endl;

    // cout << (val_x * val_y) % MOD << endl;

    ll val1 = (binpow(expon(n, k), p, MOD) - binpow(n, p - 1, MOD) + MOD) % MOD * n % MOD * binpow(n - 1, MOD - 2, MOD) % MOD;
    // cout << val1 << endl;
    // cout << endl;
    return val1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        ll res = 1;
        for (ll i = 2; i * i <= n; ++i)
        {
            ll p = 0;
            while (n % i == 0)
            {
                p++;
                n = n / i;
            }
            if (p != 0)
            {
                res *= euler(i, p, k) % MOD;
            }
        }
        if (n != 1)
        {
            res *= euler(n, 1, k) % MOD;
        }

        cout << res << endl;
    }
}