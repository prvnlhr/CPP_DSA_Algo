
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int N = 10^18;

vector<long long> sieve(N + 1);
void createSieve()
{

    for (long long i = 1; i <= N; i++)
    {
        sieve[i] = i;
    }

    for (long long i = 2; i * i <= N; i++)
    {

        if (sieve[i] == i)
        {

            for (long long j = i * i; j <= N; j += i)
            {

                if (sieve[j] = j)
                {

                    sieve[j] = i;
                }
            }
        }
    }
}

map<long long, long long> solve(long long n)
{
    map<long long, long long> factMpp;

    while (n != 1)
    {

        cout << sieve[n] << " ";
        if (factMpp.find(sieve[n]) != factMpp.end())
        {
            factMpp[sieve[n]]++;
        }
        else
        {
            factMpp.insert({sieve[n], 1});
        }

        n = n / sieve[n];
    }

    return factMpp;
}

// map<long long, long long> trial_division1(long long n)
// {
//     vector<long long> factorization;
//     map<long long, long long> factMpp;

//     while (n % 2 == 0)
//     {

//         if (factMpp.find(2) != factMpp.end())
//         {
//             factMpp[2]++;
//         }
//         else
//         {

//             factMpp.insert({2, 1});
//         }

//         n /= 2;
//     }

//     for (long long d = 3; d * d <= n; d += 2)
//     {
//         while (n % d == 0)
//         {
//             if (factMpp.find(d) != factMpp.end())
//             {
//                 factMpp[d]++;
//             }
//             else
//             {
//                 factMpp.insert({d, 1});
//             }
//             n /= d;
//         }
//     }
//     if (n > 1)
//     {
//         factMpp.insert({n, 1});
//     }
//     return factMpp;
// }

int main()
{
    long long n;
    cin >> n;
    createSieve();
    auto ans = solve(n);
    long long ANS = 1;
    for (auto x : ans)
    {

        ANS = ANS * (x.second + 1);
    }

    cout << ANS;
}