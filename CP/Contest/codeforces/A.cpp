

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        int a, b, c;
        cin >> a >> b >> c;

        int time_1;
        int time_2;

        if (a < b && b < c)
        {
            cout << 1 << endl;
        }
        else if (a > b && b > c)
        {

            time_1 = a - 1;
            time_2 = b - 1;
            if (time_1 < time_2)
            {

                cout << 1 << endl;
            }
            else if (time_1 > time_2)
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 3 << endl;
            }
        }
        else
        {
            if (b > c)
            {
                time_1 = a - 1;
                time_2 = (b - c) + ((b - c) - 1);
                if (time_1 < time_2)
                {

                    cout << 1 << endl;
                }
                else if (time_1 > time_2)
                {
                    cout << 2 << endl;
                }
                else
                {
                    cout << 3 << endl;
                }
            }
            else if (b < c)
            {
                // cout << "c3" << endl;
                time_1 = a - 1;
                time_2 = (c - b) + (c - b);
                // cout << time_1 << " " << time_2 << endl;
                if (time_1 < time_2)
                {
                    cout << 1 << endl;
                }
                else if (time_1 > time_2)
                {
                    cout << 2 << endl;
                }
                else
                {
                    cout << 3 << endl;
                }
            }
        }
    }
}
