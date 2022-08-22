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

    int n;
    //> Refer brilliant.org finding last digit of big powers article.
    // * basically when have to observe the pattern of powers, and compute the last digit acccordingly.
    cin >> n;
    if (n == 0)
    {
        cout << 1 << endl;
    }
    else if (n % 4 == 0)
    {
        cout << 6 << endl;
    }
    else if (n % 4 == 1)
    {
        cout << 8 << endl;
    }
    else if (n % 4 == 2)
    {
        cout << 4 << endl;
    }
    else if (n % 4 == 3)
    {
        cout << 2 << "\n";
    }
}
