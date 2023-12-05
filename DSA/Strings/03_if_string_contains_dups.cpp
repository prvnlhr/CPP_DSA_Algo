
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
//--------------------------------------------------------------------------------------------------------------------------------

//>----------------------------ＳＯＬＶＥ-----------------------------------------------------------------------------------------------------------------------------------------------

/*
:TC :O(NlogN) --> inserting in set and looping string of size N
:SC : (N)--> set
> Using set
*/
bool containsDups1(string s)
{
    set<int> st;
    for (auto ch : s)
    {
        if (!st.empty() && st.find(ch) != st.end())
        {
            return true;
        }
        st.insert(ch);
    }
    return false;
}

/*
:TC :(N)
:SC:(N)
> Using boolean visited array
*/
bool containsDups2(string s)
{
    set<int> st;
    int maxChars = 256;

    vector<bool> visited(maxChars, false);
    for (auto ch : s)
    {
        if (visited[ch])
        {
            return true;
        }
        visited[ch] = true;
    }

    return false;
}

/*
:TC :(N)
:SC:(1)
> Using bits to store info
-  Instead of maintaining a boolean array, we maintain an integer value
-  called checker(32 bits). As we iterate over the string, we find the
-  int value of the character with respect to ‘a’ with the statement
-> int bitAtIndex = str.charAt(i)-‘a’;
-  Then the bit at that int value is set to 1 with the statement 1 << bitAtIndex .
-  Now, if this bit is already set in the checker, the bit AND operation
-  would make the checker > 0. Return false in this case.
-  Else Update checker to make the bit 1 at that index with the statement
-> checker = checker | (1 <<bitAtIndex);



//> IMP CONCEPT TO KNOW TO SOLVE USING THIS TECHNIQUE
** 1. How to set ith bit ??
** 2. How to check if ith bit is set or not


-> 1.How to set ith bit
- Ex. n = 10 -> binary representation is 1010
- 1010 , set k = 2nd bit -> 1110
** ( n | (1 << k))


-> 2.How to check if ith bit is set or not
- Ex n = 10 -> 1010
- k = 2
** ( n & (1 << k))







*/
bool containsDups3(string s)
{

    int checkerNum = 0;

    for (auto ch : s)
    {

        int bitIndex = ch - 'a';

        //|> check if a bit is set or not
        if ((checkerNum & (1 << bitIndex)))
        {
            return true;
        }

        //|> set bit for curr ch
        checkerNum = checkerNum | (1 << bitIndex);
    }

    return false;
}

void solve()
{

    string s;
    cin >> s;
    debug(s);
    cout << containsDups3(s);
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
