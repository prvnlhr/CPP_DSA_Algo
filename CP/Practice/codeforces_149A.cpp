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

    int k;
    cin >> k;
    vi arr(12);
    for (int i = 0; i < 12; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());

    int len = 0;

    int cnt = 0;
    for (int i = 0; i < 12; i++)
    {
        if (len >= k)
        {
            break;
        }
        len += arr[i];
        cnt++;
    }
    if (len < k)
    {
        cout << -1 << endl;
    }
    else
    {

        cout << cnt << endl;
    }
}
