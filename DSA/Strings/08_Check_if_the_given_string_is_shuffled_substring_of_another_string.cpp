
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
-> Input: str1 = “onetwofour”, str2 = “hellofourtwooneworld”
-> Output: YES
-  Explanation: str1 is substring in shuffled form of str2 as
-  str2 = “hello” + “fourtwoone” + “world”
-  str2 = “hello” + str1 + “world”, where str1 = “fourtwoone” (shuffled form)
-  Hence, str1 is a substring of str2 in shuffled form.

->  Input: str1 = “roseyellow”, str2 = “yellow”
->  Output: NO
-  Explanation: As the length of str1 is greater than str2. Hence, str1 is not a substring of str2.
*/

/*
 > This is optimised solution based on Anagram search solution
 :TC O(N)
 :SC: O(1) -> constant
*/

bool isPresent(string s1, string s2)
{
    vector<int> countStr1(256, 0);
    vector<int> countStr2(256, 0);

    for (int i = 0; i < min(s1.size(), s2.size()); i++)
    {
        countStr1[s1[i]]++;
        countStr2[s2[i]]++;
    }
    int m = s1.size();

    for (int i = s1.size(); i < s2.size(); i++)
    {
        if (countStr1 == countStr2)
        {
            return true;
        }
        (countStr2[s2[i]])++;
        countStr2[s2[i - m]]--;
    }

    if (countStr1 == countStr2)
    {
        return true;
    }
    return false;
}

// ** SAME AS ABOVE BUT MODIFIED TO MORE GENERIC SLIDING WINDOW PROBLEM
bool isPresent1(string s1, string s2)
{

    /*
    > Ex -> s1 = ABCD, s2 = BACDGABCDA
    - winSize = ABCD  ==  4, so we have to find this window in s2, in suffle form
    - first store all chars of s1 in s1CharCount array
    - take first window of s2 equal to s1.szie() and  store count in winCharCount
    - then iterate s2 form next window == s1.size()
    - if at any movement both cout Array become equal i.e, there chars becomes equal, so we return true
    - at and we also need to check for last window
    */

    vector<int> s1CharCount(256, 0);
    vector<int> winCharCount(256, 0); //> here window size is equal to s1

    int m = s1.size();
    int n = s2.size();

    for (int i = 0; i < m; i++)
    {
        s1CharCount[s1[i]]++;
        winCharCount[s2[i]]++;
    }

    int winStart = 0;
    int winEnd = m;
    while (winEnd < n)
    {
        if (s1CharCount == winCharCount)
        {
            return true;
        }

        winCharCount[s2[winEnd]]++;
        winCharCount[s2[winStart++]]--;
        winEnd++;
    }

    if (s1CharCount == winCharCount)
    {
        return true;
    }
    return false;
}

void solve()
{

    string s1, s2;
    cin >> s1 >> s2;
    debug(s1, s2);
    cout << isPresent(s1, s2) << endl;
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
