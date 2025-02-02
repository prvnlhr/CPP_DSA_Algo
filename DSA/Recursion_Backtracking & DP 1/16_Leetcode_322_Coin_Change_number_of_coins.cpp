
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

template <class T, class = decltype(begin(declval<T>())),
          class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &os, const T &c)
{
    os << '[';
    for (auto it = begin(c); it != end(c); ++it)
        os << (it == begin(c) ? "" : ", ") << *it;
    return os << ']';
}

#define _NTH_ARG(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N
#define _FE_1(_CALL, x) _CALL(x)
#define _FE_2(_CALL, x, ...) _CALL(x) _FE_1(_CALL, __VA_ARGS__)
#define _FE_3(_CALL, x, ...) _CALL(x) _FE_2(_CALL, __VA_ARGS__)
#define _FE_4(_CALL, x, ...) _CALL(x) _FE_3(_CALL, __VA_ARGS__)
#define _FE_5(_CALL, x, ...) _CALL(x) _FE_4(_CALL, __VA_ARGS__)
#define _FE_6(_CALL, x, ...) _CALL(x) _FE_5(_CALL, __VA_ARGS__)
#define _FE_7(_CALL, x, ...) _CALL(x) _FE_6(_CALL, __VA_ARGS__)
#define _FE_8(_CALL, x, ...) _CALL(x) _FE_7(_CALL, __VA_ARGS__)
#define _FE_9(_CALL, x, ...) _CALL(x) _FE_8(_CALL, __VA_ARGS__)
#define _FE_10(_CALL, x, ...) _CALL(x) _FE_9(_CALL, __VA_ARGS__)
#define FOR_EACH_MACRO(MACRO, ...)                                                               \
    _NTH_ARG(__VA_ARGS__, _FE_10, _FE_9, _FE_8, _FE_7, _FE_6, _FE_5, _FE_4, _FE_3, _FE_2, _FE_1) \
    (MACRO, __VA_ARGS__)

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
//--------------------------------------------------------------------------------------------------------------------------------

//> ----------------------------ＳＯＬＶＥ-----------------------------------------------------------------------------------------------------------------------------------------------
/*
- You are given an integer array coins representing coins of different
- denominations and an integer amount representing a total amount of money.
- Return the fewest number of coins that you need to make up that amount.
- If that amount of money cannot be made up by any combination
- of the coins, return -1.

- You may assume that you have an infinite number of each
- kind of coin.

- Examples:
-> Input: coins[] = {25, 10, 5}, amount = 30
-> Output: Minimum 2 coins required
- 10+10+10 = 30 , 3 coins
- 25+5 = 30 , 2 coins
- 5+5+5+5+5+5 = 30 , 6 coins
- We can use one coin of 25 cents and one of 5 cents , we will get minimum no. of coins
-
-> Input: coins[] = {9, 6, 5, 1}, amount = 11
-> Output: Minimum 2 coins required
- We can use one coin of 6 cents and 1 coin of 5 cents

- Example 1:
-> Input: coins = [1,2,5], amount = 11
-> Output: 3
- Explanation: 11 = 5 + 5 + 1

- Example 2:
-> Input: coins = [2], amount = 3
-> Output: -1

- Example 3:
-> Input: coins = [1], amount = 0
-> Output: 0
*/

/*
> Recursive naive
: TC : O(2^N) -> its actually more then 2^N, because of case when we take a coin, we can again take it
: SC: O(N) -> More then N,  because of case when we take a coin, we can again take it
*/

int coinChangeRec(vector<int> coins, int amount, int n)
{
    if (amount == 0)
    {
        return 0;
    }
    if (amount < 0 || n < 0)
    {
        return 1e9;
    }
    int take = 1 + coinChangeRec(coins, amount - coins[n], n);
    int not_take = coinChangeRec(coins, amount, n - 1);
    return min(take, not_take);
}

/*
> Recursive naive
: TC : O(2^N) -> its actually more then 2^N, because of case when we take a coin, we can again take it
: SC: O(N) -> More then N,  because of case when we take a coin, we can again take it
*/

int coinChangeMemo(vector<int> &coins, int amount, int n, vector<vector<int>> &dp)
{
    //> base case: amount becomes -> 0
    if (amount == 0)
    {
        return 0;
    }

    //* edge case: we were not able to make the denominations
    if (amount < 0 || n < 0)
    {
        return 1e9;
    }
    if (dp[n][amount] != -1)
    {
        return dp[n][amount];
    }
    int not_take = coinChangeMemo(coins, amount, n - 1, dp);
    int take = 1 + coinChangeMemo(coins, amount - coins[n], n, dp);
    dp[n][amount] = min(take, not_take);
    return dp[n][amount];
}

/*
> Iter DP : O(n*n)
::TODO
*/

int coinChange(int n, int amount, vector<int> &coins)
{
    // int ans = coinChangeRec(coins, amount, n - 1);
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    int ans = coinChangeMemo(coins, amount, n - 1, dp);
    //> if we were able to make deno,
    if (ans < 1e9)
    {
        return ans;
    }
    return -1;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins;
    int cn;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        coins.push_back(ele);
    }
    debug(coins);
    cout << coinChange(n, x, coins) << endl;
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
    auto now = system_clock::to_time_t(system_clock::now());
    stringstream timeStream;

    timeStream << put_time(localtime(&now), "%d %b %Y %H:%M:%S");
    string formatted_time = timeStream.str();

#ifndef ONLINE_JUDGE
    cerr << endl;
    cerr << "Exec Time: " << duration.count() / 1000 << " ms" << endl;
    cerr << "Curr Time: " << formatted_time << endl;
#endif
}
