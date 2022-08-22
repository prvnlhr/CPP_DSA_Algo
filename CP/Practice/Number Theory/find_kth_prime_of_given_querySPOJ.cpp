/*


The problem statement is really simple. There are some queries.
You are to give the answers.

Input
An integer stating the number of queries Q(equal to 50000), and Q lines follow,
each containing one integer K between 1 and 5000000 inclusive.

Output
Q lines with the answer of each query: the Kth prime number.

Input:
7
1
10
100
1000
10000
100000
1000000

Output:
2
29
541
7919
104729
1299709
15485863

*/

/*

When have to find the kth prime, let say k = 10 ( 1 <= k <= 5000000) ,
then 10th prime is 29.

now as there can be Q(1 < Q < 50000) query, we have to find for every k of query the kth prime.

This can be solve using seive technique  by pre computing the primes.
when we get the sieve, it will have true for all primes.
We can then store a the primes in an other array(let say primes).
Then finally to find the kth prime we return the kth value from primes array.

Now, there a catch,
As the sieve we created contains all primes and non prime numbers.
But we only want 5000000 first primes in primes array.
According to problem constraint, what should be the max size of sieve
to accomodate all numbers so that we can extract 5000000 primes from it.

TO solve this, at first  we will make a sieve of size 1e8 = 100000000

Then we will count all the indexes where it is true i.e primes
We will count until our count reaches 5000000.
At count = 5000000, we will get the  max index where our last 5000000th prime will reside.
Thus we will change our size of sieve from 100000000 to index we found(86028121).

by doing this we will reduce the memory taken by the sieve from 100000000 indexes to 86028121.

If we use 100000000, then we get memory TLE.


*/

#include <iostream>
#include <vector>
using namespace std;

int n = 100000000;

// int n = 86028121;

vector<bool> sieve(n + 1, true);

vector<int> primes;
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
    // _________________________________________________________

    // int cnt = 0;
    // int size = 1;
    // int limit = 5 * 1000000;
    // int i = 2;
    // while (i <= n)
    // {
    //     if (sieve[i] == true)
    //     {
    //         cnt++;
    //         if (cnt == limit)
    //         {
    //             size = i;
    //             break;
    //         }
    //     }

    //     i++;
    // }
    // cout << size << endl;

    // OR

    // int cnt = 0;
    // int size = 1;
    // int limit = 5 * 1000000;
    // for (int i = 2;; i++)
    // {
    //     if (sieve[i] == true)
    //     {

    //         cnt++;
    //     }
    //     if (cnt == limit)
    //     {
    //         size = i;
    //         break;
    //     }
    // }

    // cout << size;
    // _________________________________________________________
    for (int i = 2; i <= n; i++)
    {
        if (sieve[i])
        {
            primes.push_back(i);
        }
    }
}
int main()
{

    int t;
    cin >> t;
    createSieve();
    // while (t--)
    // {
    //     int k;
    //     cin >> k;
    //     cout << primes[k - 1] << endl;
    // }
}
