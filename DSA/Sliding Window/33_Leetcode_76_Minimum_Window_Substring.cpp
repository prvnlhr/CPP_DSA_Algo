
/*
|>------------------------------------------------------------------------------------------------------------------------------------------------------------
|>                               █▀ ▀█▀ █▀▀ █░░ █░░ █░█ █▀█
|>                               ▄█ ░█░ ██▄ █▄▄ █▄▄ █▀█ █▀▄
|>------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define MOD 1000000007
#define MOD1 998244353
#define PI 3.141592653589793238462

typedef long long ll;

// |> --- DEBUG_TEMPLATE_START ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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

//-- Change output format here ______________________________________________________________________________________________________________________________________________________
#define out(x) #x " = " << x << "; "

#ifndef ONLINE_JUDGE
#define debug(...) \
    cerr << "Line " << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
#else
#define debug(...)
#endif

//|> --- DEBUG_TEMPLATE_END -----------------------------------------------------------------------------------------------------------------------------------------------------------

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

//|> --- GCD -------------------------------------------------------------------
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

//|> --- EXPONENTIAL ----------------------------------------------------------
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

//|> --- FACTORIAL ------------------------------------------------------------
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

//|> --- SOLVE -----------------------------------------------------------------------------------------------------------------------------------------------
// string minWindow(string s, string t)
// {

//     map<char, int> win_freq;
//     map<char, int> t_freq;

//     for (auto ch : t)
//     {
//         t_freq[ch]++;
//     }

//     for (int i = 0; i < t.size(); i++)
//     {
//         win_freq[s[i]]++;
//     }

//     int n = s.size();

//     int minWin_s = 0;
//     int minWin_e = 0;

//     int start = 0;
//     int end = t.size();

//     int minWinSize = INT_MAX;

//     debug(t_freq, win_freq);

//     while (end < n)
//     {
//         char currCh = s[end];

//         win_freq[currCh]++;

//         if (win_freq[s[start]] > 1)
//         {
//             while (start < n)
//             {
//                 if (t_freq.find(s[start]) != t_freq.end() && win_freq[s[start]] > 1)
//                 {
//                     win_freq[s[start]]--;
//                     start++;
//                 }
//                 else if (t_freq.find(s[start]) == t_freq.end())
//                 {
//                     win_freq[s[start]]--;
//                     if (win_freq[s[start]] == 0)
//                     {
//                         win_freq.erase(s[start]);
//                     }
//                     start++;
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//         }

//         if (start - end < minWinSize)
//         {
//             minWinSize = end - start;
//             minWin_s = start;
//             minWin_e = end;
//         }
//         end++;
//     }

//     debug(minWin_s, minWin_e);
//     string res = "";
//     for (int i = minWin_s; i <= minWin_e; i++)
//     {
//         res += s[i];
//     }
//     debug(minWinSize);
//     return res;
// }

string minWindow(string s, string t)
{

    unordered_map<char, int> mpp, t_freq;
    int start = 0;
    int end = 0;
    int n = s.size();

    int minWinSize = INT_MAX;
    int ress = 0;
    int rese = 0;

    for (char ch : t)
    {
        t_freq[ch]++;
    }

    int required_cnt = t.size();
    int formed_cnt = 0;

    while (end < n)
    {
        char currCh = s[end];
        mpp[currCh]++;

        if (t_freq.find(currCh) != t_freq.end() && mpp[currCh] == t_freq[currCh])
        {
            formed_cnt++;
        }

        while (formed_cnt == required_cnt)
        {
            int currWinSize = end - start + 1;
            if (currWinSize < minWinSize)
            {
                minWinSize = currWinSize;
                ress = start;
                rese = end + 1;
            }

            char startCh = s[start];
            mpp[startCh]--;
            if (t_freq.find(startCh) != t_freq.end() && mpp[startCh] < t_freq[startCh])
            {
                formed_cnt--;
            }
            start++;
        }
        end++;
    }

    if (minWinSize == INT_MAX)
    {
        return "";
    }

    return s.substr(ress, minWinSize);
}
void solve()
{
    string s, t;
    cin >> s >> t;
    auto res = minWindow(s, t);
    debug(res);
}

//|> --- MAIN -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
