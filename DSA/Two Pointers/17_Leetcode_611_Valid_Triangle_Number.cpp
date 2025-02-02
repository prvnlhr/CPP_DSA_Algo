
/*
|>------------------------------------------------------------------------------------------------------------------------------------------------------------
|>                               █▀ ▀█▀ █▀▀ █░░ █░░ █░█ █▀█
|>                               ▄█ ░█░ ██▄ █▄▄ █▄▄ █▀█ █▀▄
|>------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define MOD 1000000007
#define MOD1 998244353
#define PI 3.141592653589793238462

typedef long long ll;

// |> ---DEBUG_TEMPLATE_START---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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

//__Change output format here______________________________________________________________________________________________________________________________________________________
#define out(x) #x " = " << x << "; "

#ifndef ONLINE_JUDGE
#define debug(...) \
    cerr << "Line " << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
#else
#define debug(...)
#endif

//|> ---DEBUG_TEMPLATE_END-----------------------------------------------------------------------------------------------------------------------------------------------------------

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

//|> ---ＳＯＬＶＥ-----------------------------------------------------------------------------------------------------------------------------------------------

//|> O(N^3)
bool isTriangle(int a, int b, int c)
{
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int triangleNumber(vector<int> &nums)
{
    int cntTriplets = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (isTriangle(nums[i], nums[j], nums[k]))
                {
                    debug(nums[i], nums[j], nums[k]);
                    cntTriplets++;
                }
            }
        }
    }
    return cntTriplets;
}

//|> O(N^2)
/*
This problem is very similar to 3-Sum, in 3-Sum, we can use three pointers (i, j, k and i < j < k) to solve the problem in O(n^2) time for a sorted array, the way we do in 3-Sum is that we first lock pointer i and then scan j and k, if nums[j] + nums[k] is too large, k--, otherwise j++, once we complete the scan, increase pointer i and repeat.

For this problem, once we sort the input array nums, the key to solve the problem is that given nums[k], count the combination of i and j where nums[i] + nums[j] > nums[k] (so that they can form a triangle). If nums[i] + nums[j] is larger than nums[k], we know that there will be j - i combination.

Let's take the following array for example, let's mark the three pointers:

 i                  j   k
[3, 19, 22, 24, 35, 82, 84]
because 3 + 82 > 84 and the numbers between 3 and 82 are always larger than 3, so we can quickly tell that there will be j - i combination which can form the triangle, and they are:

3,  82, 84
19, 82, 84
22, 82, 84
24, 82, 84
35, 82, 84
Now let's lock k and point to 35:

 i          j   k
[3, 19, 22, 24, 35, 82, 84]
because 3 + 24 < 35, if we move j to the left, the sum will become even smaller, so we have to move pointer i to the next number 19, and now we found that 19 + 24 > 35, and we don't need to scan 22, we know that 22 must be ok!

*/

int triangleNumber(vector<int> &nums)
{
    int cntTriplets = 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int k = n - 1; k >= 2; k--)
    {
        int i = 0;
        int j = k - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] > nums[k])
            {
                cntTriplets = cntTriplets + (j - i);
                j--;
            }
            else
            {
                i++;
            }
        }
    }

    return cntTriplets;
}

void solve()
{
    vector<int> nums;
    int ele;
    while (cin >> ele)
    {
        nums.push_back(ele);
    }
    int res = triangleNumber(nums);
    debug(res);
}

//|> ---MAIN-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
