#include <iostream>
using namespace std;

bool isPrime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{

    int n;
    cin >> n;
    bool ans = isPrime(n);
    cout << ans << "\n";
}
