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

    ll n, m;
    cin >> n >> m;
    vector<ll> arr(m);
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {

        cin >> arr[i];
        if (i == 0)
        {
            ans = ans + arr[i] - 1;
        }
        else
        {
            if (arr[i] < arr[i - 1])
            {
                ll steps_to_com_circuit = n - arr[i-1];
                ans = ans + steps_to_com_circuit+arr[i];
            }
            else
            {

                ans = ans + arr[i] - arr[i - 1];
            }
        }
    }

    cout << ans << endl;
}
