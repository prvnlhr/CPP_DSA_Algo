#include <iostream>

using namespace std;

void printPrimes(int N)
{

    for (int d = 2; d * d <= N; d++)
    {
        while (N % d == 0)
        {

            cout << d << " ";
            N /= d;
        }
    }
}

int main()
{

    int n;
    cin >> n;
    printPrimes(n);
}