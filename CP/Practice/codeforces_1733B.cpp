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

        int n, x, y;
        cin >> n >> x >> y;
        vector<int> ans;

        if ((x > 0 && y > 0) || (x == 0 && y == 0))
        {
            cout << -1 << endl;
        }
        else
        {

            int numWins = max(x, y);
            if ((n - 1) % numWins != 0)
            {
                cout << -1 << endl;
            }
            else
            {

                for (int playerNum = 1; playerNum <= n; playerNum++)
                {

                    for (int cnt = 1; cnt <= numWins; cnt++)
                    {
                        ans.push_back(playerNum + 1);
                    }
                    playerNum += numWins - 1;
                }

                //> printing the result
                for (int i = 0; i < n - 1; i++)
                {

                    cout << ans[i] << " ";
                }
                cout << endl;
            }
        }
    }
}
