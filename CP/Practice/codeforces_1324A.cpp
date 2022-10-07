#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;
        vector<int> arr(n);
        int parVal = 0;
        string ANS = "YES";

        /*
        * Based on the observation, we found that;
        > If all elements are even or all elements are odd, then only solution possoible i.e, "YES".
        > In case of mixed elements, no solution i.e, "NO".
        

         */

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {

                parVal = arr[i] % 2;
            }
            else
            {
                if (arr[i] % 2 != parVal)
                {
                    ANS = "NO";
                    break;
                }
            }
        }
        cout << ANS << endl;
        // cout << endl;
    }
}