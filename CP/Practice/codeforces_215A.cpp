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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    vector<int> ratios;

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (b[j] % a[i] == 0)
            {
                ratios.push_back(b[j] / a[i]);
            }
        }
    }

    sort(ratios.begin(), ratios.end(), greater<int>());

    // for (auto x : ratios)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    int cnt = 0;
    for (int i = 1; i < ratios.size(); i++)
    {
        if (ratios[i - 1] == ratios[i])
        {
            cnt++;
        }
        else
        {
            break;
        }
    }
    cout << cnt + 1 << endl;
}