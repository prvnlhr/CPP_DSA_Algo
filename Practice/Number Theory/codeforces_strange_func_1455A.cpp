
#include <iostream>
#define ll long long
using namespace std;

/**
 * > Input is of size 10^100, which is very big. So store in string
 * According to problem there is a function f(x), to ehich if you pass x is basically reverses it
 * ? Ex -> 23, f(23) -> 32
 * if there is any trialing zero it will remove it,
 * ? Ex -> 230, f(230) -> 030 -> 30
 * now there is another function g(x) = x / f(f(x))
 * Now when we carefully look at denominator we find that if x has not trailing zero like 23 or 233 it will be same
 * ? f(f(x)) -> f(f(23)) -> f(32) -> 23, same as original
 * ? f(f(230)) -> f(f(230)) -> f(32) -> 23
 * Now we have to find for the range from 1 to n, for every x, the number of diff value of g(x).
 * ? Ex n = 4 -> 1, 2, 3, 4 -> g(1), g(2), g(3), g(4) == all have value 1, so number of diff vals is 1
 * ? EX n = 10 -> 1, 2, 3 ... 10 -> from 1 to 9 all have g(x) as 1, except 10, which g(x) as 10. so 2 diff val{1 , 10}
 * 
 * Now if we look for the range 10 -> 99, there are only 2 diff values, {10, 20} , rest all have g(x) = 1
 * Now if we look for the range 100 -> 999, there are 1 diff values 
 * Now if we look for the range 1000 -> 9999 , there is 1 diff values
 * So we conclude that every increse in no. of digit diff values increse,
 * ? like 2 digit no -> 2 diff values, 3 digit no -> 3 diff value and so on.
 * * So finally we have to cout the length of n, i.e number of digits of n,
 * * As n is take as string we can do this easily
 */

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        string n;
        cin >> n;

        cout << n.length() << endl;
    }
}
