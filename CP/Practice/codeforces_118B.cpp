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

    // for (int i = n; i >= 0; i--)
    // {

    //     for (int j = i; j > 0; j--)
    //     {
    //         cout << "+";
    //     }
    //     cout << endl;
    // }
    

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < i + 1; j++)
        {
            cout << "+";
        }
        cout << endl;
    }

    // for (int i = n; i >= 0; i--)
    // {

    //     for (int j = i; j > 0; j--)
    //     {
    //         cout << "+";
    //     }
    //     cout << endl;
    // }

    // for (int i = n; i >= 0; i--)
    // {

    //     for (int j = i; j > 0; j--)
    //     {
    //         cout << "+";
    //     }
    //     cout << endl;
    // }
}
