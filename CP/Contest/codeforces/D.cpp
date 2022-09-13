

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
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        vector<int> req(n);
        for (int i = 0; i < n; i++)
        {

            req[i] = b[i] - a[i];
        }

        sort(req.begin(), req.end());

        int i = 0;
        int j = n - 1;

        int numDays = 0;

        while (i < j)
        {

            if (req[i] + req[j] >= 0)
            {
                numDays++;
                i++;
                j--;
            }
            else if (i < j)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        cout << numDays << endl;
    }
}
