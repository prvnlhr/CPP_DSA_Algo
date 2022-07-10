#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> leastPrimeFactor(int n)
    {
        vector<int> sieve(n + 1, 0);
        sieve[0] = 0;
        sieve[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            if (sieve[i] == 0)
            {

                sieve[i] = i;
                for (int j = i * i; j <= n; j += i)
                {
                    if (sieve[j] == 0)
                    {
                        sieve[j] = i;
                    }
                }
            }
        }

        vector<int> ans;

        for (int i = 0; i <= n; i++)
        {
            ans.push_back(sieve[i]);
        }

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<int> ANS = ob.leastPrimeFactor(n);

        for (int i = 1; i <= n; i++)
        {
            cout << ANS[i] << " ";
        }
        cout << endl;
    }
}