#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
#include <climits>
#define ll long long
using namespace std;

int main()
{

    //> ACCUMULATE -> to find sum of all elements of vector #include <numeric>

    cout << ceil(2.8) << endl;                       // -> 3,  Ceil rounds off the given value to the closest integer which is more than the given value
    cout << floor(2.8) << endl;                      // -> 2,   Floor rounds off the given value to the closest integer which is less than the given value.
    cout << round(2.8) << " " << round(2.3) << endl; // -> 3 , 2 Rounds gave numbers to the closest integer
    cout << trunc(2.835) << endl;

    cout << INT_MIN << endl;
    cout << INT_MAX << endl; // -> 2 Trunc rounds remove digits after the decimal point
}
