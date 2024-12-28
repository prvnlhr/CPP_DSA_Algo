#include <iostream>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {

        int lenOfLastWord = 0;
        int lenOfString = s.size();

        //|> skipping spaces
        int i = lenOfString - 1;
        while (i >= 0 && !isalpha(s[i]))
        {
            i--;
        }

        //|> counting alphabets
        while (i >= 0 && isalpha(s[i]))
        {
            lenOfLastWord++;
            i--;
        }

        return lenOfLastWord;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    int ans = sol.lengthOfLastWord(s);

    cout << ans << " ";
}