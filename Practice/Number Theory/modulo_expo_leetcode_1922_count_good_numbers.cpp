#include <iostream>
#define ll long long
using namespace std;

/*

A digit string is good if the digits (0-indexed) at even indices are 
even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions 
are even and the digits (5 and 2) at odd positions are prime. However, 
"3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. 
Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.



APPROACH ::

Given  n = let say 7
So we have to count the number of strings of length 7 digits, which
satisfies the required condition of a good string.
Goood string =>  at even index -> even numbers between 0 to 9 {0, 2, 4, 6, 8}
             =>  at odd index -> prime between 0 to 9 {2, 3, 5, 7} 

Now if we start forming strings of length say n = 7,
then what is the minimum number we can start from, ->  0000000 and ends at 9999999
Now from 0000000 to  9999999 we have to count all the strings which are good strings.

Now when we carefully observe we found that for good string, at even index we
can have 0, 2, 4, 6, 8 and at odd index we can have 2, 3, 5, 7

so for seven digit strings ->   _5*e _4*o _5*e _4*o _5*e _4*o _5*e_
                           ->   5^(4 even places) * 4^(3 odd places)

so from above line -> no of even places = 4
                   -> no of odd places  = 3
                   5^(even places) * 4^(odd places) -> this is the required formula to get number of strings.


Now as the problem constraints states that, n can be 10^15 which is very large number.
and we have to return and in mod 10^9 + 7.

so to calculate (5^(eve_places) %mod * 4^(3 odd places) % mod ) % mod,
we can using modular exponentiation for quickly calculating the ouptut.





*/

ll binpower(ll a, ll b, ll mod)
{
    ll res = 1;

    a = a % mod;

    while (b > 0)
    {

        if (b % 2 == 1)
        {
            res = res * a % mod;
        }
        b = b / 2;
        a = a * a % mod;
    }
    return res;
}
ll countGoodNumbers(ll n)
{

    int mod = 1e9 + 7;
    ll num_odd_places = n / 2;
    ll num_even_places = (n + 1) / 2;

    ll res = (binpower(5, num_even_places, mod) * binpower(4, num_odd_places, mod)) % mod;

    return res;
}

int main()
{

    ll n;
    cin >> n;
    cout << countGoodNumbers(n) << endl;
}
