
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
> REFER STRIVER'S YT VIDEO

-> APPROACH::
- Given an arr of n books with pages in it and no. of students to
- allocate books, m = 2,  [12 , 34,  67,  90]
- We have to find the '''minimum of maximum''' of minimum pages allocated to m students
- Consider  m = 2, [12 , 34,  67,  90]
-
-  s1(Student 1)          :        s2(student 2)
-  12                              34 + 67 + 90 == 191 ,   min = 12 , max = 191
-  12 + 34 == 46                   67 + 90 ==  157 ,       min = 46 , max = 157
-  12 + 34 + 67 == 113             90                      min = 90 , max = 113

- So max = 113 , which is minimum of all max, and it is our ans

- SO WHAT IS SOL ???
- We can solve is recursively with all the possible allocation cases
- Time complexity would be 2^n

- BETTER SOL ::
- BINARY SEARCH SOLUTION  , O(nLogN)

- What is the minimum number of pages can be allocated if only one student is there ??
- The ans would be minimum of array or 0
- What would be max , ans is sum of all pages of all books
- So now we have min and max , or lo or hi
- Now find the mid of min ,max or (lo,hi)
- mid = (lo,hi)//2
- now our mid could be ans , if we could allocate all books to all students, considering mid as our ans
- So we will find if mid is our feasible ans or not.
- if we found that mid can be our ans so we will try to further minimise by reducing our lo, hi range from lo to mid-1
- else we will increase our range from mid+1 to  hi
-
- Now for a a mid value how to find if it is feasible ans or not,
- our isPossible function will give us ans.
- We will keep a variable allocatedStudent  = 1
- for every book we will allocate it to student no 1 , and increase pagesAllocated
- if pagesAllocated is less that our mid value we can still allocate pages to student 1
- At last if all students are allocated all book we have our ans True or False


: T : O(N) +O(logN) = O(NlogN)

! NOTE: In interview don't waste time on suggesting or working on brute force sol,
!       because it is complex to work out and will waste lot of time.
!       So directly jump on optimize binary search solution.

*/

bool canAllocate(int arr[], int studs, int n, int pagesToAllocate)
{
    int currntlyAlloPages = 0;
    int currStudsCnt = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > pagesToAllocate)
        {
            return false;
        }
        if (currntlyAlloPages + arr[i] <= pagesToAllocate)
        {
            currntlyAlloPages += arr[i];
        }
        else
        {
            currStudsCnt++;
            currntlyAlloPages = arr[i];
            if (currStudsCnt > studs)
            {
                return false;
            }
        }
    }
    return true;
}
int findPages(int A[], int N, int M)
{
    if (N < M)
    {
        return -1;
    }
    int res = -1;
    int lo = A[0];
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
    }
    int hi = sum;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (canAllocate(A, M, N, mid))
        {
            res = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return res;
}
void solve()
{
    int n = 4;
    int A[] = {12, 34, 67, 90};
    int m = 2;
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
