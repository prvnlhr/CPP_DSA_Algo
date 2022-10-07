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
    int n, k;
    cin >> n >> k;
    vi arr(n + 1);

    for (int i = 1; i < n + 1; i++)
    {
        cin >> arr[i];
    }

    for (int i = k; i < n; i++)
    {
        if ((i + 1) < (n + 1) && arr[i] != arr[i + 1])
        {
            cout << -1 << endl;
            return 0;
        }
    }

    int indx = 0;
    for (int i = 1; i <= k; i++)
    {
        if ((i + 1) < (n + 1) && arr[i] != arr[i + 1])
        {
            indx = i;
        }
    }

    cout << indx << endl;
}
