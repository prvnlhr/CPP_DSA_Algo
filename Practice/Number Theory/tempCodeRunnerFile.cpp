#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll N = 1000000;
vector<bool> sieve(N + 1, true);
vector<ll> primes(N + 1);

void createSieve()
{

    sieve[0] = sieve[1] = 0;

    for (ll i = 2; i * i <= N; i++)
    {
        if (sieve[i] == 1)
        {
            for (ll j = i * i; j <= N; j += i)
                sieve[j] = 0;
        }
    }

    ll j = 0;
    for (ll p = 2; p <= N; p++)
    {
        if (sieve[p] == 1)
        {

            primes[j] = p;

            // primesquare[p * p] = true;
            j++;
        }
    }
}

ll mulmod(ll a, ll b, ll c)
{
    long long x = 0, y = a % c;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % c;
        }
        y = (y * 2) % c;
        b /= 2;
    }
    return x % c;
}
/*
 * modular exponentiation
 */
ll modulo(ll base, ll exponent, ll mod)
{
    ll x = 1;
    ll y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}

/*
 * Miller-Rabin primality test, iteration signifies the accuracy
 */
bool miller(ll p, int iteration)
{
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && p % 2 == 0)
    {
        return false;
    }
    ll s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < iteration; i++)
    {
        ll a = rand() % (p - 1) + 1, temp = s;
        ll mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return false;
        }
    }
    return true;
}

int countDivisors(long long n)
{
    int iteration = 5;

    if (n == 1)
        return 1;

    createSieve();

    // int ans = 1;

    // for (long long i = 0;; i++)
    // {
    //     if (primes[i] * primes[i] * primes[i] > n)
    //         break;

    //     int cnt = 1;
    //     while (n % primes[i] == 0)
    //     {
    //         n = n / primes[i];
    //         cnt = cnt + 1;
    //     }

    //     ans = ans * cnt;
    // }
    int ans = 1;
    for (auto &p : primes)
    {
        if (p * p * p > n)
            break;
        int cn = 1;
        while (n % p == 0)
        {
            n /= p;
            ++cn;
        }
        ans *= cn;
    }

    if (miller(n, iteration))
    {
        // cout << "n: " << n << " " << miller(n, iteration) << endl;

        ans = ans * 2;
    }

    else if (miller(sqrt(n), iteration))
    {

        ans = ans * 3;
    }

    else if (n != 1)
    {

        ans = ans * 4;
    }

    return ans;
}
int main()
{

    int t;
    cin >> t;
    vector<ll> arr;
    arr.reserve(t);
    while (t--)
    {
        ll n;
        cin >> n;
        arr.push_back(n);
    }

    for (auto x : arr)
    {
        cout << countDivisors(x) << endl;
    }
}
