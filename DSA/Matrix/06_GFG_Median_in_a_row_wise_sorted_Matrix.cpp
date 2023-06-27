
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

# HERE WE ARE COUNTING FOR EVERY ELEMENT
# IN CURR ROW WHICH ARE SMALLER THEN MID.
# NOW WE CAN USE LINER SEARCH ALL SEARCH
# TO COUNT, BUT TO OPTIMISE IT,
# WE CAN USE BINARY SEARCH AS THE CURR ROW IS SORTED
# currRow[mid_index] we decide if all smaller ele then MID
# will lie in left of right,
# SO we will only search half row.

*/
int countElementsSmallerThenMid(int MID, vector<int> &row)
{
    int i = 0;
    int j = row.size() - 1;

    while (i <= j)
    {
        int midIndex = (i + j) / 2;
        debug(i, j);
        if (row[midIndex] <= MID)
        {
            i = midIndex + 1;
        }
        else
        {
            j = midIndex - 1;
        }
    }

    return i;
}

int median(vector<vector<int>> &matrix, int R, int C)
{

    int MIN = INT_MAX;
    int MAX = INT_MIN;

    /*
    # One intuition to find lo and hi would be to take topMost left element and bottomMost right ele
    # [[0, 6, 8, 9, 11],
    # [20, 22, 28, 29, 31],            lo = 0 , hi = 128 , all elements are in range 0 -> 128
    # [36, 38, 50, 61, 63],
    # [64, 66, 100, 122, 128]]

    # but what if matrix is like below,
    # [[5]
    #  [4]
    #  [3]
    #  [1]
    #  [3]                            lo = 5 , hi = 3
    #  [1]
    #  [4]
    #  [2]
    #  [5]
    #  [3]
    #  [3]]

    # SO we run loop to find lo and hi , rather then just taking topMost left and bottomMost right element
    */

    for (int i = 0; i < R; i++)
    {
        MIN = min(MIN, matrix[i][0]);
        MAX = max(MAX, matrix[i][C - 1]);
    }

    while (MIN <= MAX)
    {
        int mid = (MIN + MAX) / 2;
        debug(MIN, MAX);

        int cnt = 0;
        for (int i = 0; i < R; i++)
        {
            cnt += countElementsSmallerThenMid(mid, matrix[i]);
        }

        if (cnt <= ((R * C) / 2))
        {
            MIN = mid + 1;
        }
        else
        {
            MAX = mid - 1;
        }
    }
    return MIN;
}
void solve()
{
    vector<vector<int>> matrix{{1, 3, 5},
                               {2, 6, 9},
                               {3, 6, 9}};
    int r = 3;
    int c = 3;
    cout << median(matrix, r, c) << endl;
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
