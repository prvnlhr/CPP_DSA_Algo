#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {

        int skips = numRows - 2;
        cout << skips << endl;
        int ln = s.length();
        int cnt = 0;
        vector<char> temp;
        vector<vector<char>> arr;
        vector<char> skipChar;
        for (int i = 0; i < ln; i++)
        {
            if (cnt == numRows)
            {

                arr.push_back(temp);
                temp.clear();
                cnt = 0;

                int skipCnt = 0;
                int j = i;

                while (skipCnt < skips)
                {

                    skipChar.push_back(s[j]);
                    j++;
                    skipCnt++;
                }

                i += skips;
            }
            cnt++;
            temp.push_back(s[i]);
        }

        arr.push_back(temp);

        string ans = "";
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr.size(); j++)
            {
                ans += arr[j][i];
            }
        }
        cout << ans << endl;

        for (auto x : arr)
        {
            for (auto y : x)
            {
                cout << y << " ";
            }
            cout << endl;
        }
        cout << endl;

        for (auto x : skipChar)
        {
            cout << x << " ";
        }

        int cols = arr.size() + skipChar.size();
        vector<vector<char>> vec(numRows, vector<char>(cols, 0));

        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < numRows; j++)
            {

                vec[][]
            }
        }

        return " ";
    }
};

int main()
{

    Solution *obj = new Solution();
    string s;
    cin >> s;
    int n;
    cin >> n;
    cout << obj->convert(s, n);
}