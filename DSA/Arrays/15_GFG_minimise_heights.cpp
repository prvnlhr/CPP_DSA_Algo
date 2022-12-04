
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
# Given heights of n towers and a value k. We need to either
# increase or decrease the height of every tower by k (only once)
# where k > 0. The task is to minimize the difference between the
# heights of the longest and the shortest tower after modifications
# and output this difference.

-> '''Minimize the maximum difference between the heights'''


 Examples:

 -Input  : arr[] = {1, 15, 10}, k = 6
 -Output :  Maximum difference is 5.
 -Explanation : We change 1 to 7, 15 to
 -9 and 10 to 4. Maximum difference is 5
 -(between 4 and 9). We can't get a lower
 -difference.
-
- Input : arr[] = {1, 5, 15, 10}
-         k = 3
- Output : Maximum difference is 8
- arr[] = {4, 8, 12, 7}
-
- Input : arr[] = {4, 6}
-         k = 10
- Output : Maximum difference is 2
- arr[] = {14, 16} OR {-6, -4}
-
- Input : arr[] = {6, 10}
-         k = 3
- Output : Maximum difference is 2
- arr[] = {9, 7}
-
- Input : arr[] = {1, 10, 14, 14, 14, 15}
-         k = 6
- Output: Maximum difference is 5
- arr[] = {7, 4, 8, 8, 8, 9}
-
- Input : arr[] = {1, 2, 3}
-         k = 2
- Output: Maximum difference is 2
- arr[] = {3, 4, 5}
-
-

: APPROACH : REFER TECHIE'S CODE YT VIDEO

 >  1  1  1  2  5  6  7  9  9  10
 >                           a                           b
 >                           |                           |
 >                           1  1  1  2  5  6  7  9  9  10

 - Consider the above case, Initially before making any changes to the array elements
 - if the array is sorted what would be the max diff ??, Well if array is sorted maxEle(a) - minELe(b) = 10 - 1 = 9 is max Diff
 - Now, as we have to minimise this diff , what could be the possible cases,
 -> 1. Increase a and b
 -> 2. Decrease a and b
 -> 3. Increase a, Decrease b
 -> 4. Decrease a, Increase b
    We first two cases would be absurd because, let say if a = 1, b = 10, diff = 10-1 = 9
    if both and b are increased -> a = a + 1 , b = b + 1 => a = 2, b = 11,  diff = 11 -2 = 9.

 - Now, if we carefully observe, if we want to minimise the heights, we need to minimise the difference.
 - So case 3. would be correct,to increase a and decrease b. So when we increase a and decrease b, we are reduce the distance between them
 -
 - Now again if we further look at the sorted array we find that, any two elements which are adjacent to each other
 - will have minimum difference. i.e  arr[i-1] and arr[i].
 - now if arr[i-1]{left ele} move towards right i.e arr[i-1]+k  and arr[i]{right ele} moves towards left i.e arr[i]-k , difference can be
 - further decreased.
 - Conclusion:
 - Initially our minELe -> arr[0] , maxEle -> arr[n-1] , because arr is sorted.
 - Further, to minimise diff ,we can do, minELe = arr[0]+k,  and maxELe = arr[n-1]-k , reducing the gap.
 - Now, two adjacent elements are given as arr[i-1] and arr[i].
 - If we want to reduce the gap between then, we can do -->  arr[i-1]+k  , arr[i]-k.
 - So our minEle will be minimum of initial minELe i.e arr[0]+k and arr[i]-k
 - and maxEle will be maximum of initial maxELe i.e arr[n-1]-k and arr[i-1]+k
   ->     MIN = min(arr[0] + k, arr[i] - k)
   ->     MAX = max(arr[n - 1] - k, arr[i - 1] + k)

    > now diff = MAX-MIN
    > and as we want to minimise the ans therefore, ans = min(ans, diff)
    ! NOTE: there's a catch in the solution, as after subtracting k from element it should be non-negative(i.e remain positive),
    #       so we cant subtract k from a element if it become negative.
    #       if a element is equal or greater then k, then only we can subtract k from it, without making it negative,
    #       else we need to skip that element


: Time Complexity: O(NlogN)
: Space Complexity: O(N)

*/
int getMinDiff(vector<int> arr, int n, int k)
{
    sort(arr.begin(), arr.end());

    int ans = arr[n - 1] - arr[0];

    for (int i = 0; i < n; i++)
    {

        if (arr[i] >= k)
        {

            int MIN = min(arr[0] + k, arr[i] - k);
            int MAX = max(arr[n - 1] - k, arr[i - 1] + k);
            int diff = MAX - MIN;
            ans = min(ans, diff);
        }
        else
        {
            continue;
        }
    }
    return ans;
}
void solve()
{

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    FOR(i, 0, n)
    {
        int ele;
        cin >> ele;
        arr[i] = ele;
    }
    cout << getMinDiff(arr, n, k) << endl;
}

//>-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration.count() / 1000 << endl;
#endif
}
