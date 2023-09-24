
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

// |> ---DEBUG_TEMPLATE_START---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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

//__Change output format here______________________________________________________________________________________________________________________________________________________
#define out(x) #x " = " << x << "; "

#ifndef ONLINE_JUDGE
#define debug(...) \
    cerr << "Line " << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
#else
#define debug(...)
#endif

//|> ---DEBUG_TEMPLATE_END-----------------------------------------------------------------------------------------------------------------------------------------------------------

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

//|> ---ＳＯＬＶＥ-----------------------------------------------------------------------------------------------------------------------------------------------

pair<int, int> getVersion(string s, int currIndx)
{
    int ver = 0;
    debug(currIndx);
    while (currIndx < s.size() && s[currIndx] != '.')
    {
        char ch = s[currIndx];
        int intOfCh = ch - '0';
        ver = ver * 10 + intOfCh;
        currIndx++;
    }
    if (s[currIndx] == '.')
    {
        currIndx++;
    }
    debug(s, currIndx, ver);
    cerr << endl;

    return {ver, currIndx};
}

int compareVersion(string version1, string version2)
{
    int i = 0;
    int j = 0;
    int currIndex = 0;
    int n1 = version1.size();
    int n2 = version2.size();

    while (i < n1 && j < n2)
    {
        auto num1 = getVersion(version1, i);

        auto num2 = getVersion(version2, j);

        if (num1.first < num2.first)
        {
            return -1;
        }
        else if (num1.first > num2.first)
        {
            return 1;
        }
        else
        {
            i = num1.second;
            j = num2.second;
        }
        debug(i, j);
    }

    cerr << endl;
    debug("end of loop--", n1, i, n2, j);

    while (i < n1)
    {
        auto num1 = getVersion(version1, i);
        if (num1.first == 0)
        {
            i = num1.second;
        }
        else
        {
            return 1;
        }
    }
    while (j < n2)
    {
        auto num2 = getVersion(version2, j);
        if (num2.first == 0)
        {
            j = num2.second;
        }
        else
        {
            return -1;
        }
    }

    return 0;
}

// |> ChatGPT version_____________________  
class Solution
{
public:
    pair<int, int> getVersion(const string &s, int currIndex)
    {
        int ver = 0;
        while (currIndex < s.size() && s[currIndex] != '.')
        {
            ver = ver * 10 + (s[currIndex] - '0');
            currIndex++;
        }
        if (s[currIndex] == '.')
        {
            currIndex++;
        }
        return {ver, currIndex};
    }

    int compareVersion(const string &version1, const string &version2)
    {
        int i = 0;
        int j = 0;
        int n1 = version1.size();
        int n2 = version2.size();

        while (i < n1 || j < n2) // here we are using or which make this code better and short
                                 // as we do not need while loops for remaining char at end.
        {
            auto num1 = getVersion(version1, i);
            auto num2 = getVersion(version2, j);

            if (num1.first < num2.first)
            {
                return -1;
            }
            else if (num1.first > num2.first)
            {
                return 1;
            }

            i = num1.second;
            j = num2.second;
        }

        return 0;
    }
};

void solve()
{

    string v1, v2;
    cin >> v1 >> v2;
    int ans = compareVersion(v1, v2);
    debug(ans);
}

//|> ---MAIN-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
