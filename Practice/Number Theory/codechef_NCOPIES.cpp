#include <iostream>
#define ll long long
using namespace std;
/*
9
2 2
00
2 4
11
3 3
101
4 4
1010
4 3
1010
5 4
11110
5 3
11110
8 4
11100111
8 3
11100111

4
1
2
2
2
2
1
1
3
 */
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        int SUM = 0;
        for (int i = 0; i < n; i++)
        {
            SUM = SUM + (s[i] - '0');
        }

        if (SUM == 0)
        {
            cout << n * m << endl;
        }

        else if (SUM % 2 == 1 && m % 2 == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            if (m % 2 == 0)
            {

                int left_0 = 0;
                int right_0 = 0;

                for (int i = 0; i < n; i++)
                {

                    if (s[i] == '1')
                    {
                        break;
                    }
                    left_0++;
                }
                for (int i = n - 1; i >= 0; i--)
                {
                    if (s[i] == '1')
                    {
                        break;
                    }
                    right_0++;
                }

                cout << left_0 + right_0 + 1 << endl;
            }

            else
            {
                int cnt = 1;
                int currSUM = 0;
                int i;

                for (i = 0; i < n; i++)
                {
                    currSUM = currSUM + s[i] - '0';
                    if (currSUM == SUM / 2)
                    {
                        break;
                    }
                }
                i++;
                while (s[i] == '0')
                {
                    cnt++;
                    i++;
                }

                cout << cnt << endl;
            }
        }
    }
}
