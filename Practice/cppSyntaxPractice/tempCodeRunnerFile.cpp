#include <iostream>

using namespace std;

int main()
{

    long long n, k;

    cin >> n >> k;

    int mid;
    if (n % 2 == 0)
    {
        mid = n / 2;
    }
    else
    {
        mid = (n / 2) + 1;
    }

    if (k <= mid)

    {

        cout << (2 * k) - 1;
    }
    else
    {
        int indx = k - mid;

        cout << 2 * (k - (n + 1) / 2);
    }
}