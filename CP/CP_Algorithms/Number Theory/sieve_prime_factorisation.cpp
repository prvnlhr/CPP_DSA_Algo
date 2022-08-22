

#include <iostream>
#include <vector>
using namespace std;

int N = 1000000;

vector<int> sieve(N + 1);

void printSieve()
{
    for (int i = 2; i < sieve.size(); i++)
    {
        cout << sieve[i] << " ";
    }

    cout << endl;
}
void createSieve()
{

    for (int i = 1; i <= N; i++)
    {
        sieve[i] = i;
    }

    for (int i = 2; i * i <= N; i++)
    {

        if (sieve[i] == i)
        {

            for (int j = i * i; j <= N; j += i)
            {

                if (sieve[j] = j)
                {

                    sieve[j] = i;
                }
            }
        }
    }
}

int main()
{

    int t;
    cin >> t;
    createSieve();
    // printSieve();

    while (t--)
    {
        int n;
        cin >> n;

        while (n != 1)
        {

            cout << sieve[n] << " ";

            n = n / sieve[n];
        }
        cout << "" << endl;
    }
}
