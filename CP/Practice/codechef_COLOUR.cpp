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
    int t;
    cin >> t;
    while (t--)
    {

        int x, y, z;
        vi a(4);
        cin >> x >> y >> z;
        a[0] = x;
        a[1] = y;
        a[2] = z;

        int cnt = 0;
        sort(a.begin(), a.end(), greater<int>());

        if (a[0] > 0)
        {
            a[0]--;
            cnt++;
        }
        if (a[1] > 0)
        {
            a[1]--;
            cnt++;
        }
        if (a[2] > 0)
        {
            a[2]--;
            cnt++;
        }

        if (a[0] > 0 && a[1] > 0)
        {
            a[0]--;
            a[1]--;
            cnt++;
        }
        if (a[0] > 0 && a[2] > 0)
        {
            a[0]--;
            a[2]--;
            cnt++;
        }
        if (a[1] > 0 && a[2] > 0)
        {
            a[1]--;
            a[2]--;
            cnt++;
        }
        cout << cnt << endl;
    }
}
