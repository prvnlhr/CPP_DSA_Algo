
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<long long> printPrimes(long long n)
{
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++)
    {
        while (n % d == 0)
        {

            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int main()
{
    long long n;
    cin >> n;
    auto ans = printPrimes(n);
    for (auto x : ans)
    {
        cout << x << " ";
    }
}