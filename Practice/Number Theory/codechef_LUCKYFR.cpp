#include <iostream>
#define ll long long
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '4')
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}
