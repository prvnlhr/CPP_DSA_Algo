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

    int n, m;
    cin >> n >> m;

    vector<int> nt(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nt[i];
    }

    vector<int> mt(m);
    for (int i = 0; i < m; i++)
    {
        cin >> mt[i];
    }

    SORTDSC(nt);
    SORTASC(mt);

    if (mt[0] <= nt[0])
    {
        cout << -1 << endl;
    }
    else
    {

        int v = -1;
        v = max(nt[0], 2 * nt[n - 1]);
        // int currV = nt[0];
        // if (n == 1 && 2 * currV < mt[0])
        // {
        //     v = 2 * currV;
        // }

        // for (int i = 1; i < n; i++)
        // {

        //     if (2 * nt[i] <= currV)
        //     {
        //         v = currV;
        //         break;
        //     }
        // }
        cout << v << endl;
    }
}
/*
1 50
7
65 52 99 78 71 19 96 72 80 15 50 94 20 35 79 95 44 41 45 53 77 50 74 66 59 96 26 84 27 48 56 84 36 78 89 81 67 34 79 74 99 47 93 92 90 96 72 28 78 66

5 100
1 1 1 1 1
77 53 38 29 97 33 64 17 78 100 27 12 42 44 20 24 44 68 58 57 65 90 8 24 4 6 74 68 61 43 25 69 8 62 36 85 67 48 69 30 35 41 42 12 87 66 50 92 53 76 38 67 85 7 80 78 53 76 94 8 37 50 4 100 4 71 10 48 34 47 83 42 25 81 64 72 25 51 53 75 43 98 53 77 94 38 81 15 89 91 72 76 7 36 27 41 88 18 19 75

*/