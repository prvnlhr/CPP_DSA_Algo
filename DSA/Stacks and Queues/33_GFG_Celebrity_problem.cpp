
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

bool knows(int i, int j, vector<vector<int>> &mat)
{
    return mat[i][j];
}

/*

>- Naive solution : O(N^2) O(N)
>- Using Graph in degree and outdegree

:Follow the steps below to solve the problem:
-Create two arrays indegree and outdegree, to store the indegree and outdegree
-Run a nested loop, the outer loop from 0 to n and inner loop from 0 to n.
-For every pair i, j check if i knows j then increase the outdegree of i and indegree of j.
-For every pair i, j check if j knows i then increase the outdegree of j and indegree of i.
-Run a loop from 0 to n and find the id where the indegree is n-1 and outdegree is 0.

*/

int celebrity(vector<vector<int>> &M, int n)
{
    vector<int> inDegree(n);
    vector<int> outDegree(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (knows(i, j, M))
            {
                outDegree[i] += 1;
                inDegree[j] += 1;
            }
        }
    }

    int celebrity = -1;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == n - 1 && outDegree[i] == 0)
        {
            celebrity = i;
            break;
        }
    }
    return celebrity;
}

/*
>- TC: O(N) SC: O(N)
: using stack elimination technique
Steps:
1. Put all candidates into stack , 0 -> n
2. pop top two candidates from stack, A and B
3. If A knows B, B can be potential celeb. so put B back to stack
   else, put A to stack
4. At the end there will be only one candidate in stack, who can be potential celeb
5. At the end run a loop and verify if the stack candidate is celeb or not.

*/
int celebrity1(vector<vector<int>> &M, int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    //-> st.size() > 1 : because we want finally one element in stack top
    //-> which can be our potentional celebrity

    while (st.size() > 1)
    {
        int A = st.top();
        st.pop();

        int B = st.top();
        st.pop();

        if (knows(A, B, M))
        {
            //|> B could be potentional celebrity
            st.push(B);
        }
        else
        {
            //|> else A would be potentional celebrity
            st.push(A);
        }
    }
    int celebrity = st.top();
    st.pop();

    //|> finally verifying if st.top() is really a celebrity or not
    for (int i = 0; i < n; i++)
    {
        if (celebrity != i && (knows(celebrity, i, M) || !knows(i, celebrity, M)))
        {
            return -1;
        }
    }
    return celebrity;
}

/*
|> TC: O(N), SC: O(1)
: Using two pointer approach
*/
int celebrity2(vector<vector<int>> &M, int n)
{

    int A = 0;
    int B = n - 1;

    while (A < B)
    {
        if (knows(A, B, M))
        {
            A++;
        }
        else
        {
            B--;
        }
    }

    int celebrity = A;

    //|> finally verifying if st.top() is really a celebrity or not
    for (int i = 0; i < n; i++)
    {
        if (celebrity != i && (knows(celebrity, i, M) || !knows(i, celebrity, M)))
        {
            return -1;
        }
    }
    return celebrity;
}

//> ---------------------------------------------------------------------------------

void solve()
{
    vector<vector<int>> grid{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << celebrity2(grid, 3) << endl;
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
