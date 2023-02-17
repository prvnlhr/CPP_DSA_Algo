
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

//-> REFER APNA COLLEGE YT VIDEO

/*

> Time complexity Best	  : O(n*log n)
> Time complexity Worst	  : O(n^2)
> Time complexity Average : O(n*log n)
> Space Complexity	: O(1)

** IMP : When does the worst case occurs in quick sort
> Worst Case:
- The worst case occurs when the partition process always picks the greatest or smallest element
- as the pivot. If we consider the above partition strategy where the last element is always
- picked as a pivot, the worst case would occur when the array is already sorted in increasing
- or decreasing order. Following is recurrence for the worst case.

> Best Case:
- The best case occurs when the partition process always picks the middle element as the pivot.



** Why Quick Sort is preferred over MergeSort for sorting Arrays ?
- Quick Sort in its general form is an in-place sort (i.e. it doesn’t require any extra storage)
- whereas merge sort requires O(N) extra storage


** Why MergeSort is preferred over QuickSort for Linked Lists ?
- In case of linked lists the case is different mainly due to difference in memory
- allocation of arrays and linked lists. Unlike arrays, linked list nodes may not be adjacent in memory.
- Unlike array, in linked list, we can insert items in the middle in O(1) extra space and O(1) time.
- Therefore merge operation of merge sort can be implemented without extra space for linked lists.

*/

int partition(vector<int> &arr, int low, int high)
{
    int pivotElement = arr[high];

    int currSwappIndex = low - 1;

    //> here j is going till : high - 1, because at high we have our pivot, so we are swapping
    //> element between low and high-1, without considering high, i.e pivot
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivotElement)
        {
            currSwappIndex++;
            swap(arr[currSwappIndex], arr[j]);
        }
    }

    currSwappIndex++;
    swap(arr[currSwappIndex], arr[high]);
    return currSwappIndex;
}

void quickSort(vector<int> &arr, int low, int high)
{

    if (low < high)
    {

        //> 1. first find pivot
        int pivotIndex = partition(arr, low, high);

        //> 2. apply  quick sort on left half and right half

        //>   [low..........pivotIndex................high]
        //> we are doing pivotIndex - 1, and pivotIndex+1, because we know that pivotElement will
        //>  come at correct place after end, of step
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void solve()
{
    // vector<int> arr{6, 3, 9, 5, 2, 8};
    vector<int> arr{5, 4, 3, 2, 1};
    quickSort(arr, 0, arr.size() - 1);
    debug(arr);
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
