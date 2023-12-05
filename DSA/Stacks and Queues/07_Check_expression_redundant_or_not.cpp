
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

//|> CN SOL : O(N), O(N);
/*

    The intuition behind this solution is that it basically checks if there is a expression `a+b`, `a/b`, etc.
    in between a pair of opening and closing bracket.

    Ex_1.  (a+(b/c))
    In this example the inner pair of open and close bracket has a expression in-between `b/c` so this inner pair of bracket is valid
    Similar will be the case for outer pair.

    Ex_2. (a+((b/c)))
    In this example the innermost pair of open-close brackets has a expression `b/c`, so it is valid pair of bracks.
    Now the next surrounding pair of open-close brakets  outside the innermost pair is redudant, bcoz it has not valid expression.
    `b/c` belongs to innermost pair, so  the outer pair has left with nothing, so they are redudant.

    So the intuition is to check if a open-close pair has expression in-between them then they are valid pair.
    This can be done using stack.

    steps: 1. Open bracket, or operator or operand(we can just skip the operand) then put it in stack
           2. Closing bracket then check if a expression is present in-between. This can be done by using stack top.
           3. If stack top has operator or operand followed by a open bracket then this opening-closing bracket is valid pair.
           4. Else if stack top has immemidiate opening bracket, that means no operator in between then, invalid open-close pair.


    Dry-run: (a+((b/c)))

    stack : []
    index = 0, (  -> put to stack  [ (, ]
    index = 1, a  -> put to stack  [ (, a ]
    index = 2, +  -> put to stack  [ (, a, + ]
    index = 3, (  -> put to stack  [ (, a, +, ( ]
    index = 4, (  -> put to stack  [ (, a, +, (, ( ]
    index = 5, b  -> put to stack  [ (, a, +, (, (, b ]
    index = 6, /  -> put to stack  [ (, a, +, (, (, b, / ]
    index = 7, c  -> put to stack  [ (, a, +, (, (, b, /, c ]
    index = 8, )  -> check stack top : `c`, that means there is an expression in-between followed by a open bracket -> (, b, /, c
                                        so pop stack till open bracket is found. Now stack is -> [ (, a, +, (, ]

    index = 9, )  ->  stack : [ (, a, +, (, ], top : `(`. That means there is not expression in-between so invalid pair, return true


*/
bool checkRedundacny(string s)
{
    stack<char> st;

    for (auto ele : s)
    {
        if (ele == '(' || ele == '+' || ele == '-' || ele == '*' || ele == '/')
        {
            st.push(ele);
        }
        else if (ele == ')')
        {
            bool isRedundant = true;

            //|> if we enter this loop it means that we dont have immediate top element as opening bracket
            //|> means no redundant bracket, so isRedudant == false
            while (st.top() != '(')
            {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/')
                {
                    isRedundant = false;
                }
                st.pop();
            }
            st.pop();
            if (isRedundant == true)
            {
                return true;
            }
        }
    }
    return false;
}

//|> O(N), O(1)
//|> GFG SOL
bool checkRedundacny1(string s)
{

    int operatorCount = 0;
    int bracketsCount = 0;

    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        //|> Edge case -> (a)
        if (i + 2 < n && s[i] == '(' && s[i + 2] == ')')
        {
            return true;
        }
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            operatorCount++;
        }
        if (s[i] == '(')
        {
            bracketsCount++;
        }
    }

    if (bracketsCount > operatorCount)
    {
        return true;
    }

    return false;
}

void solve()
{
    string s;
    cin >> s;
    if (checkRedundacny1(s))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
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
