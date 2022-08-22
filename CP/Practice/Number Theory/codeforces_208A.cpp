#include <iostream>
#define ll long long
using namespace std;

int main()
{

    string s;
    cin >> s;
    string output = "";

    int i = 0;
    while (i < s.length())
    {
        string temp = s.substr(i, 3);

        if (temp == "WUB")
        {
            if (output.length() >= 1)
            {

                output = output + " ";
            }

            i = i + 3;
        }
        else
        {
            output = output + s[i];
            i++;
        }
    }
    cout << output << endl;
}
