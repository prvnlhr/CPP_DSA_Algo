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

        int n;
        cin >> n;

        string s;
        cin >> s;

        int cnt_0 = 0;
        int cnt_1 = 0;

        for (int i = 0; i < n; i++)
        {

            if (s[i] == '0')
                cnt_0++;
            if (s[i] == '1')
                cnt_1++;
        }

        if (cnt_1 == n or cnt_0 == n)
        {
            cout << n << " " << 0 << endl;
            return 0;
        }

        int op = abs(cnt_0 - cnt_1) + 1;

        vector<vector<int>> arr;

        for (int i = 1; i < op; i++)
        {

            int j = 1;
            while (s[j] == s[j - 1])
            {
                j++;
            }

            char c;

            if (cnt_0 < cnt_1)
            {

                c = '0';
            }
            else
            {

                c = '1';
            }

            arr.push_back({j, j + 1, c});
            string t = s.substr(0, j - 1) + c + s.substr(j + 1);
            s = t;
        }
        arr.push_back({1, (int)s.length(), '0'});
        cout << 1 << " " << arr.size() << endl;
        for (auto x : arr)
        {
            cout << x[0] << " " << x[1] << " " << char(x[2]) << endl;
        }
    }
}
