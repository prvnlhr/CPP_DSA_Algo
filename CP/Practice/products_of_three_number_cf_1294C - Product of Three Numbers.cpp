#include <iostream>

using namespace std;

int main()
{

    int n, t;

    cin >> t;

    while (t--)
    {

        cin >> n;
        int a = 1, b = 1, c = 1;

        for (int i = 2; i * i <= n; i++)
        {

            if (n % i == 0)
            {
                a = i;
                break;
            }
        }
        n = n / a;
        // cout << "n" << n << endl;
        for (int j = 2; j * j <= n; j++)
        {

            if (n % j == 0)
            {
                if (j != a)
                {

                    b = j;
                    break;
                }
            }
        }

        c = n / b;

        if (a != b && b != c && a != 1 && b != 1 && c != 1)
        {
            cout << "YES" << endl;
            cout << a << " " << b << " " << c << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}