#include <iostream>
// #include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
// #include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = end; i >= start; i--)
#define FOREACH(x, b) for (auto x : b)

#define COUT(x) cout << x << endl;

typedef vector<int> vi;
typedef vector<int> vl;
typedef set<int> stint;
typedef map<int, int> mpint;
typedef pair<int, int> pi;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    string s;
    cin >> s;

    //> C++ Strings are mutable in general

    for (int tsec = 1; tsec <= t; tsec++)
    {

        int i = 0;
        while (i < s.size())
        {

            if (s[i] == 'B' && s[i + 1] == 'G')
            {
                swap(s[i + 1], s[i]);
                i = i + 2;
            }
            else
            {
                i++;
            }
        }
    }
    cout << s << "\n";

    //> OR  USING ARRAY

    // vector<char> arr(s.length());

    // for (int i = 0; i < s.length(); i++)
    // {
    //     arr[i] = s[i];
    // }

    // for (int tsec = 1; tsec <= t; tsec++)
    // {

    //     int i = 0;
    //     while (i < arr.size())
    //     {

    //         if (arr[i] == 'B' && arr[i + 1] == 'G')
    //         {
    //             swap(arr[i + 1], arr[i]);
    //             i = i + 2;
    //         }
    //         else
    //         {
    //             i++;
    //         }
    //     }
    // }
    // for (auto x : arr)
    // {
    //     cout << x;
    // }
}
