#include <iostream>
#include <cctype>
// #include <cstring>
#define ll long long
using namespace std;

int main()
{

    string s1, s2;
    cin >> s1;

    cin >> s2;

    /*
    * Convert char to lower or uppercase.
    > tolower() or toupper function requires character of string
     */
    for (int i = 0; i < s1.length(); i++)
    {

        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
    }

    // > 1.Method ->  compare(), compares strings lexicographically,

    //? if s1 greater value  > 0
    // ? if s2 greater value  < 0
    // ? if equal value == 0

    if (s1.compare(s2) == 0)
    {
        cout << 0 << endl;
    }
    else if (s1.compare(s2) < 0)
    {
        cout << -1 << endl;
    }
    else if (s1.compare(s2) > 0)
    {
        cout << 1 << endl;
    }

    //> 2.Method -> comparing using == and != operator

    // if (s1 == s2)
    // {
    //     cout << 0 << endl;
    // }
    // else if (s1 > s2)
    // {
    //     cout << 1 << endl;
    // }
    // else if (s1 < s2)
    // {
    //     cout << -1 << endl;
    // }
}
