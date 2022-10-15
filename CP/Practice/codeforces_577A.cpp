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

#define FOR(i, start, end) for (ll i = start; i < end; i++)
#define RFOR(i, start, end) for (ll i = end; i >= start; i--)
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

    ll n, x;
    cin >> n >> x;
    // * constraints : 1<= n <= 10^5 , 1<= n <= 10^9

    ll cnt = 0;

    if (n == 1 && x != 1)
    {
        cout << 0 << endl;
    }
    else
    {

        FOR(i, 2, n + 1)
        {

            //> Every row will has max  10^5 cols, so if x/i is greater then n,then no sol;
            if (x % i == 0 && x / i <= n)
            {
                // cout << i << endl;

                cnt++;
            }
        }

        if (n >= x)
        {
            cnt++;
        }
        cout << cnt << endl;
    }
}
