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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m, '0'));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    char toPrint = 'B';

    vector<vector<char>> boardAns(n, vector<char>(m, '0'));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            boardAns[i][j] = toPrint;
            if (toPrint == 'B')
            {
                toPrint = 'W';
            }
            else
            {
                toPrint = 'B';
            }
        }
        if (i < n)
        {

            char prevStart = boardAns[i][0];
            if (prevStart == 'W')
            {
                toPrint = 'B';
            }
            else if (prevStart == 'B')
            {
                toPrint = 'W';
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '-')
            {
                boardAns[i][j] = '-';
            }
        }
    }

    for (auto x : boardAns)
    {

        for (auto y : x)
        {
            cout << y;
        }
        cout << endl;
    }
    cout << endl;
}

/*
4 97
--.........-..-...............-....--..-.-.-..-.-.---.-.-...-.--..-.---.-....-...-.---..-.-.-...-
.---........--.........--------...--..--...--.-....--.-.--..--..-.....-...-.--.--.......--....-.-
.-...-.--.-..--..-..---..-.-....-...-..-....--...-.....-...-.-...-.--.-.-.---..--......-..-...-.-
--.......--......-........-....-...--..-.-.-....-.--...--...-.-.--..-..--...--.-..-....-.....--..


4 5
.....
.....
.....
.....
*/