#include <bits/stdc++.h>



// WRONG SELF TRIED
using namespace std;
long long N = 10 ^ 18;
vector<bool> sieve(N + 1, true);

int main()
{
    long long n;
    cin >> n;
    unordered_map<long long, long long> factMpp;
    vector<long long> factorization;
    int ANS = 1;

    int cnt = 0;
    while (n % 2 == 0)
    {
        cnt++;

        factorization.push_back(2);

        // if (factMpp.find(2) != factMpp.end())
        // {
        //     factMpp[2]++;
        // }
        // else
        // {

        //     factMpp.insert({2, 1});
        // }

        n /= 2;
    }
    ANS = ANS * (cnt + 1);

    int cnt1;
    for (long long d = 3; d * d <= n; d += 2)
    {

        cnt1 = 0;
        while (n % d == 0)
        {
            cnt1++;
            // if (factMpp.find(d) != factMpp.end())
            // {
            //     factMpp[d]++;
            // }
            // else
            // {
            //     factMpp.insert({d, 1});
            // }
            factorization.push_back(d);

            n /= d;
        }
    }
    ANS = ANS * (cnt1 + 1);
    if (n > 1)
    {
        // factMpp.insert({n, 1});
        factorization.push_back(n);
        ANS = ANS * (1 + 1);
    }

    // for (auto el : factorization)
    // {
    //     cout << el << " ";
    // }
    // cout << endl;
    // int ANS = 1;

    // for (auto x : factMpp)
    // {
    //     ANS = ANS * (x.second + 1);
    // }
    cout << ANS << endl;
}
