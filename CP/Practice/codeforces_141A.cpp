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

    string a, b, s;

    cin >> a;
    cin >> b;
    cin >> s;
    if (s.length() < a.length() + b.length())
    {
        cout << "NO" << endl;
        return 0;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(s.begin(), s.end());

    // cout << a << endl;
    // cout << b << endl;
    // cout << s << endl;

    int ip = 0;
    int jp = 0;
    int sp = 0;
    string ans = "YES";

    while (sp < s.length())
    {

        if (a[ip] == s[sp])
        {
            ip++;
            sp++;
        }
        else if (b[jp] == s[sp])
        {
            jp++;
            sp++;
        }
        else
        {
            ans = "NO";
            break;
        }
    }
    cout << ans << endl;
}
