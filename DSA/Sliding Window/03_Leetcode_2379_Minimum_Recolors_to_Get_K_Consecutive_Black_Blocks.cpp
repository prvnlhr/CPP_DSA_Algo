
/*
>------------------------------------------------------------------------------------------------------------------------------------------------------------
>                               █▀ ▀█▀ █▀▀ █░░ █░░ █░█ █▀█
>                               ▄█ ░█░ ██▄ █▄▄ █▄▄ █▀█ █▀▄
>------------------------------------------------------------------------------------------------------------------------------------------------------------
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

//> TC: O(N), SC: O(1)
//> SELF SOLVED
int minimumRecolors1(string blocks, int k)
{

    /*
            EX_:
            blocks = WBBWWBBWBW
            k = 7
            OP: 3 operations


            0 1 2 3 4 5 6 7 8 10
            W B B W W B B W B W
            1 2 3 4 5 6 7
              1 2 3 4 5 6 7
                1 2 3 4 5 6 7

       */
    int winStart = 0;
    int winEnd = 0;
    int n = blocks.size();

    int res = INT_MAX;
    int w_cnt = 0;

    //> STEPS:
    //> Keep on counting W's in w_cnt.
    //> min (w_cnt,res) is ans
    //> when moving window, remove w's from winStart

    while (winStart < n && winEnd < n)
    {

        if (blocks[winEnd] == 'W')
        {
            w_cnt++;
        }
        if (winEnd - winStart + 1 == k)
        {
            res = min(res, w_cnt);
            if (blocks[winStart] == 'W')
            {
                w_cnt--;
            }
            winStart++;
            winEnd++;
        }
        else
        {
            winEnd++;
        }
    }
    return res;
}

//> SLEF SOLVED: TC:O(N), SC: O(N)
int minimumRecolors(string blocks, int k)
{
    /*
        EX_:
        WBBWWBBWBW
        7

        0 1 2 3 4 5 6 7 8 10
        5 4 4 4 3 2 2 2 1 1
        W B B W W B B W B W
        1 1 1 2 3 3 3 4 4 5
        1 2 3 4 5 6 7
          1 2 3 4 5 6 7
            1 2 3 4 5 6 7

   */

    int winStart = 0;
    int winEnd = 0;
    int n = blocks.size();

    int res = INT_MAX;
    vector<int> w_cnt(n);
    int cnt = 0;
    int prevWindWCnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (blocks[i] == 'W')
        {
            cnt++;
        }
        w_cnt[i] = cnt;
    }
    debug(w_cnt);

    while (winStart < n && winEnd < n)
    {

        if (winEnd - winStart + 1 == k)
        {
            debug(winEnd - winStart + 1);
            int cntW = w_cnt[winEnd] - prevWindWCnt;
            debug(cntW);
            res = min(res, cntW);
            prevWindWCnt = w_cnt[winStart];
            winStart++;
            winEnd++;
        }
        else
        {
            winEnd++;
        }
    }
    return res;
}
void solve()
{

    string blocks;
    cin >> blocks;
    int k;
    cin >> k;
    cout << minimumRecolors1(blocks, k) << endl;
}

//>-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("../Error.txt", "w", stderr);
    freopen("../output.txt", "w", stdout);
    freopen("../input.txt", "r", stdin);
#endif
    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration.count() / 1000 << endl;
#endif
}
