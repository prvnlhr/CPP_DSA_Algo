#include <iostream>
#define ll long long
using namespace std;

int main()
{

    string s;
    cin >> s;
    bool flag = false;
    int i = 0;

    while (i < s.length())
    {
        int cnt = 1;

        for (int j = i + 1; j < s.length(); j++)
        {

            if (s[j] != s[i])
            {
                i = j - 1;
                break;
            }

            else
            {
                cnt++;
                if (cnt == 7)
                {
                    flag = true;
                    break;
                }
            }
        }

        if (flag)
        {
            break;
        }
        i++;
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
