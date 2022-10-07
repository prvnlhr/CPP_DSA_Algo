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

    int cnt5 = 0;
    int cnt0 = 0;

    vector<double> a(n);

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        if (ele == 0)
        {
            cnt0++;
        }
        else
        {
            cnt5++;
        }
        a[i] = ele;
    }

    if (cnt0 == 0)
    {
        cout << -1 << endl;
    }

    else if (cnt5 < 9)
    {
        cout << 0 << endl;
    }
    else
    {

        cnt5 = cnt5 / 9;
        for (int i = 1; i <= cnt5; i++)
        {
            cout << "555555555";
        }
        for (int i = 1; i <= cnt0; i++)
        {
            cout << '0';
        }
        cout << endl;
    }
}
/*
14
5 5 5 5 5 5 5 5 5 5 5 5 5 5
 */