
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
- Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
- Output: True
- There is a subset (4, 5) with sum 9.

- Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
- Output: False
- There is no subset that add up to 30.
*/

//> RECURSIVE:: O(2^n)

bool isSubSetSumRec(vector<int> &arr, int sum, int n)
{

    if (sum == 0)
    {
        return true;
    }
    if (n == 0 && sum != 0)
    {
        return false;
    }
    debug(sum);

    if (arr[n - 1] <= sum)
    {
        bool a = isSubSetSumRec(arr, sum - arr[n - 1], n - 1);
        bool b = isSubSetSumRec(arr, sum, n - 1);
        return a || b;
    }
    else
    {
        return isSubSetSumRec(arr, sum, n - 1);
    }
}

//> MEMOIZATION::O(sum * n)
bool isSubSetSumMemo(vector<int> &arr, int sum, int n, vector<vector<int>> &dp)
{
    if (sum == 0)
    {
        return true;
    }
    if (n == 0 && sum != 0)
    {
        return false;
    }
    debug(sum);

    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }

    if (arr[n - 1] <= sum)
    {
        bool a = isSubSetSumMemo(arr, sum - arr[n - 1], n - 1, dp);
        bool b = isSubSetSumMemo(arr, sum, n - 1, dp);
        dp[n][sum] = a || b;
        return dp[n][sum];
    }
    else
    {
        return isSubSetSumMemo(arr, sum, n - 1, dp);
    }
}
//> TABULATION ITERATIVE DP::O(sum * n)
bool isSubSetSumIterative(vector<int> &arr, int sum, int n)
{
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    //> sum == 0, => true
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int s = 1; s < sum + 1; s++)
        {
            if (arr[i - 1] <= s)
            {
                dp[i][s] = dp[i - 1][s - arr[i - 1]] || dp[i - 1][s];
            }
            else
            {
                dp[i][s] = dp[i - 1][s];
            }
        }
    }
    return dp[n][sum];
}
bool isSubsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    int ansRec = isSubSetSumRec(arr, sum, n);
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    int ansMemo = isSubSetSumMemo(arr, sum, n, dp);
    int ansIter = isSubSetSumIterative(arr, sum, n);
    return ansIter;
}
void solve()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);

    FOR(i, 0, n)
    {
        int ele;
        cin >> ele;
        arr[i] = ele;
    }
    cout << isSubsetSum(arr, sum) << endl;
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
