#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a[7];
int main()
{
    int n, t;
    while (~scanf("%d", &n))
    {
        memset(a, 0, sizeof a);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &t);
            if (t == 1)
                ++a[1];
            else if (t == 2)
                ++a[2];
            else if (t == 3)
                ++a[3];
            else if (t == 4)
                ++a[4];
            else if (t == 6)
                ++a[6];
        }

        
        if (a[1] != n / 3)
        {
            cout << "-1\n";
            continue;
        }
        else if (a[2] + a[3] != n / 3 || a[4] + a[6] != n / 3)
        {
            cout << "-1\n";
            continue;
        }
        else if (a[4] > a[2] || a[3] > a[6])
        {
            cout << "-1\n";
            continue;
        }

        for (int i = 0; i < a[4]; i++)
        {
            printf("1 2 4\n");
        }
        for (int i = 0; i < a[2] - a[4]; i++)
        {
            printf("1 2 6\n");
        }
        for (int i = 0; i < a[3]; i++)
        {
            printf("1 3 6\n");
        }
    }
    return 0;
}