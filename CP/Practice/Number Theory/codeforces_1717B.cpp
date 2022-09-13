

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {

        int n, k, r, c;
        cin >> n >> k >> r >> c;

        vector<vector<char>> table(n + 1, vector<char>(n + 1, '.'));

        for (int i = 1; i < n + 1; i++)
        {
            for (int i = c; i < n + 1; i += k)
            {
                table[r][i] = 'X';
            }
            for (int i = c; i >= 1; i -= k)
            {
                table[r][i] = 'X';
            }
            r++;
            c++;
            if (r > n)
            {
                r = 1;
            }
            if (c > n)
            {
                c = 1;
            }
        }

        //> Printing output table

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                cout << table[i][j];
            }
            cout << endl;
        }
    }
}
