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
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }

    int diff = INT_MAX;
    int s = 0;
    int e = 0;
    for (int i = 1; i < n; i++)
    {
        int diffCur = abs(arr[i - 1] - arr[i]);
        if (diffCur < diff)
        {
            diff = diffCur;
            s = i - 1;
            e = i;
        }
    }
    if (abs(arr[0] - arr[n - 1]) < diff)
    {
        s = n - 1;
        e = 0;
    }
    cout << s + 1 << " " << e + 1 << endl;
}
