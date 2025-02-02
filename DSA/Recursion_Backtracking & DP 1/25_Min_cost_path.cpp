
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
- Given a cost matrix cost[][] and a position (m, n) in cost[][], write a
- function that returns cost of minimum cost path to reach (m,n) from
- (0, 0). Each cell of the matrix represents a cost to traverse through
- that cell. The total cost of a path to reach (m, n) is the sum of all the costs
- on that path (including both source and destination). You can only traverse down,
- right and diagonally lower cells from a given cell, i.e., from a given cell (i, j),
- cells (i + 1, j), (i, j + 1), and (i + 1, j + 1) can be traversed.
- You may assume that all costs are positive integers.

-> Ex__
- 1  2  3
- 4  8  2
- 1  5  3
-
- The path with minimum cost is (0, 0) –> (0, 1) –> (1, 2) –> (2, 2).
- The cost of the path is 8 (1 + 2 + 2 + 3).

-> 1) Optimal Substructure
-  The path to reach (m, n) must be through one of the 3 cells: (m-1, n-1) or (m-1, n) or (m, n-1).
-  So minimum cost to reach (m, n) can be written as “minimum of the 3 cells plus cost[m][n]”.
-  minCost(m, n) = min (minCost(m-1, n-1), minCost(m-1, n), minCost(m, n-1)) + cost[m][n]
-
-> 2) Overlapping SubProblems
-  Following is a simple recursive implementation of the MCP (Minimum Cost Path) problem.
-  The implementation simply follows the recursive structure mentioned above.
*/

int minCostPathRec(vector<vector<int>> mat, int row, int col, int i, int j)
{
    if (i == row - 1 && j == col - 1)
    {
        return mat[i][j];
    }
    if (i >= row || j >= col)
    {
        return INT_MAX;
    }

    int a = minCostPathRec(mat, row, col, i + 1, j);
    int b = minCostPathRec(mat, row, col, i + 1, j + 1);
    int c = minCostPathRec(mat, row, col, i, j + 1);
    return mat[i][j] + min({a, b, c});
}

int minCostDP(vector<vector<int>> mat)
{
    int row = mat.size();
    int col = mat[0].size();

    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
    dp[0][0] = mat[0][0];

    for (int i = 1; i < row; i++)
    {
        dp[i][0] = dp[i - 1][0] + mat[i][0];
    }

    for (int j = 1; j < col; j++)
    {
        dp[0][j] = dp[0][j - 1] + mat[0][j];
    }

    debug(dp);
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            dp[i][j] = mat[i][j] + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
        }
    }
    debug(dp);
    return dp[row - 1][col - 1];
}

int minCostPath(vector<vector<int>> mat)
{
    int row = mat.size();
    int col = mat[0].size();
    // return minCostPathRec(mat, row, col, 0, 0);
    return minCostDP(mat);
}
void solve()
{
    /*
    # 1  2  3
    # 4  8  2
    # 1  5  3
    */
    vector<vector<int>> mat{{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};
    cout << minCostPath(mat) << endl;
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
