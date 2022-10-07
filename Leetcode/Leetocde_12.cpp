#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {

        // 1 -> 99
        // 100 -> 999
        /// 1000 -> 3999
        string res = "";
        vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> str{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        for (int i = 0; i < val.size(); i++)
        {

            while (num >= val[i])

            {
                num -= val[i];
                cout << num << endl;
                res += str[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution *obj = new Solution();
    cout << obj->intToRoman(58) << endl;
}
