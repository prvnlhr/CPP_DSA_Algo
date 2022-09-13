
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

typedef long long ll;

#define REMDUP(arr) unique(arr.begin(), arr.end())

#define SORTASC(arr) sort(arr.begin(), arr.end())
#define SORTDSC(arr) sort(arr.begin(), arr.end(), greater<>())
#define lb(arr, val) lower_bound(arr.begin(), arr.end(), val)
#define ub(arr, val) upper_bound(arr.begin(), arr.end(), val)
int main()
{

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
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        vector<int> temp1 = a;

        SORTASC(temp1);

        temp1.erase(REMDUP(temp1), temp1.end());

        for (int i = 0; i < a.size(); i++)
        {

            a[i] = lb(temp1, a[i]) - temp1.begin();
        }

        vector<int> temp2 = b;

        SORTASC(temp2);

        temp2.erase(REMDUP(temp2), temp2.end());

        for (int i = 0; i < b.size(); i++)
        {

            b[i] = lb(temp2, b[i]) - temp2.begin();
        }

        vector<int> c(n);
        vector<int> s(n);
        vector<int> r(n);

        vector<int> p;

        for (int i = 0; i < n; i++)
        {
            c[a[i]] = b[i];
            s[i] = a[i] + b[i];
            r[b[i]] = i;
        }
        for (int i = 0; i < n; ++i)
        {
            p.insert(ub(p, c[i]), c[i]);

            s[r[c[i]]] -= lb(p, c[i]) - p.begin();
        }

        int t1 = 0;
        int q1 = 0;

        for (auto x : s)
        {
            t1 = max(t1, x);
        }

        for (auto y : s)
        {
            q1 += (y == t1);
        }

        cout << q1 << endl;
    }
}