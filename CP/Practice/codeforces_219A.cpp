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
    int k;
    cin >> k;

    string s;
    cin >> s;

    map<char, int> mpp;
    for (int i = 0; i < s.length(); i++)
    {
        mpp[s[i]]++;
    }

    for (auto it = mpp.begin(); it != mpp.end(); it++)
    {
        if (it->second % k != 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    string part = "";
    for (auto it = mpp.begin(); it != mpp.end(); it++)
    {
        char x = it->first;
        int cnt = it->second;
        int charCnt = cnt / k;
        for (int i = 1; i <= charCnt; i++)
        {
            part += x;
        }
    }

    string res = "";
    for (int i = 0; i <= k - 1; i++)
    {
        res += part;
    }
    cout << res;
}

/*
3
aabaaabaabba
 */