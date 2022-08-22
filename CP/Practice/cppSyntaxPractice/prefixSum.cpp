
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> prefixSum(vector<int> &arr)
{

    vector<int> res(arr.size());

    res[0] = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {

        res[i] = res[i - 1] + arr[i];
    }

    return res;
}

int main()
{

    vector<int> arr{10, 20, 10, 5, 15};
    // vector<int> arr{10, 4, 16, 20};

    auto ans = prefixSum(arr);

    for (auto ele : ans)
    {
        cout << ele << " ";
    }
}
