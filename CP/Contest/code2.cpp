/* @AshishKingdom */

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define ul unsigned long int
#define forir(a, b) for (ul i = a; i < b; i++)
#define forirs(a, b, s) for (ul i = a; i < b; i += s)
#define forn(n) for (ul i = 0; i < n; i++)
#define pb push_back

template <typename T>
void printv(vector<T> &v)
{
    for (ul i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << '\n';
}

template <typename T>
void input(vector<T> &v, ul n)
{
    T x;
    for (ul i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
}

bool miller_rabin_test(ul n, ul d, ul r, ul a = 0)
{
    ul d0 = d, x = 1;
    if (a == 0)
    {
        a = 2 + rand() % (n - 3), d0 = d, x = 1;
    }
    while (d0 > 0)
    {
        if (d0 & 1)
            x = (x * a) % n;
        a = (a * a) % n;
        d0 >>= 1;
    }
    x %= n;
    if (x == 1 || x == n - 1)
        return true;
    while (d != (n - 1))
    {
        x = (x * x) % n;
        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
        d *= 2;
    }
    return false;
}

bool is_prime_fast(ul p, int k = 5)
{
    if (p <= 1)
        return false;
    if (p > 1 && p < 4)
        return true;
    if (p % 2 == 0)
        return false;
    ul r = 0, d = p - 1;
    while ((d & 1) == 0)
    {
        d >>= 1;
        r++;
    }
    while (k--)
    {
        if (!miller_rabin_test(p, d, r))
            return false;
    }
    return true;
}

void generate_primes(ul n, vector<ul> &r)
{
    // Sieve of Eratosthenes
    if (n < 2)
        return;
    if (n < 3)
    {
        r.push_back(2);
        return;
    }
    if (n < 4)
    {
        r.push_back(2);
        r.push_back(3);
        return;
    }
    vector<bool> p(n + 1, true);
    ul n0 = sqrt(n);
    for (ul i = 2; i <= n0; i++)
    {
        if (p[i])
        {
            for (ul j = i * i; j <= n; j += i)
                p[j] = 0;
        }
    }
    for (ul i = 2; i <= n; i++)
    {
        if (p[i])
            r.push_back(i);
    }
}

ul bin_power(ul a, ul n, ul m)
{
    ul r = 1;
    while (n > 0)
    {
        if (n & 1)
            r = (r * a) % m;
        a = (a * a) % m;
        n >>= 1;
    }
    return r;
}

ul gcd(ul a, ul b)
{
    if (a < b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

void factorize(ul n, vector<ul> &r)
{
    for (ul i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
            r.push_back(i);
    }
    for (ll i = r.size() - 1; i >= 0; i--)
    {
        if (r[i] * r[i] != n)
        {
            r.push_back(n / r[i]);
        }
    }
}
void prime_factorize(ul n, vector<ul> &r)
{
    while (n % 2 == 0)
    {
        n /= 2;
        r.push_back(2);
    }
    for (ul i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            n /= i;
            r.push_back(i);
        }
    }
    if (n > 2)
        r.push_back(n);
}

ul sum_of_factors(ul n)
{
    ul curr_fac, res = 1, curr_sum;
    for (ul i = 2; i * i <= n; i++)
    {
        curr_fac = 1;
        curr_sum = 1;
        while (n % i == 0)
        {
            n /= i;
            curr_fac *= i;
            curr_sum += curr_fac;
        }
        res *= curr_sum;
    }
    if (n > 2)
        res *= (n + 1);
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ul t;
    cin >> t;
    int board[9][9], A, B, nq;
    while (t--)
    {
        cin >> A >> B;
        cout << A << " " << B << "\n";

        // clear board
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
            {
                board[i][j] = 0;
            }
        }
        board[A][B] = 1;
        nq = 0;
        if (A == 8)
        {
            if (B == 8)
            {
                nq = 2;
                board[A - 1][B - 2] = 2;
            }
            else if (B == 1)
            {
                nq = 2;
                board[A - 1][B + 2] = 2;
            }
            else
            {
                nq = 2;
                board[A - 2][B - 1] = 2;
                board[A - 2][B + 1] = 2;
            }
        }
        else if (A == 1)
        {
            if (B == 8)
            {
                nq = 2;
                board[A + 1][B - 2] = 2;
                // board[A + 2][B - 1] = 2;
            }
            else if (B == 1)
            {
                nq = 2;
                board[A + 1][B + 2] = 2;
                // board[A + 2][B + 1] = 2;
            }
            else
            {
                nq = 2;
                board[A + 2][B - 1] = 2;
                board[A + 2][B + 1] = 2;
            }
        }
        else
        {
            if (B == 8)
            {
                nq = 2;
                board[A - 1][B - 2] = 2;
                board[A + 1][B - 2] = 2;
            }
            else if (B == 1)
            {
                nq = 2;
                board[A - 1][B + 2] = 2;
                board[A + 1][B + 2] = 2;
            }
            else
            {
                if (B >= 3 && B <= 6)
                {
                    nq = 2;
                    board[A - 1][B - 2] = 2;
                    board[A + 1][B + 2] = 2;
                }
                else if (A >= 3 && A <= 6)
                {
                    nq = 2;
                    board[A - 2][B - 1] = 2;
                    board[A + 2][B + 1] = 2;
                }
                else
                {
                    if (B == 2 && A == 2)
                    {
                        board[A + 2][B - 1] = 2;
                        board[A - 1][B + 3] = 2;
                    }
                    else if (B == 2 && A == 7)
                    {
                        board[A + 1][B + 3] = 2;
                        board[A - 2][B - 1] = 2;
                    }
                    else if (B == 7 && A == 2)
                    {
                        board[A - 1][B - 3] = 2;
                        board[A + 2][B + 1] = 2;
                    }
                    else
                    {
                        board[A + 1][B - 3] = 2;
                        board[A - 2][B + 1] = 2;
                    }
                }
            }
        }
        // print the board
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << "\n";
    }
    return 0;
}