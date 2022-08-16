#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<string> arr;
    for (int i = 0; i < n; i++)
    {

        string s;
        cin >> s;
        arr.push_back(s);
    }
    int ANS = 0;
    for (auto x : arr)
    {
        if (x == "X++" || x == "++X")
        {
            ANS++;
        }
        else if (x == "--X" || x == "X--")
        {

            ANS--;
        }
    }

    cout << ANS << endl;
}
