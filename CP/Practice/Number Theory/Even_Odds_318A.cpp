#include <iostream>

using namespace std;

int main()
{

    // wrong
    // long long n, k;
    // int mid;
    long long int n, k, mid;

    cin >> n >> k;

    if (n % 2 == 0)
    {
        mid = n / 2;
    }
    else
    {
        mid = (n + 1) / 2;
    }

    if (k <= mid)

    {

        cout << (2 * k) - 1;
    }
    else
    {
        cout << 2 * (k - mid);
    }
}