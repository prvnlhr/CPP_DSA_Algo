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
#define FOREACH(x, b) for (int x : b)

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

    int s, n;
    cin >> s >> n;
    string ANS = "YES";

    int currS = s;
    vector<pi> arr;

    // * 1. O(N)
    while (n--)
    {
        int xi, yi;
        cin >> xi >> yi;
        pi pr{xi, yi};
        arr.push_back({xi, yi});
    }

    // * 2. (N logN)
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        if (currS > arr[i].first)
        {
            currS = currS + arr[i].second;
        }
        else
        {
            ANS = "NO";
            break;
        }
    }

    //* 3. Over all TC : O(N log N) + O(N) => O(N log N)
    cout << ANS << "\n";
}
