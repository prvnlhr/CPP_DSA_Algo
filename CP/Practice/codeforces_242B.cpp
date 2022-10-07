#include <bits/stdc++.h>
using namespace std;

#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = end; i >= start; i--)
#define FOREACH(x, b) for (auto x : b)

#define print1(x) cout << x << endl;
#define print2(x, y) cout << x << " " << y << endl;
#define print3(x, y, z) cout << x << " " << y << " " << z << endl;

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
    vector<vector<int>> arr(n, vector<int>(2, 0));

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i][0] = a;
        arr[i][1] = b;
    }

    int minl = INT_MAX;
    int maxr = INT_MIN;

    int req = -1;

    for (int i = 0; i < n; i++)
    {

        int l = arr[i][0];
        int r = arr[i][1];

        minl = min(minl, l);
        maxr = max(maxr, r);
    }

    for (int i = 0; i < n; i++)
    {

        int l = arr[i][0];
        int r = arr[i][1];

        if (minl == l && maxr == r)
        {
            req = i;
        }
    }

    if (req == -1)
    {
        cout << -1 << endl;
    }
    else
    {

        cout << req + 1 << endl;
    }
}

/*

5
1 5
2 2
3 3
5 7
1 6
*/