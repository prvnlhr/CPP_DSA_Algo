#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;

        vector<int> B(n);

        for (int i = 0; i < n; i++)
        {
            cin >> B[i];
        }

        vector<int> A(n);

        A[0] = 1;

        for (int i = 0; i < n; i++)
        {

            if (i < n - 1)
            {
                if (B[i] == 0)
                {
                    A[i + 1] = A[i];
                }
                else
                {
                    A[i + 1] = A[i] + 1;
                }
            }
        }

        if ((A[0] + A[n - 1]) % 2 == B[n - 1])
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
    }
}
