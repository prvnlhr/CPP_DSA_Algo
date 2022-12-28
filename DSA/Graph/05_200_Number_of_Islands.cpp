
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
vector<int> dirRow{-1, 1, 0, 0, -1, 1, -1, 1};
vector<int> dirCol{0, 0, -1, 1, -1, 1, 1, -1};

bool isSafe(int x, int y, vector<vector<char>> &adjmatrix, vector<vector<bool>> &visited)
{
    return x >= 0 && y >= 0 && x < adjmatrix.size() && y < adjmatrix[0].size() && !visited[x][y] && adjmatrix[x][y] == '1';
}
void dfs(vector<vector<char>> &adjmatrix, int i, int j, int m, int n, vector<vector<bool>> &visited)
{
    visited[i][j] = true;
    if (j - 1 >= 0 && adjmatrix[i][j - 1] == '1' && visited[i][j - 1] == false)
    {
        dfs(adjmatrix, i, j - 1, m, n, visited);
    }
    if (i - 1 >= 0 && adjmatrix[i - 1][j] == '1' && visited[i - 1][j] == false)
    {
        dfs(adjmatrix, i - 1, j, m, n, visited);
    }
    if (j + 1 < n && adjmatrix[i][j + 1] == '1' && visited[i][j + 1] == false)
    {
        dfs(adjmatrix, i, j + 1, m, n, visited);
    }
    if (i + 1 < m && adjmatrix[i + 1][j] == '1' && visited[i + 1][j] == false)
    {
        dfs(adjmatrix, i + 1, j, m, n, visited);
    }

    // for (int i = 0; i < 8; i++) // # DFS in 8 directions
    // {
    //     int adjx = x + dirRow[i];
    //     int adjy = y + dirCol[i];
    //     if (isSafe(adjx, adjy, adjmatrix, visited)) // # if adj dir not visited already and is not out of bound
    //     {
    //         dfs(adjmatrix, adjx, adjy, visited);
    //     }
    // }
}

int numIslands(vector<vector<char>> &grid)
{

    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    int numIsland = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (!visited[i][j] && grid[i][j] == '1')
            {
                dfs(grid, i, j, rows, cols, visited);
                numIsland++;
            }
        }
    }
    return numIsland;
}

void solve()
{
    // vector<vector<char>> grid{{1, 1, 1, 1, 0},
    //                           {1, 1, 0, 1, 0},
    //                           {1, 1, 0, 0, 0},
    //                           {0, 0, 0, 0, 0}};
    vector<vector<char>> grid{{'1', '1', '0', '0', '0'},
                              {'1', '1', '0', '0', '0'},
                              {'0', '0', '1', '0', '0'},
                              {'0', '0', '0', '1', '1'}};
    // vector<vector<char>> grid{{'0'}};
    // vector<vector<char>> grid{{'0', '0', '1', '0', '1'}};
    // vector<vector<char>> grid{{'1'}};
    cout << numIslands(grid) << endl;
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
