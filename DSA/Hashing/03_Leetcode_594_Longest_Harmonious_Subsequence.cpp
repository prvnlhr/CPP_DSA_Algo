
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

// O(nlog(n)) -> sorting and sliding
int findLHS(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int winEnd = 0;
    int winStart = 0;
    int maxLen = 0;

    while (winEnd < n)
    {
        int diff = nums[winEnd] - nums[winStart];
        if (diff > 1)
        {
            while (nums[winEnd] - nums[winStart] > 1)
            {
                winStart++;
            }
        }
        if (nums[winEnd] - nums[winStart] == 1)
        {
            maxLen = max(maxLen, winEnd - winStart + 1);
        }
        winEnd++;
    }
    return maxLen;
}

// O(N) -> Hashing into Map
int findLHSBetter(vector<int> &nums)
{
    unordered_map<int, int> freqMpp;
    int maxLen = 0;

    for (int &num : nums)
    {
        freqMpp[num]++;
    }

    for (auto [num, freq] : freqMpp)
    {
        if (freqMpp.find(num + 1) != freqMpp.end())
        {
            int firstVal = freqMpp[(num + 1)];
            int secondVal = freqMpp[num];

            maxLen = max(maxLen, firstVal + secondVal);
        }
    }
    return maxLen;
}

void solve()
{
    int ele;
    vector<int> nums;
    //  1 3 5 7 9 11 13 15 17
    // 1 3 2 2 5 2 3 7

    while (cin >> ele)
    {
        nums.push_back(ele);
    }
    int res = findLHSBetter(nums);
    cout << res << endl;
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
