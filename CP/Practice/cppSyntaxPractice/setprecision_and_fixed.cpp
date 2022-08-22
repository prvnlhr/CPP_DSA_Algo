#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main()
{
    // Complete the code.
    int a;
    long b;
    char c;
    float f;
    double d;

    cin >> a >> b >> c >> f >> d;
    // cin >> d;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << fixed;
    cout << setprecision(3) << f << endl;
    cout << setprecision(9) << d << endl;

    return 0;
}