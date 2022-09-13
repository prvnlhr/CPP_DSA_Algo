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

        ll n, k, b, s;
        cin >> n >> k >> b >> s;

        ll lastDgt = b * k;

        if (n == 1)
        {
            if (s / k != b)
            {
                cout << -1 << endl;
            }
        }
        else if (lastDgt > s)
        {
            cout << -1 << endl;
        }
        else
        {
            ll rem = s - lastDgt;
            if ((rem / (n - 1)) > k)
            {
                cout << -1 << endl;
            }
            else
            {

                ll currSum = rem;
                for (ll i = 1; i < n; i++)
                {

                    ll part = ceil((s - lastDgt) / (n - 1));
                    cout << part << " ";
                    currSum = currSum - part;
                }
                cout << lastDgt << endl;
            }
        }
    }
}
