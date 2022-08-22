#include <iostream>
#define ll long long
using namespace std;

int main()
{

    int m, n;
    cin >> m >> n;


    //> Solution 1:
    int ANS = 0;

    if (n == 1 && m == 1)
    {
        ANS = 0;
    }
    else if (m == 1 && n != 1)
    {

        if (n % 2 == 0)
        {

            ANS = n / 2;
        }
        else
        {
            ANS = ((n - 1) / 2);
        }
    }

    else if (m != 1 && n != 1)
    {

        if (n % 2 == 0)
        {

            ANS = (n / 2) * (m);
        }
        else
        {
            ANS = (n - 1) / 2 * m + (m / 2);
        }
    }
    cout << ANS << endl;



    /*
    > Solution 2: after careful observation, eliminating unwanted cases


    if (n == 1 && m == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        if (n % 2 == 0)
        {

            cout << n / 2 * m;
        }
        else
        {
            cout << n / 2 * m + m / 2;
        }
    }
     */
}
