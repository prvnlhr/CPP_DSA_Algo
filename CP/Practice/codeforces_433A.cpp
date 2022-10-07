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

    ll SUM = 0;
    vector<int> arr(n);
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
        mpp[a]++;
        SUM += a;
    }

    if (n == 1)
    {
        cout << "NO" << endl;
    }
    else if (mpp[200] && mpp[100] && mpp[100] % 2 == 0 && mpp[200] % 2 == 0)
    {

        cout << "YES" << endl;
    }
    else
    {
        if (mpp[100] && !mpp[200] && mpp[100] % 2 == 0)
        {
            cout << "YES" << endl;
        }
        else if (mpp[200] && !mpp[100] && mpp[200] % 2 == 0)
        {
            cout << "YES" << endl;
        }
        else if (mpp[200] && mpp[100] && mpp[100] % 2 == 1 && mpp[200] % 2 == 1)
        {
            cout << "NO" << endl;
        }
        else if (200 * mpp[200] == 100 * mpp[100])
        {
            cout << "YES" << endl;
        }

        else if (mpp[200] && mpp[100] && (200 * (mpp[200] % 2) == (100 * mpp[100])))
        {
            cout << "YES" << endl;
        }

        else if (mpp[200] && mpp[100] && mpp[100] % 2 == 0 && (((mpp[100] / 2) + (2 * (mpp[200])) + (mpp[100] / 2)) % 2 == 0))
        {

            cout << "YES" << endl;
        }
        else
        {

            cout << "NO" << endl;
        }
    }
}
