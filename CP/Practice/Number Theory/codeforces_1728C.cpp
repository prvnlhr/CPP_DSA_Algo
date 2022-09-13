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
        priority_queue<int> a;
        priority_queue<int> b;

        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            a.push(ele);
        }
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            b.push(ele);
        }

        int ans = 0;

        while (!a.empty())
        {

            int aTop = a.top();
            int bTop = b.top();
            cout << aTop << " " << bTop << endl;

            if (aTop > bTop)
            {
                aTop = to_string(aTop).size();
                a.push(aTop);
                a.pop();
                ans++;
            }
            else if (aTop < bTop)
            {
                bTop = to_string(bTop).size();
                b.push(bTop);
                b.pop();
                ans++;
            }

            else
            {
                a.pop();
                b.pop();
            }
        }
        cout << ans << endl;
    }
}
