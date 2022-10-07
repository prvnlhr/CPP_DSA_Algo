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

    map<int, vector<int>> mpp;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        mpp[a].push_back(i);
    }

    auto it = mpp.begin();

    if (it->second.size() > 1)
    {
        cout << "Still Rozdil" << endl;
    }
    else
    {
        cout << it->second[0] + 1 << endl;
    }
}
