
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

//|> Naive Solution gives memory limit Exceeded
void buildString(string &s, int n)
{
    if (n == 1)
    {
        return;
    }
    string currS = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            currS = currS + '0' + '1';
        }
        else if (s[i] == '1')
        {
            currS = currS + '1' + '0';
        }
    }
    s = currS;
    n = n - 1;
    buildString(s, n);
}

/*
|> Time Complexity : O(N)
|> Space Complexity : O(1);
*/

/*
|> INTUTION :
-> Here are a few observations, if you can figure them out the code itself is rather easy.
|> Observations:
n = 1 => 0
n = 2 => 01
n = 3 => 0110
n = 4 => 01101001

* The length is in the power of 2,i.e, 2^(n-1).
* The 1st half in each row is equal to previous row.
* The 2nd half is the compliment of previous row.

|> So rather then building a string all together which can give us memory limit exceeded(MLE),
|> by using the above observation, we find the kth required character easily

- At every step for a particular value of n, the string does repeats.
- First half of string is similar to previous row string
- Using this fact we can find the kth element without actually building the string
- We know that for n=1, string is => 0
- Now for every consecutive rows, this string somehow repeats itself
- So if we can decide, where exactly the kth element will lie we can get our ans
- At every step, for a value of  n, we can get the length of string so formed by using lenOfStr = 2^n-1
- So for ex. n = 3, lenOfStr  = 2^3-1 = 4.
- and midOfStr of String formed will be at midOfStr = lenOfStr/2
- Now if k is smaller then this midOfStr value that means we can get our kth char from previous row's kth charcter
- So we will go to previous row, i.e n = n-1, and k will remain same
- But if k is greater then midOfStr, then kth char will be complement of kth character of first half, because
- we know that second half is repeated and is also complement of first half.
- So we just need to give the kth char of first half but it will be complement(opposite),
- and we know that first half is same as previous  row, so we will go to previous row, i.e n = n-1,
- and value of k will be k = k - midOfStr, how we got k = k - midOfStr see below example.

|> Example n = 5, k = 11
|> lenOfStr = 2^n-1 = 16
|> midOfStr = 16/2 = 8
|> String will be => 0110100110010110
                                  |
                  1 2 3 4 5 6 7 8 | 9 10 11 12 13 14 15 16
          n = 5   0 1 1 0 1 0 0 1 | 1  0  0  1  0  1  1  0
                      |           |       |
                      |       midOfStr    |
         k = 11       |___________________|

         3rd k is corresponding to 11th k and also complement(opposite)

         So 3rd k = 3 => k - midOfStr = 11-8 = k(3) 3rd k
*/
int kthGrammerBetter(int n, int k)
{
    if (n == 1 && k == 1)
    {
        return 0;
    }
    int lenOfStr = pow(2, n - 1);
    int midOfStr = lenOfStr / 2;
    if (k <= midOfStr)
    {
        return kthGrammerBetter(n - 1, k);
    }
    else
    {
        return !kthGrammerBetter(n - 1, k - midOfStr);
    }
}

int kthGrammar(int n, int k)
{
    string s = "0";
    buildString(s, n);
    debug(s);
    return s[k - 1] - '0';
}
void solve()
{
    int n;
    int k;
    cin >> n >> k;
    cout << kthGrammar(n, k) << endl;
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
