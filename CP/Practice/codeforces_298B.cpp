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

    int t, sx, sy, ex, ey;
    cin >> t >> sx >> sy >> ex >> ey;

    string s;
    cin >> s;

    // int destx = ex - sx;
    // int desty = ey - sy;

    // cout << destx << " " << desty << endl;

    for (int i = 0; i < s.length(); i++)
    {

        // cout << s[i] << " " << sx << " " << sy << endl;

        if (s[i] == 'E')
        {
            if (sx < ex)
            {
                sx++;
            }
        }
        else if (s[i] == 'S')
        {

            if (sy > ey)
            {
                sy--;
            }
        }
        else if (s[i] == 'W')
        {

            if (sx > ex)
            {
                sx--;
            }
        }
        else if (s[i] == 'N')
        {

            if (sy < ey)
            {
                sy++;
            }
        }

        if (sx == ex && sy == ey)
        {
            cout << i + 1;
            return 0;
        }
    }

    // for (int i = 0; i < s.length(); i++)
    // {

    //     cout << sx << " " << sy << endl;
    //     if (s[i] == 'E')
    //     {
    //         if (destx < 0)
    //         {
    //             sx++;
    //         }
    //     }
    //     else if (s[i] == 'S')
    //     {
    //         if (desty < 0)
    //         {
    //             sy--;
    //         }
    //     }
    //     else if (s[i] == 'W')
    //     {
    //         if (destx < 0)
    //         {
    //             sx--;
    //         }
    //     }
    //     else if (s[i] == 'N')
    //     {
    //         if (desty > 0)
    //         {
    //             sy++;
    //         }
    //     }

    //     if (sx == ex && sy == ey)
    //     {
    //         cout << i + 1;
    //         return 0;
    //     }
    // }
    cout << -1 << endl;
}
