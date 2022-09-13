#include <iostream>
#include <string>
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
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = end; i >= start; i--)
#define FOREACH(x, b) for (auto x : b)

#define COUT(x) cout << x << endl;
#define N << endl;

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
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int j = 0; j < n; j++)
        {
            cin >> b[j];
        }

        for (int i = 0; i < n; i++)
        {

            auto up = lower_bound(b.begin(), b.end(), a[i]);
            // cout << *up << endl;
            int d = *up - a[i];
            cout << d << " ";
        }
        cout << endl;

        for (int i = 0; i < n - 1; i++)
        {

            int j = n - 2;

            if (b[j] >= a[j + 1])
            {
                cout << b[n - 1] - a[i] << " ";
            }
            else
            {

                while (b[j] < a[j + 1] && j > i)
                {
                    j--;
                }
                cout << b[j] - a[i] << " ";
            }
        }
        cout << b[n - 1] - a[n - 1];
        cout << endl;

        // int dmax[n];
        // int j = n - 1;
        // // cout << b[n - 1] - a[n - 1] << " ";
        // dmax[j] = b[j] - a[j];

        // for (int i = n - 2; i >= 0; i--)
        // {

        //     if (b[i] >= a[i + 1])
        //     {
        //         // cout << b[j] - a[i] << " ";
        //         dmax[i] = b[j] - a[i];
        //     }
        //     else
        //     {
        //         j = i;
        //         // cout << b[i] - a[i] << " ";
        //         dmax[i] = b[i] - a[i];
        //     }
        // }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << dmax[i] << " ";
        // }

    }
}
/*
1
4
10 20 30 40
22 33 33 55
*/