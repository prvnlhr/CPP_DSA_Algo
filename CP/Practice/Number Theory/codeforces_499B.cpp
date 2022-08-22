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

    string st;
    int n, m;
    cin >> n >> m;
    map<string, string> mpp;

    for (int i = 1; i <= m; i++)
    {
        string a;
        string b;
        cin >> a >> b;
        mpp[a] = b;
    }

    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;

        string res = "";

        string x = mpp[s];

        if (x.length() < s.length())
        {
            res = x;
        }
        else
        {
            res = s;
        }
        cout << res << " ";
    }
    cout << "\n";
}
