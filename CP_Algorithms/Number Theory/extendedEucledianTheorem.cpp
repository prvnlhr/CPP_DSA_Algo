#include <iostream>
using namespace std;

/*


CODE TO FIND GCD of a,b in logarithmic time O(log min(a,b))

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}


While the Euclidean algorithm calculates only the greatest common divisor (GCD) of two integers a and b,
the extended version also finds a way to represent GCD in terms of  and , i.e. coefficients  and  for which:


                                a.x + b.y = gcd(a,b)

                        ex____  gcd(55, 80) = 5
                                55.3 + 80.(-20) = 5

                                Input: a = 30, b = 20
                                Output: gcd = 10
                                        x = 1, y = -1
                                (Note that 30*1 + 20*(-1) = 10)

                                Input: a = 35, b = 15
                                Output: gcd = 5
                                        x = 1, y = -2
                                (Note that 35*1 + 15*(-2) = 5)



The extended Euclidean algorithm updates results of gcd(a, b) using the results calculated by recursive call gcd(b%a, a).


            x and y are results for inputs a and b,
            a.x + b.y = gcd                      ----(1)

            And x1 and y1 are results for inputs b % a and a
            (b % a).x1 + a.y1 = gcd

            When we put b%a = (b - (⌊b/a⌋).a) in above
            we get following,

            (b - (⌊b/a⌋).a).x1 + a.y1  = gcd   , Note that ⌊b/a⌋ is floor(b/a)

            Above equation can also be written as below
            b.x1 + a.(y1 - (⌊b/a⌋).x1) = gcd      ---(2)

            After comparing coefficients of 'a' and 'b' in (1) and
            (2), we get following

            x = y1                    or    x = y1 - ⌊b/a⌋ * x1
            y = x1 - ⌊b/a⌋ * y1             y = x1









*/

int gcdExtended(int a, int b, int &x, int &y)
{

    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;

    int g = gcdExtended(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

int main()
{

    int x, y, a, b;
    a = 34;
    b = 24;
    int g = gcdExtended(a, b, x, y);

    cout << g << " " << a << " " << b << " " << x << " " << y;
}

/*


Example of above code


  34x 24y = 2

  a = 34, b = 24

  calling gcd(a, b) => gcd(34, 24)

  gcd(34, 24) --> gcd(b, a%b) --> gcd(24, 10)
  gcd(24, 10) --> gcd(b, a%b) --> gcd(10, 4)
  gcd(10, 4) --> gcd(b, a%b) --> gcd(4, 2)
  gcd(4, 2) --> gcd(b, a%b) --> gcd(2, 0)

  gcd(2, 0) , now b == 0, gcd = a.x + b.y
                              = a.x + 0.y
      as b == 0, gcd is a,  2 = 2 *1 + 0

      therefore, x = 1 , y = 0 and gcd = g = 2

      now, we have derived,  x = y1
                             y = x1 - y1 + (a/b)


    now, when we can go backwards up the recursive calls,
    we will use x = 1, y = 0, calculate previously



    2 = gcd( 2 ,  0 ) => 2.x + 0.y =>    2.1 + 0.0 = 2
                                         x = 1 , y = 0


    now,   x = y1;
           y = x1 - y1 * (a / b);

    now, what is x1 and y1 ??. x1 is x from previous
    step and y1 is y from previous step



    2 = gcd(4, 2)   => 4.x + 2.y =>
                     = 4(y1) + 2(x1 - y1 *(a/b))
                     = 4(0) + 2(1 - 0 *(4/2))
                     = 4 * 0  +  2 * 1 , so x = 0; y = 1

    2 = gcd(10, 4)   => 10.(y1) + 4.(x1 - y1 *(a/b))
                      = 10. 1 + 4.(0 - 1*(10/4))
                      = 10.1 + 4.(-2)

    2 = gcd(24, 10)  => 24.(y1) + 10.(x1 - y1 *(a/b))
                      = 24.(-2) + 10.(1 - (-2) *(24/10))
                      = 24.(-2) + 10.(5)


    2 = gcd(34, 24)  => 34.(5) + 24.(-2-5*(34/24))
                      = 34.5  + 24.(-7)



                      so, finally x = 5 , y = -7 and gcd = 2









*/