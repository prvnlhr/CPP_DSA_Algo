#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    while (n--)
    {

        string s;
        cin >> s;
        int len = s.size();
        string res;
        if (len > 10)
        {
            res = s[0] + to_string(len - 2) + s[len - 1];
        }
        else
        {
            res = s;
        }
        cout << res << endl;
    }
}