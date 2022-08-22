/*

A Diophantine equation is a polynomial equation, usually in two or more unknowns,
such that only the integral solutions are required. An Integral solution is a solution
such that all the unknown variables take only integer values.


Given three integers a, b, c representing a linear equation of the form : ax + by = c.
Determine if the equation has a solution such that x and y are both integral values.


Input : a = 3, b = 6, c = 9
Output: Possible
Explanation : The Equation turns out to be,
3x + 6y = 9 one integral solution would be
x = 1 , y = 1

Input : a = 3, b = 6, c = 8
Output : Not Possible
Explanation : o integral values of x and y
exists that can satisfy the equation 3x + 6y = 8

Input : a = 2, b = 5, c = 1
Output : Possible
Explanation : Various integral solutions
possible are, (-2,1) , (3,-1) etc.

DEGENERATE CASE :
A degenerate case that need to be taken care of is when, a = b = 0 .
It is easy to see that we either have no solutions or infinitely many solutions,
depending on whether, c = 0 or not.
In the rest of this article, we will ignore this case.


Solution:
For linear Diophantine equation equations, integral solutions exist if and only if,
the GCD of coefficients of the two variables divides the constant term perfectly.
In other words the integral solution exists if, GCD(a ,b) divides c.
Thus the algorithm to determine if an equation has integral solution
is pretty straightforward.


1. Find GCD of a and b
2. Check if c % GCD(a ,b) ==0
3. If yes then print Possible, else print Not Possible



*/

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {

        return gcd(b, a % b);
    }
}

int main()
{

    int a, b, c;

    cin >> a >> b >> c;

    // step 1. find GCD of a,b :

    int GCD = gcd(a, b);

    if (c % GCD == 0)
    {
        cout << "Possible";
    }
    else
    {
        cout << "Not Possible";
    }
}