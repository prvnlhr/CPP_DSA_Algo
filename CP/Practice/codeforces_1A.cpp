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

    ll n, m, a;
    cin >> n >> m >> a;
    if (a > n && a > m)
    {
        cout << 1 << endl;
    }
    else
    {

        ll row_wise = n / a;
        ll row_rem = n % a;

        ll col_wise = m / a;
        ll col_rem = m % a;

        if (row_rem != 0)
        {
            row_wise = row_wise + 1;
        }
        if (col_rem != 0)
        {
            col_wise = col_wise + 1;
        }

        cout << (row_wise) * (col_wise );
    }
}
