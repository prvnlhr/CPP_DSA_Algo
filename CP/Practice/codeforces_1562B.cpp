

#include <iostream>
#include <vector>

using namespace std;

int n = 100;
vector<bool> is_prime(n + 1, true);

void createSieve()
{
    is_prime[0] = is_prime[1] = false;

    
    for (int i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

void solve(int n, string s)
{

    // >> First case : consider all single digit numbers of  string
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9')
        {
            cout << 1 << endl;
            cout << s[i] << endl;
            return;
        }
    }

    // >> Second case : consider all single digit numbers of  string

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            int num = (((s[i] - '0') * 10) + s[j] - '0');
            cout << num << endl;
            if (!is_prime[(s[i] - '0') * 10 + (s[j] - '0')])
            {
                cout << 2 << endl;
                cout << s[i] << s[j] << endl;
                return;
            }
        }
    }
}
int main()
{

    createSieve();
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        string s;
        cin >> s;
        solve(k, s);
    }
}
