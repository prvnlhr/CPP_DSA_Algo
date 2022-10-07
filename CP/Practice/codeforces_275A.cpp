#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = end; i >= start; i--)
#define FOREACH(x, b) for (auto x : b)

#define COUT(x) cout << x << endl;
#define N << endl;

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

    vector<vector<int>> initial(3, vector<int>(3, 0));
    vector<vector<int>> final(3, vector<int>(3, 1));

    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            cin >> initial[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            // cout << initial[i][j] << endl;
            // for (int i = 0; i < 3; i++)
            // {
            //     for (int j = 0; j < 3; j++)
            //     {
            //         cout << final[i][j];
            //     }
            //     cout << endl;
            // }
            // cout << endl;

            if (initial[i][j] % 2 == 1)
            {

                if (i == 0 && j == 0)
                {

                    final[i][j] = 1 - final[i][j];
                    final[0][1] = 1 - final[0][1];
                    final[1][0] = 1 - final[1][0];
                }
                else if (i == 0 && j == 1)
                {
                    final[i][j] = 1 - final[i][j];
                    final[0][0] = 1 - final[0][0];
                    final[0][2] = 1 - final[0][2];
                    final[1][1] = 1 - final[1][1];
                }
                else if (i == 0 && j == 2)
                {
                    final[i][j] = 1 - final[i][j];
                    final[0][1] = 1 - final[0][1];
                    final[1][2] = 1 - final[1][2];
                }
                else if (i == 1 && j == 0)
                {
                    final[i][j] = 1 - final[i][j];
                    final[0][0] = 1 - final[0][0];
                    final[2][0] = 1 - final[2][0];
                    final[1][1] = 1 - final[1][1];
                }

                else if (i == 1 && j == 1)
                {
                    final[i][j] = 1 - final[i][j];
                    final[0][1] = 1 - final[0][1];
                    final[2][1] = 1 - final[2][1];
                    final[1][0] = 1 - final[1][0];
                    final[1][2] = 1 - final[1][2];
                }
                else if (i == 1 && j == 2)
                {

                    final[i][j] = 1 - final[i][j];
                    final[0][2] = 1 - final[0][2];
                    final[2][2] = 1 - final[2][2];
                    final[1][1] = 1 - final[1][1];
                }
                else if (i == 2 && j == 0)
                {
                    final[i][j] = 1 - final[i][j];
                    final[1][0] = 1 - final[1][0];
                    final[2][1] = 1 - final[2][1];
                }
                else if (i == 2 && j == 1)
                {
                    final[i][j] = 1 - final[i][j];

                    final[1][1] = 1 - final[1][1];
                    final[2][0] = 1 - final[2][0];
                    final[2][2] = 1 - final[2][2];
                }
                else if (i == 2 && j == 2)
                {
                    final[i][j] = 1 - final[i][j];
                    final[1][2] = 1 - final[1][2];
                    final[2][1] = 1 - final[2][1];
                }
                // for (int i = 0; i < 3; i++)
                // {
                //     for (int j = 0; j < 3; j++)
                //     {
                //         cout << final[i][j];
                //     }
                //     cout << endl;
                // }
            }
            // cout << endl;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << final[i][j];
        }
        cout << endl;
    }
}
