#include <iostream>
#include <cstdlib>
#include<climits>
#define ll long long
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int X, Y;
        cin >> X >> Y;
        int start;
        int end;

        start = min(X, Y);
        end = max(X, Y);
        int ANS = INT_MAX;

        for (int i = start; i <= end; i++)
        {
            ANS = min(max(abs(X - i), abs(Y - i)), ANS);
        }
        cout << ANS << endl;
    }
}
