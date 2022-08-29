#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution
{
public:
    string sorted_num_string(int n)
    {

        string numStr = to_string(n);
        sort(numStr.begin(), numStr.end());
        return numStr;
    }
    bool reorderedPowerOf2(int n)
    {
        if (n == 1)
        {
            return true;
        }
        string numStr = sorted_num_string(n);

        for (int i = 1; i <= 29; i++)
        {
            int num = pow(2, i);
            string num1_str = sorted_num_string(num);

            if (num1_str == numStr)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution *obj = new Solution();
    int n;
    cin >> n;
    bool ans = obj->reorderedPowerOf2(n);
    cout << ans << endl;
}

// class Solution
// {
// public:
//     bool reorderedPowerOf2(int N)
//     {
//         string N_str = sorted_num(N);
//         for (int i = 0; i < 32; i++)
//             if (N_str == sorted_num(1 << i))
//                 return true;
//         return false;
//     }

//     string sorted_num(int n)
//     {
//         string res = to_string(n);
//         sort(res.begin(), res.end());
//         return res;
//     }
// };