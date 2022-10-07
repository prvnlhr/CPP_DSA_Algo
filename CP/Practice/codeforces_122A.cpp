#include <iostream>
#include <set>
#define ll long long
using namespace std;

set<int> st{4, 7, 44, 47, 74, 77, 444, 447, 477, 474, 477, 747, 774, 777};

int main()
{

    int n;
    cin >> n;
    string ANS = "NO";

    for (auto it = st.begin(); it != st.end(); it++)
    {

        if (n % *it == 0)
        {
            ANS = "YES";
            break;
        }
    }
    cout << ANS << endl;

    //>OR
    if (n % 4 == 0 || n % 7 == 0 || n % 44 == 0 || n % 47 == 0 || n % 74 == 0 || n % 77 == 0 || n % 444 == 0 || n % 447 == 0 || n % 477 == 0 || n % 474 == 0 || n % 477 == 0 || n % 747 == 0 || n % 774 == 0 || n % 777 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    // cout << ANS << endl;
}