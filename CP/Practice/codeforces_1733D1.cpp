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

        ll n, x, y;
        cin >> n >> x >> y;

        string a, b;
        cin >> a;
        cin >> b;

        vector<ll> notEqPairs;

        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                notEqPairs.push_back(i);
            }
        }

        if (notEqPairs.size() % 2 == 1)
        {
            cout << -1 << endl;
        }

        else if (notEqPairs.size() == 2)
        {

            if (notEqPairs[0] + 1 == notEqPairs[1])
            {
                cout << min(x, 2 * y) << endl;
            }
            else
            {
                cout << (notEqPairs.size() / 2) * y << endl;
            }
        }
        else
        {
            cout << (notEqPairs.size() / 2) * y << endl;
        }
    }
}

/*

4
5 8 7
01001
00101
5 7 2
01000
11011
7 8 3
0111001
0100001
5 10 1
01100
01100
*/