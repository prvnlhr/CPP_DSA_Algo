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
#include <climits>
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

        vector<ll> arr(n);

        ll MIN = INT_MAX;
        ll MAX = INT_MIN;
        for (int i = 0; i < n; i++)
        {

            ll a;
            cin >> a;
            MIN = min(MIN, a);
            MAX = max(MAX, a);
            arr[i] = a;
        }

        ll minProd = 0;
        ll maxProd = 0;
        if (MIN < 0 && MAX < 0)
        {

            minProd = MAX * MAX;
            maxProd = MIN * MIN;
        }
        else if (MIN >= 0 && MAX >= 0)
        {

            minProd = MIN * MIN;
            maxProd = MAX * MAX;
        }
        else if (MIN < 0 && MAX > 0)
        {

            minProd = min(min(MIN * MIN, MAX * MAX), MIN * MAX);
            maxProd = max(max(MIN * MIN, MAX * MAX), MIN * MAX);
        }

        cout << minProd << " " << maxProd << endl;
    }
}
