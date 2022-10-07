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

    int n, m;
    cin >> n >> m;

    int l = max(n, m);
    int cnt = 0;
    for (int i = 0; i <= l; i++)
    {
        for (int j = 0; j <= l; j++)
        {

            int a = i;
            int b = j;

            if ((((a * a) + b) == n) && ((a + (b * b)) == m))
            {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}
