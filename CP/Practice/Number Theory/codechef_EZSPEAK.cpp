#include <iostream>
#include <set>
#define ll long long
using namespace std;

set<char> st{'a', 'e', 'i', 'o', 'u'};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;

        for (int i = 0; i < s.length(); i++)
        {

            if (st.find(s[i]) != st.end())
            {
                cnt = 0;
            }
            else
            {
                cnt++;
            }

            if (cnt >= 4)
            {
                break;
            }
        }
        if (cnt == 4)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}
