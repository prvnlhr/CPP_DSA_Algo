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

    string g1, g2;
    cin >> g1;
    cin >> g2;

    map<char, int> mpp;
    set<char> st;

    if (g1.length() != g2.length())
    {
        cout << "NO" << endl;
        return 0;
    }
    else
    {
        for (int i = 0; i < g1.length(); i++)
        {
            if (g1[i] != g2[i])
            {
                mpp[g2[i]] = i;
                st.insert(g1[i]);
                st.insert(g2[i]);
            }
        }

        if (mpp.size() == 1 || st.size() > 2)
        {
            cout << "NO" << endl;
            return 0;
        }
        else
        {

            for (auto x : mpp)
            {

                g1[x.second] = x.first;
            }

            if (g1 == g2)
            {
                cout << "YES" << endl;
                return 0;
            }
            else
            {
                cout << "NO" << endl;
                return 0;
            }
        }

        // if (mpp.size() == 1)
        // {
        //     cout << "NO" << endl;
        // }

        // for (auto x : mpp)
        // {
        //     cout << x.first << " " << x.second << endl;
        // }
        // cout << endl;
    }
    cout << "YES" << endl;
}
