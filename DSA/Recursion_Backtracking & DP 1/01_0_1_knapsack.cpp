
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

//>----------------------------ＳＯＬＶＥ-----------------------------------------------------------------------------------------------------------------------------------------------

/*
- A thief robbing a store can carry a maximal weight of W into his knapsack.
- There are N items, and i-th item weigh 'Wi' and the value being 'Vi.'
- What would be the maximum value V, that the thief can steal?
- Examples::
- Input 1:
- 4
- V --> 5 4 8 6
- W --> 1 2 4 5
- maxW --> 5
- output 1: 13
-
- Input 2:
- 5
- 24 13 23 15 16
- 12 7 11 8 9
- 26
- output 2: 51
*/

// ___________________________________________________________________________________
/*
: Time Complexity: O(2^N)
: Auxiliary Space: O(N), Stack space required for recursion
*/
int knapSackRec(vector<int> weights, vector<int> values, int maxW, int i, int n)
{
    if (maxW == 0 || i == n)
    {
        return 0;
    }

    if (weights[i] <= maxW)
    {
        return max(values[i] + knapSackRec(weights, values, maxW - weights[i], i + 1, n), knapSackRec(weights, values, maxW, i + 1, n));
    }
    else
    {
        return knapSackRec(weights, values, maxW, i + 1, n);
    }
}
// # without using ith pointer

int knapSackRec1(vector<int> weights, vector<int> values, int maxW, int n)
{
    if (maxW == 0 || n <= 0)
    {
        return 0;
    }

    if (weights[n - 1] <= maxW)
    {
        int ans1 = values[n - 1] + knapSackRec1(weights, values, maxW - weights[n - 1], n - 1);
        int ans2 = knapSackRec1(weights, values, maxW, n - 1);
        return max(ans1, ans2);
    }
    else
    {
        return knapSackRec1(weights, values, maxW, n - 1);
    }
}

// ___________________________________________________________________________________

//> MEMOIZATION

int knapSackMemo(vector<int> weights, vector<int> values, int maxW, int n, vector<vector<int>> DP)
{
    if (maxW == 0 || n < 0)
    {
        return 0;
    }

    if (DP[n][maxW] != -1)
    {
        return DP[n][maxW];
    }

    if (weights[n] <= maxW)
    {
        return DP[n][maxW] = max(values[n] + knapSackMemo(weights, values, maxW - weights[n], n - 1, DP), knapSackMemo(weights, values, maxW, n - 1, DP));
    }
    int ans = knapSackMemo(weights, values, maxW, n - 1, DP);
    DP[n][maxW] = ans;
    return ans;
}
// ______________________________________________________________________________________
//> Iterative Dp

int knapSackIter(vector<int> weights, vector<int> values, int maxW)
{

    /*
    >   In iterative DP sol, following changes are made
    ->  maxWeight -> w
    ->  n -> i
    ->  function call becomes -> dp[][]
    */

    int n = weights.size();
    vector<vector<int>> Dp(n + 1, vector<int>(maxW + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int w = 1; w < maxW + 1; w++)
        {
            if (weights[i - 1] <= w)
            {
                int a = values[i - 1] + Dp[i - 1][w - weights[i - 1]];
                int b = Dp[i - 1][w];
                Dp[i][w] = max(a, b);
            }
            else
            {
                Dp[i][w] = Dp[i - 1][w];
            }
        }
    }

    return Dp[n][maxW];
}

// ___________________________________________________________________________________
int knapsack(vector<int> weights, vector<int> values, int maxW)
{

    int n = weights.size();
    // int ans1 = knapSackRec(weights, values, maxW, 0, n);
    // int ans2 = knapSackRec1(weights, values, maxW, n);

    vector<vector<int>> DP(n + 1, vector<int>(maxW + 1, -1));
    // int ans3 = knapSackMemo(weights, values, maxW, n - 1, DP);
    int ans4 = knapSackIter(weights, values, maxW);
    return ans4;
}
void solve()
{

    vector<int> weights{1, 2, 4, 5};
    vector<int> values{5, 4, 8, 6};
    int maxW = 5;
    cout << knapsack(weights, values, maxW);
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
