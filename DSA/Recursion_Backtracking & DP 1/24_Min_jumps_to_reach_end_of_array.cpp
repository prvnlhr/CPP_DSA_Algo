
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
//|> O(2^N)
int minJumpsRec(vector<int> arr, int n, int currPos)
{
    if (currPos >= n - 1)
    {
        return 0;
    }

    int minJumps = INT_MAX;
    int maxSteps = arr[currPos];

    while (maxSteps > 0)
    {
        int currAns = 1 + minJumpsRec(arr, n, currPos + maxSteps);
        minJumps = min(minJumps, currAns);
        maxSteps = maxSteps - 1;
    }
    return minJumps;
}

//|> O(N*N)
int minJumpsDp(vector<int> arr)
{
    if (arr[0] == 0)
    {
        return 0;
    }
    int n = arr.size();

    vector<int> dp(n, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i <= j + arr[j])
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    return dp[n - 1];
}

//|> O(N)
int minJumpsGreedy(vector<int> arr)
{

    int n = arr.size();
    int left = 0;
    int right = 0;
    int minJumps = 0;

    while (right < n - 1)
    {
        int farthestReached = 0;
        for (int i = left; i < right + 1; i++)
        {
            farthestReached = max(farthestReached, arr[i] + 1);
        }
        left = right + 1;
        right = farthestReached;
        minJumps += 1;
    }
    return minJumps;
}

int minJumps(vector<int> arr)
{
    int n = arr.size();
    // return minJumpsRec(arr, n, 0);
    // return minJumpsDp(arr);
    return minJumpsGreedy(arr);
}

//|> self solved
int minJumps1(vector<int> arr, int n, int pos)
{
    if (pos >= n - 1)
    {
        return 0;
    }
    int jumpsTaken = INT_MAX;
    int maxJumps = arr[pos];
    for (int i = 1; i <= maxJumps; i++)
    {
        int a = 1 + minJumps1(arr, n, pos + i);
        jumpsTaken = min(jumpsTaken, a);
    }
    return jumpsTaken;
}

int minJumps1Dp(vector<int> arr, int n, int pos, vector<int> &dp)
{
    if (pos >= n - 1)
    {
        return 0;
    }
    if (dp[pos] != -1)
    {
        return dp[pos];
    }
    int jumpsTaken = INT_MAX;
    int maxJumps = arr[pos];
    for (int i = 1; i <= maxJumps; i++)
    {
        int a = 1 + minJumps1Dp(arr, n, pos + i, dp);
        jumpsTaken = min(jumpsTaken, a);
    }

    return dp[pos] = jumpsTaken;
}

void solve()
{
    // vector<int> jump{1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    vector<int> jump{2, 3, 1, 1, 4};
    vector<int> arr;
    // cout << minJumps(jump) << endl;
    int ele;
    while (cin >> ele)
    {
        arr.push_back(ele);
    }
    int n = arr.size();
    int ans = minJumps1(arr, n, 0);
    vector<int> dp(n + 1, -1);
    int ans1 = minJumps1Dp(arr, n, 0, dp);
    debug(ans1);
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
