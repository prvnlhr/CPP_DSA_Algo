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
        string ANS = "CHEF";
        cin >> n;
        vector<int> piles(n);
        int SUM = 0;
        bool flag = false;
        int MIN = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> piles[i];
            MIN = min(MIN, piles[i]);

            SUM = SUM + piles[i];
        }
        if (MIN == 1)
        {
            cout << "CHEF"
                 << "\n";
        }
        else if ((SUM - 2 * n) % 2 == 0)
        {
            ANS = "CHEF";
        }
        else
        {
            ANS = "CHEFINA";
        }

        cout << ANS << "\n";
    }
}
