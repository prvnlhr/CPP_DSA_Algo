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
    cin >> n;

    int leftDOpen, leftDClose, rightDOpen, rightDClose;
    leftDOpen = 0;
    leftDClose = 0;
    rightDOpen = 0;
    rightDClose = 0;

    for (int i = 1; i <= n; i++)
    {

        int leftD, rightD;
        cin >> leftD >> rightD;

        if (leftD == 1)
        {
            leftDOpen++;
        }
        else if (leftD == 0)
        {
            leftDClose++;
        }

        if (rightD == 1)
        {
            rightDOpen++;
        }
        else if (rightD == 0)
        {
            rightDClose++;
        }
    }

    int leftAns = max(leftDOpen, leftDClose);
    int rightAns = max(rightDOpen, rightDClose);
    // cout << leftAns << " " << rightAns << endl;

    int ans = (n - leftAns) + (n - rightAns);
    cout << ans << endl;
}
