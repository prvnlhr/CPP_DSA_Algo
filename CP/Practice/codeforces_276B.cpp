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

    string s;
    cin >> s;

    map<char, int> mpp;
    for (int i = 0; i < s.length(); i++)
    {
        mpp[s[i]]++;
    }

    int cnt = 0;

    for (auto x : mpp)
    {
        if (x.second % 2 == 1)
        {
            cnt++;
        }
    }

    if (cnt % 2 == 1 || cnt == 0)
    {
        cout << "First" << endl;
    }
    else
    {
        cout << "Second" << endl;
    }
}
