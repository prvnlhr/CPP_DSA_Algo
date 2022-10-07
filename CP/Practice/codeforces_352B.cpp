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

    vector<int> arr(n);
    map<int, vector<int>> mpp;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
        mpp[a].push_back(i + 1);
    }
    // for (auto x : mpp)
    // {
    //     cout << x.first << " : ";
    //     for (auto y : x.second)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }

    vector<vector<int>> ans;
    int cnt = 0;

    for (auto x : mpp)
    {

        set<int> st;

        int diff = 0;

        for (int i = 0; i < x.second.size(); i++)
        {
            if (i + 1 < x.second.size())
            {

                diff = x.second[i + 1] - x.second[i];
                st.insert(diff);
            }
        }

        if (st.size() == 1 || st.size() == 0)
        {
            vector<int> p{x.first, diff};
            ans.push_back(p);
            st.clear();
            cnt++;
        }
    }

    cout << cnt << endl;
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}
