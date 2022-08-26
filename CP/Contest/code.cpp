#include <bits/stdc++.h>

using namespace std;

#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = end; i >= start; i--)
#define FOREACH(x, b) for (auto x : b)

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

    int t;
    cin >> t;
    while (t--)
    {

        int x, y;
        cin >> x >> y;
        cout << x << " " << y << "\n";

        vector<vector<int>> board(9, vector<int>(9, 0));

        board[x][y] = 1;

        // four corners
        if (x == 1 && y == 1)
        {
            board[x + 1][y + 2] = 2;
        }
        else if (x == 8 && y == 1)
        {
            board[x - 1][y + 2] = 2;
        }

        else if (x == 1 && y == 8)
        {
            board[x + 1][y - 2] = 2;
        }
        else if (x == 8 && y == 8)
        {
            board[x - 1][y - 2] = 2;
        }

        // four borders
        else if (x == 1 && y >= 2 && y <= 7)
        {
            board[x + 2][y - 1] = 2;
            board[x + 2][y + 1] = 2;
        }
        else if (y == 1 && x >= 2 && x <= 7)
        {
            board[x - 1][y + 2] = 2;
            board[x + 1][y + 2] = 2;
        }
        else if (x == 8 && y >= 2 && y <= 7)
        {
            board[x - 2][y - 1] = 2;
            board[x - 2][y + 1] = 2;
        }
        else if (y == 8 && x >= 2 && x <= 7)
        {
            board[x - 1][y - 2] = 2;
            board[x + 1][y - 2] = 2;
        }

        // four corners near border
        else if (x == 2 && y == 2)
        {
            board[x - 1][y + 3] = 2;
            board[x + 2][y - 1] = 2;
        }
        else if (x == 2 && y == 7)
        {
            board[1][4] = 2;
            board[4][8] = 2;
        }

        else if (x == 7 && y == 2)
        {
            board[x - 3][y - 1] = 2;
            board[x + 1][y + 2] = 2;
        }
        else if (x == 7 && y == 7)
        {
            board[x - 2][y + 1] = 2;
            board[x + 1][y - 3] = 2;
        }

        // for inner edges

        else if (x == 2 && y >= 3 && y <= 6)
        {

            board[x - 1][y - 2] = 2;
            board[x + 1][y + 2] = 2;
        }
        else if (x == 7 && y >= 3 && y <= 6)
        {

            board[x - 1][y - 2] = 2;
            board[x + 1][y + 2] = 2;
        }

        else if (y == 2 && x >= 3 && x <= 6)
        {

            board[x - 2][y - 1] = 2;
            board[x + 2][y + 1] = 2;
        }
        else if (y == 7 && x >= 3 && x <= 6)
        {

            board[x + 2][y + 1] = 2;
            board[x - 2][y - 1] = 2;
        }

        else
        {

            board[x - 2][y - 1] = 2;
            board[x + 2][y + 1] = 2;
        }

        // Print board

        for (int i = 1; i < 9; i++)
        {
            for (int j = 1; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}
