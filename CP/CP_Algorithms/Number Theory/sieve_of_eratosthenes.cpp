#include <iostream>
#include <vector>

using namespace std;

int n = 1000;
vector<bool> sieve(n + 1, true);

/**
This func creats a sieve of n size, n can be the max constraint of the input size
* * Time Complexity: O(n*log(log(n))) , to create sieve.
* ! sieve is used when we have to query t test cases.
* > sieve reduces the time complexity by pre computing the Primes and storing in sieve array.
* ? Once the primes are pre computed, then for every query of 't' test-case find prime just takes O(1).
 */

void printSieve()
{
    for (int i = 2; i < sieve.size(); i++)
    {
        if (sieve[i] == 1)
        {

            cout << i << " ";
        }
    }
    cout << endl;
}

void createSieve()
{

    sieve[0] = sieve[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= n; j += i)
                sieve[j] = false;
        }
    }
}

// Question:
// For every number 'x' of the query print YES if prime else NO if not.

int main()
{

#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);

#endif

    int t;
    cin >> t;
    createSieve();
    while (t--)
    {
        int n;
        cin >> n;
        if (sieve[n])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
