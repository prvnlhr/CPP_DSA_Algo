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

        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;

        int minDis = abs(1 - n) + abs(1 - m);

        int distLeftWallandLaser, distRightWallandLaser, distTopWallandLaser, distBottomWallandLaser;

        distLeftWallandLaser = sy - 1;
        distRightWallandLaser = m - sy;
        distTopWallandLaser = sx - 1;
        distBottomWallandLaser = n - sx;

        //> if taking leftwall and bottom path -> we need to check distLeft and distBottom
        if ((distLeftWallandLaser <= d || distBottomWallandLaser <= d) && (distRightWallandLaser <= d || distTopWallandLaser <= d))
        {
            cout << -1 << endl;
        }
        //> if taking rightWall and top path -> we need to check distLeft and distBottom

        else
        {
            cout << minDis << endl;
        }
    }
}
