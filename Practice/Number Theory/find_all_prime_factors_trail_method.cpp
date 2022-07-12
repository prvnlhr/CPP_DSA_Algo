
#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> trial_division1(long long n)
{
    vector<long long> factorization;
    map<long long, long long> factMpp;
    for (long long d = 2; d * d <= n; d++)
    {
        while (n % d == 0)
        {
            if (factMpp.find(d) != factMpp.end())
            {
                factMpp[d]++;
            }
            else
            {
                factMpp.insert({d, 1});
            }
            // factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        // factorization.push_back(n);
        factMpp.insert({n, 1});
    return factMpp;
}

void printPrimes(long long N)
{

    for (long long d = 2; d * d <= N; d++)
    {
        while (N % d == 0)
        {

            cout << d << " ";
            N /= d;
        }
    }
    if (N > 1)
    {
        cout << N << " ";
    }
}

int main()
{
    long long n;
    cin >> n;
    printPrimes(n);
}