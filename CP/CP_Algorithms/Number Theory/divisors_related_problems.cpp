#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = end; i >= start; i--)
#define FOREACH(x, b) for (auto x : b)

#define cout1(x) cout << x << endl;
#define cout2(x, y) cout << x << " " << y << endl;
#define cout3(x, y, z) cout << x << " " << y << " " << z << endl;

#define SUMOFN(arr) accumulate(arr.begin(), arr.end(), 0LL);
#define SORTASC(arr) sort(arr.begin(), arr.end());
#define SORTDSC(arr) sort(arr.begin(), arr.end(), greater<int>());

#define strLow(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define strUp(s) transform(s.begin(), s.end(), s.begin(), ::toupper);

#define lb(arr, ele) lower_bound(arr.begin(), arr.end(), ele);
#define ub(arr, ele) upper_bound(arr.begin(), arr.end(), ele);

typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> stint;
typedef map<int, int> mpint;
typedef pair<int, int> pi;
typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    /*
    * READ THIS
    * https://codeforces.com/blog/entry/22229#:~:text=Let%27s%20say%20we%20want%20to,exponent%20%2B%201)%20through%20combinatorics.
    >Let's say we want to count the number of divisors of a number. One way is to
    > check all numbers up to √n and check if n divides that number. The other way is
    > to get its prime factorization and get the product of (exponent + 1) through combinatorics.
    > Either method is O(√n) on average, thus O(n√n) if done for all numbers up to n.


    * But what if a problem asks us to print the number of divisors of all numbers from 1 to 10^7 under 3 seconds?
    > An O(n√n) algorithm will be too slow! When I tried counting divisors using the square root method, it ran for
    > about 61 seconds on my computer. That definitely won't run in time.
    > Fortunately, we can ''' tweak the Eratosthenes sieve to count the number of divisors more efficiently and elegantly'''.
    >> And you will see that this technique works not only for number of divisors, but also for
    >> generating sum of divisors(Ex problem-> 236B CF), totient function, biggest prime divisor, basically all functions that have to do with divisors!

     */

    int n;
    cin >> n;

    //> This code gives count of all  divisors form 1 to n


    //! Ex problem-> 236B CF
    //>> Ex.  n = 8 ,
    //>  1 -> 1
    //>  2 -> 2
    //>  3 -> 3
    //>  4 -> 3
    //>  5 -> 2
    //>  6 -> 4
    //>  7 -> 2
    //>  8 -> 4

    
    vector<int> divisors(n + 1);
    for (int i = 1; i <= n; ++i)
    {

        for (int j = i; j <= n; j += i)
        {

            ++divisors[j];
        }
    }
}
