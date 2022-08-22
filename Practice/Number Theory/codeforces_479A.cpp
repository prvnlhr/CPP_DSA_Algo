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

    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    int ANS = INT_MIN;

    int val1 = a * b * c;
    ANS = max(ANS, val1);
    // cout << ANS << endl;

    int val2 = (a + b) * c;
    ANS = max(ANS, val2);
    // cout << ANS << endl;

    int val3 = a + (b * c);
    ANS = max(ANS, val3);
    // cout << ANS << endl;

    int val4 = (a * b) + c;
    ANS = max(ANS, val4);
    // cout << ANS << endl;

    int val5 = a * (b + c);
    ANS = max(ANS, val5);
    // cout << ANS << endl;

    int val6 = a + b + c;
    ANS = max(ANS, val6);
    
    cout << ANS << endl;
}
