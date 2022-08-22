#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main()
{

    int mat[5][5];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 1)
            {
                int ANS = abs(2 - i) + abs(2 - j);
                cout << ANS << endl;
                break;
            }
        }
    }
}
