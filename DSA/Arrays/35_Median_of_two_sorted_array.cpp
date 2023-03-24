
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
/*
* 1. Using merge technique, to make a sorted array , and finding median
:TC: O(m+n)
:SC: O(m+n)
*/

/*
* 2. Using merge technique but not storing elements in array,rather
* keeping count pointer to reach middle element and taking median
:TC: O(m+n)
:SC :O(1)
*/

/*
* 3. Using Binary search appraoch
:TC : min(logN, LogM)
:SC : O(1)
*/
double getMedianBest(vector<int> arr1, vector<int> arr2)
{

    if (arr1.size() > arr2.size())
    {
        getMedianBest(arr2, arr1);
    }

    /*

    - Total elements in a sorted array will be m + n
    - if m = 4 , n = 6 , total element will be, 10
    - if we do partition we will get 5 elements in one and 5 in other
    - Now what is mid of first array of len 4 ?? 4 //2 = 2
    - so if we took 2 elements from first array, then how much we take from second array , 5 - 2 =  3

    - arr1 =  7  12  14  15 ,   m = 4
    - arr2 =  1  2   3   4  9  11 , n = 6
    - sorted array  =  1 2 3 4 7 9 11 12 14 15

    - mid of first array 4//2 = 2
    -
    - so if we consider 2 ele from 1st array, then we need to consider 5-2 = 3, elements from 2nd array
    -
    - 1st arr ele ->  2 ele    7  12     |  14  15
    - 2nd arr ele ->  3 ele    1  2  3   |   4   9  11

    - left1  = 12,  left2  =  3
    - right1 = 14,  right2 =  4

    - now, if at any point, left1 <= right2 and left2 <= right1:
    - we have our median as { max(left1,left2) + min(right1,right2) } // 2.0

    - else if left1 >  right2 :  left - 1
    - else if left1

    */

    int lo = 0;
    int hi = arr1.size();
    int n1 = arr1.size();
    int n2 = arr2.size();

    while (lo <= hi)
    {

        /*

        - Now consider the combination of both the array,

        -   lo                            hi
        -   |                             |
        -   0  1  2  3  4  5  6   7   8   9
        -   1  2  3  4  7  9  11  12  14  15

        - lo = 0 , hi = 9
        - cut or cut1 will == (lo + hi)//2  == 0 + 9 = 9//2 = 4

        - so we will consider 4 elements from 1st array
        - Now, How much elements to consider from 2nd array ??

        - Total elements in combined array is 10 == (ele in 1st )m + (ele in 2nd)n

        - so (m + n - cut1)  will be elements to consider from 2nd array
        - Now we are taking m + n + 1 , because we want to cut the array equal so one step further

        */

        int cut1 = (lo + hi) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        /*

          - We want to make cut at cut1-1, but if cut1 == 0 ,
          - cut1-1 = 0-1 = -1, so we can make cut at arr[-1]
          - so we take it as '-inf'

        */

        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];

        int r1 = cut1 == n1 ? INT_MAX : arr1[cut1];
        int r2 = cut2 == n2 ? INT_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((n1 + n2) % 2 == 0)
            {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else
            {
                return max(l1, l2);
            }
        }
        else if (l1 > r2)
        {
            hi = cut1 - 1;
        }
        else
        {
            lo = cut1 + 1;
        }
    }

    return 0.0;
}

void solve()
{
    vector<int> arr1{7, 12, 14, 15};
    vector<int> arr2{1, 2, 3, 4, 9, 11};
    // vector<int> arr1{1, 2};
    // vector<int> arr2{3, 4};
    cout << getMedianBest(arr1, arr2) << endl;
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
