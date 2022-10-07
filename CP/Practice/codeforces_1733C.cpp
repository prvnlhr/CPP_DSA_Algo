#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = end; i >= start; i--)
#define FOREACH(x, b) for (auto x : b)

#define cout1(x) cout << x << endl;
#define cout2(x, y) cout << x << " " << y << endl;
#define cout3(x, y, z) cout << x << " " << y << " " << z << endl;

#define SUMOFN(arr) accumulate(arr.begin(), arr.end(), 0LL);
#define SORTASC(arr) sort(arr.begin(), arr.end());
#define SORTDSC(arr) sort(arr.begin(), arr.end(), greater<int>());

#define strLow(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define strUp(s) transform(s.begin(), s.end(), s.begin(), ::toupper);

#define lb(arr, ele) lower_bound(arr.begin(), arr.end(), ele);
#define ub(arr, ele) upper_bound(arr.begin(), arr.end(), ele);

typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> stint;
typedef map<int, int> mpint;
typedef pair<int, int> pi;
typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        if (n == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            vector<vector<int>> ans;

            if ((arr[0] + arr[n - 1]) % 2 == 1)
            {
                ans.push_back({0 + 1, n - 1 + 1});
                arr[n - 1] = arr[0];
            }
            else if ((arr[0] + arr[n - 1]) % 2 == 0)
            {
                ans.push_back({0 + 1, n - 1 + 1});
                arr[0] = arr[n - 1];
            }

            for (int i = 1; i < n - 1; i++)
            {
                if ((arr[0] + arr[i]) % 2 == 1)
                {
                    ans.push_back({0 + 1, i + 1});

                    arr[i] = arr[0];
                }
                else
                {
                    ans.push_back({i + 1, n - 1 + 1});

                    arr[i] = arr[n - 1];
                }
            }

            cout << ans.size() << endl;
            for (auto x : ans)
            {
                cout << x[0] << " " << x[1] << endl;
            }
        }
    }
}

/*
4
1 5
2 5
3 5
4 5
*/