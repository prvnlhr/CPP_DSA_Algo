
/*

 ▄▀█ █░█ █▀▄▀█ █▄░█ █▀█ █▀▄▀█
 █▀█ █▄█ █░▀░█ █░▀█ █▄█ █░▀░█

*/

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

//__________________________________________________________________________________________________________________________________________________________________________________________________

#define MOD 1000000007
#define MOD1 998244353
#define PI 3.141592653589793238462

typedef long long ll;

//>---DEBUG_TEMPLATE_START---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    return os << '{' << p.first << ", " << p.second << '}';
}

template <class T, class = decay_t<decltype(*begin(declval<T>()))>,
          class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &os, const T &c)
{
    os << '[';
    for (auto it = c.begin(); it != c.end(); ++it)
        os << &", "[2 * (it == c.begin())] << *it;
    return os << ']';
}
//__support up to 5 args
#define _NTH_ARG(_1, _2, _3, _4, _5, _6, N, ...) N
#define _FE_0(_CALL, ...)
#define _FE_1(_CALL, x) _CALL(x)
#define _FE_2(_CALL, x, ...) _CALL(x) _FE_1(_CALL, __VA_ARGS__)
#define _FE_3(_CALL, x, ...) _CALL(x) _FE_2(_CALL, __VA_ARGS__)
#define _FE_4(_CALL, x, ...) _CALL(x) _FE_3(_CALL, __VA_ARGS__)
#define _FE_5(_CALL, x, ...) _CALL(x) _FE_4(_CALL, __VA_ARGS__)
#define FOR_EACH_MACRO(MACRO, ...)                                           \
    _NTH_ARG(dummy, ##__VA_ARGS__, _FE_5, _FE_4, _FE_3, _FE_2, _FE_1, _FE_0) \
    (MACRO, ##__VA_ARGS__)

//__Change output format here
#define out(x) #x " = " << x << "; "

#ifndef ONLINE_JUDGE
#define debug(...) \
    cerr << "Line " << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
#else
#define debug(...)
#endif

//>---DEBUG_TEMPLATE_END-----------------------------------------------------------------------------------------------------------------------------------------------------------

// #define FOR(i, start, end) for (int i = start; i < end; i++)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define RFOR(i, start, end) for (int i = end; i >= start; i--)
#define FOREACH(x, b) for (auto x : b)

#define cout1(x) cout << x << endl;
#define cout2(x, y) cout << x << " " << y << endl;
#define cout3(x, y, z) cout << x << " " << y << " " << z << endl;

#define SUMOFN(arr) accumulate(arr.begin(), arr.end(), 0LL);
#define SORTASC(arr) sort(arr.begin(), arr.end());
#define SORTDSC(arr) sort(arr.begin(), arr.end(), greater<int>());
#define REV(arr) reverse(arr.begin(), arr.end());

#define strLow(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define strUp(s) transform(s.begin(), s.end(), s.begin(), ::toupper);

#define lb(arr, ele) lower_bound(arr.begin(), arr.end(), ele);
#define ub(arr, ele) upper_bound(arr.begin(), arr.end(), ele);

typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> stint;
typedef map<int, int> mpint;
typedef pair<int, int> pi;
typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;
//_____________________________
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
//_____________________________
ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
//__factorial______________________________________________
vector<ll> fact;
void factOfN(ll n)
{
    ll prod = 1;
    fact.resize(n + 1);
    for (int f = 1; f <= n; f++)
    {

        fact[f] = prod * f;
        prod = prod * f;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------

//>----------------------------ＳＯＬＶＥ-----------------------------------------------------------------------------------------------------------------------------------------------
/*
** You can buy N numbers of shares, but can hold only one at time
** first you buy then you sell, then you can again buy and again sell ....

- You are given an integer array prices where prices[i] is
- the price of a given stock on the ith day.
-
- On each day, you may decide to buy and/or sell the stock.
- You can only hold at most one share of the stock at any time.
- However, you can buy it then immediately sell it on the same day.
-
- Find and return the maximum profit you can achieve.

-> Example 1:
-> Input: prices = [7,1,5,3,6,4]
-> Output: 7
- Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
- Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
- Total profit is 4 + 3 = 7.
-
-> Example 2:
->Input: prices = [1,2,3,4,5]
-> Output: 4
- Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
- Total profit is 4.
-
-> Example 3:
-> Input: prices = [7,6,4,3,1]
-> Output: 0
- Explanation: There is no way to make a positive profit, so we never buy
- the stock to achieve the maximum profit of 0.
-> Example 4:
-> Input: prices = [6,1,3,2,4,7]
-> Output: 7

- O(N) VALLEY PEAK algorithm.
- In this approach, we just need to find the next greater element
- and subtract it from the current element so that the difference
- keeps increasing until we reach a minimum. If the sequence is a
- decreasing sequence so the maximum profit possible is 0.
*/

/*
 * SLEF SOLVED LEETCODE 100%
 */

int maxProfit(vector<int> &prices)
{
    int maxPro = 0;
    int buyPrice = prices[0];
    int profitUntil = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        int currProfit = prices[i] - buyPrice;

        if (currProfit >= profitUntil)
        {
            profitUntil = currProfit;
        }
        else if (currProfit < profitUntil)
        {
            maxPro += profitUntil;
            buyPrice = prices[i];
            profitUntil = 0;
        }
    }
    maxPro += profitUntil;

    debug(maxPro);
    return maxPro;
}

void solve()
{
    int ele;
    vector<int> prices;
    while (cin >> ele)
    {
        prices.push_back(ele);
    }

    cout << maxProfit(prices) << endl;
}

//>-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("../../Error.txt", "w", stderr);
    freopen("../../output.txt", "w", stdout);
    freopen("../../input.txt", "r", stdin);
#endif
    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration.count() / 1000 << endl;
#endif
}
