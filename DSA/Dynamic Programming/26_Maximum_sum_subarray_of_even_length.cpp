
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
:TC :(N), SC: O(N)
Naive recurisve solution wont be possible due to some unknown reason,
tried but was not able to figure it out.

> Now, We want to find maximum sum of subarray fo length that is even
lets take a naive example and see what's happening

-> Ex: 1 2 3 4 5 6 7 8

If we want to calculate the subarray with max sum of only even length could we do it,
The basic intution would be to consider all subarray of even length, So lets take allsubarrays,
of even length



> STEP 1: Consider all even length subarray starting from every index(that's how we take subarrays)
                                               >> STEP 3:
Starting from -> 1                             |
              -> 1 2                           |
              -> 1 2 3 4                       | [1 2] + 3 4 -> as we can see that form above subarray[1 ,2] we can just need to add it to this array to get our ans
              -> 1 2 3 4 5 6                   | [1 2 3 4] + 5 6   -> similarly from above subarray we can get our ans
              -> 1 2 3 4 5 6 7 8               | [1 2 3 4 5 6] + 7 8
                                               | So we found that we only need to find arr[i] + arr[i+1] and then add it to previous sum of even lenght subarray
                                               | (prev even len subarray sum) + (arr[i] + arr[i+1])
                                               | now prev even len subarray sum can be found using recurion or in case of DP we can store it
                                               | So we have to do (arr[i]+arr[i+1]) and call for (i + 2)th index and then finally add them both
                                               > Hence, int sum1 = arr[i] + arr[i+1]
                                               > and,   int sum2 = recF(i+2);
                                               > finally sum = sum1 + sum2;  and return sum;
                                               | But there's a catch. We can also have negative elements and recF(i+2) can bring us negative sum
                                               | so do we really need to add (negative sum2) and sum1 and make final sum negative ?? a BIG NO NO!!
                                               | Now before moving any futher taking let first convert it to DP solution from above recursence relation.
                                               |
                                               > int sum1 = arr[i] + arr[i+1];
                                               > int sum2 = dp[i+2] -> recF(i+2) converted to DP
                                               > dp[i] = sum1 + sum2 ; but sum2  i.e,  dp[i+1] can be negative to so we wont conside it
Starting from -> 2                             - This is what the maxSumDP_1 solution does,
                                               - maxSumDP_2 is also same solution but we just made it more readable

              -> 2 3
              -> 2 3 4 5
              -> 2 3 4 5 6 7

Starting from -> 3
              -> 3 4
              -> 3 4 5 6
              -> 3 4 5 6 7 8

Starting from -> 4
              -> 4 5
              -> 4 5 6 7

Starting from -> 5
              -> 5 6
              -> 5 6 7 8

Starting from -> 6
              -> 6 7

Starting from -> 7
              -> 7 8

Starting from -> 8
              -> No array of even length

> STEP 2: now after adding all the elements from above all subarrays and taking sum which is max
>         we cant get our result

But wait. As we can see that there is repeated work when we are considering all subarrays
Lets see how we are doing repeated work, Go to Step 3





*/

int maxSumDP_1(vector<int> arr)
{
    int n = arr.size();

    if (n < 2)
    {
        return 0;
    }

    vector<int> dp(n + 1, 0);

    dp[n - 1] = 0;
    dp[n - 2] = arr[n - 2] + arr[n - 1];

    for (int i = n - 3; i >= 0; i--)
    {
        int sum1 = arr[i] + arr[i + 1];

        if (dp[i + 2] > 0)
        {
            sum1 = sum1 + dp[i + 2];
        }

        dp[i] = sum1;
    }

    int maxSumRes = *max_element(dp.begin(), dp.end());
    return maxSumRes;
}
int maxSumDP_2(vector<int> arr)
{
    int n = arr.size();

    if (n < 2)
    {
        return 0;
    }

    vector<int> dp(n + 1, 0);

    dp[n - 1] = 0;                       //> Sum at end of array will be 0
    dp[n - 2] = arr[n - 2] + arr[n - 1]; //> Sum at second last index(n-2) will be arr[n-1]+arr[n-2]

    //> Starting from n-3
    for (int i = n - 3; i >= 0; i--)
    {
        int sum1 = arr[i] + arr[i + 1];

        int sum2 = arr[i] + arr[i + 1] + dp[i + 2]; //> dp[i+2] i.e, prev even lenght sum can be neagtive, which
                                                    //> which will make sum2 negative, so  we have to do max(sum1,sum2);
        dp[i] = max(sum1, sum2);                    //> sum2 can become negative, due to dp[i+2]
    }

    int maxSumRes = *max_element(dp.begin(), dp.end());
    return maxSumRes;
}
void solve()
{

    // vector<int> arr{8, 9, -8, 9, 10};
    vector<int> arr{1, 2, 3};
    cout << maxSumDP_2(arr);
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
