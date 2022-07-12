
#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
Input:
3111989
13091989
77145199750673
0

Output:
317^1 9817^1
17^2 89^1 509^1
328439^1 234884407^1

The largest integer given in the input file has 15 digits
*/

// SOLVED USING TRAIL_FACTORISATION MAETHOD

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
            n /= d;
        }
    }
    if (n > 1)
        factMpp.insert({n, 1});
    return factMpp;
}

int main()
{

    while (true)
    {
        long long n;
        cin >> n;
        if (n == 0)
            return 0;
        auto ans = trial_division1(n);
        for (auto x : ans)
        {
            cout << x.first << "^" << x.second << " ";
        }
    }
}