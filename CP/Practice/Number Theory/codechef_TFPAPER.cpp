#include <iostream>
#include<algorithm>
#define ll long long
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int N, K;
        cin >> N >> K;

        if (N == K)
        {
            cout << 0 << endl;
        }
        else if (K == 0)
        {
            cout << N << endl;
        }
        else
        {
            cout << N - K << endl;
        }
    }
}
