
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
const int mod = 1000000007;
typedef long long ll;

// long long binpow(long long a, long long b, long long m)
// {
//     int q = 1;
//     while (b)
//     {
//         if (b % 2 == 1)
//         {
//             q = q * a % m;
//             a = a * a % m;
//             b = b / 2;
//         }
//     }
//     return q;
// }

int binpow(int b, int n, int MOD)
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

int expon(int a, int b)
{
    if (b >= 30)
        return binpow(a, binpow(2, b, mod - 1) + mod - 1, mod);

    return binpow(a, (1 << b), mod);
}

int euler(int n, int p, int k)

{

    // int val1 = binpow(n - 1, mod - 2, mod) % mod;
    // int val2 = (binpow(expon(n, k), p, mod) - binpow(n, p - 1, mod) + mod) % mod * n % mod;

    // int pow1 = binpow(expon(n, k), p, mod);
    // int pow2 = binpow(n, p - 1, mod);
    // int pow3 = binpow(n - 1, mod - 2, mod);

    // cout << pow1 << " " << pow2 << " " << pow3 << endl;

    // int val_x = (binpow(expon(n, k), p, mod) - binpow(n, p - 1, mod) + mod) % mod * n % mod;
    // int val_y = binpow(n - 1, mod - 2, mod) % mod;

    // int val = ((pow1 - pow2 + mod) % mod) * (n % mod) * (pow3 % mod) % mod;

    // cout << val << endl;

    // cout << (val_x * val_y) % mod << endl;

    int val1 = (binpow(expon(n, k), p, mod) - binpow(n, p - 1, mod) + mod) % mod * n % mod * binpow(n - 1, mod - 2, mod) % mod;
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
        for (int i = 2; i * i <= n; ++i)
        {
            int p = 0;
            while (n % i == 0)
            {
                p++;
                n = n / i;
            }
            if (p != 0)
            {
                res *= euler(i, p, k) % mod;
            }
        }
        if (n != 1)
        {
            res *= euler(n, 1, k) % mod;
        }

        cout << res << endl;
    }
}
