
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


# Input : ((()
# Output : 2
# Explanation : ()
#
# Input: )()())
# Output : 4
# Explanation: ()()
#
# Input:  ()(()))))
# Output: 6
# Explanation:  ()(())
#
#
# O(n) and O(n) stack sol:
# Input: str = "(()()"
#
# Initialize result as 0 and stack with one item -1.
#
# For i = 0, str[0] = '(', we push 0 in stack
#
# For i = 1, str[1] = '(', we push 1 in stack
#
# For i = 2, str[2] = ')', currently stack has
# [-1, 0, 1], we pop from the stack and the stack
# now is [-1, 0] and length of current valid substring
# becomes 2 (we get this 2 by subtracting stack top from
# current index).
#
# Since the current length is more than the current result,
# we update the result.
#
# For i = 3, str[3] = '(', we push again, stack is [-1, 0, 3].
# For i = 4, str[4] = ')', we pop from the stack, stack
# becomes [-1, 0] and length of current valid substring
# becomes 4 (we get this 4 by subtracting stack top from
# current index).
# Since current length is more than current result,
# we update result.

*/

// :TC O(N)
// :SC O(N)
//> Tricky, for only logic, coders camp video YT, not code(code seems to be wrong)
int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1);
    int res = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                int len = i - st.top();
                res = max(res, len);
            }
        }
    }
    return res;
}

//> O(N),O(1)
//> counting open and close brackets

int longestValidParenthesesOP(string s)
{

    int res = 0;
    int n = s.size();
    int openCnt = 0;
    int closeCnt = 0;
    for (int i = 0; i < n; i++)
    {
        char curr = s[i];
        if (curr == '(')
        {
            openCnt++;
        }
        else
        {
            closeCnt++;
        }
        if (openCnt == closeCnt)
        {
            //> why 2 * closeCnt ?? -> bcoz openCnt==closeCnt
            //> so len of substring will be 2*openCnt or 2*closeCnt, can take any
            res = max(res, 2 * closeCnt);
        }
        else if (closeCnt > openCnt)
        {
            openCnt = 0;
            closeCnt = 0;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        char curr = s[i];
        if (curr == '(')
        {
            openCnt++;
        }
        else
        {
            closeCnt++;
        }
        if (openCnt == closeCnt)
        {
            //> why 2 * closeCnt ?? -> bcoz openCnt==closeCnt
            //> so len of substring will be 2*openCnt or 2*closeCnt, can take any
            res = max(res, 2 * closeCnt);
        }
        else if (openCnt > closeCnt)
        {
            openCnt = 0;
            closeCnt = 0;
        }
    }
    return res;
}

void solve()
{

    string s;
    cin >> s;
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
