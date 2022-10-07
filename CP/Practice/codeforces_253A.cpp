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
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    string ans = "";

    char gen;

    if (n > m)
    {

        gen = 'B';
    }
    else if (m > n)
    {
        gen = 'G';
    }
    else
    {
        gen = 'B';
    }

    int cntB = n;
    int cntG = m;

    for (int i = 0; i < n + m; i++)
    {

        if (gen == 'B' && cntB >= 1)
        {
            ans += 'B';
            gen = 'G';
            cntB--;
        }
        else if (gen == 'G' && cntG >= 1)
        {
            ans += 'G';
            gen = 'B';
            cntG--;
        }
    }

    if (cntG > 0)
    {
        while (cntG > 0)
        {

            ans += 'G';
            cntG--;
        }
    }
    if (cntB > 0)
    {
        while (cntB > 0)
        {

            ans += 'B';
            cntB--;
        }
    }
    cout << ans << endl;
}
