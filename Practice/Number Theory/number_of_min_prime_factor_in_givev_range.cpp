

/*

We have given a range of numbers, let say 1 to 1000000.
We are given 't' test cases.
for every test case we are given n queries.

for ex. t = 5
n = 2
n = 3
n = 4
n = 5
n = 6

for every n, when have to find the numbers of numbers in given range of which
n is min prime factor.

Ex n = 3 and range is {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25}
numbers which has n = 3 as min prime factors are, [3 9 15 21}, total 4 numbers.
So output is 4.
Note: for 12, 3 is a prime factor, but it is not minimum, minimum is 2 for 12.

"REFER STRIVERS PRIME AND SIEVE L3"
 */

#include <iostream>
#include <vector>
using namespace std;

int N = 25;
vector<int> sieve(N + 1, 1);

void createSieve()
{

    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i] == 1)
        {
            for (int j = i * i; j <= N; j += i)
            {
                if (sieve[j] != 0)
                {
                    sieve[i]++;
                    sieve[j] = 0;
                }
            }
        }
    }
    cout << "sieve : ";

    for (auto x : sieve)
    {
        cout << x << " ";
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    createSieve();
    while (t--)
    {
        int x;
        cin >> x;
        cout << "-> " << sieve[x] << endl;
    }
}
