#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// comparator
bool compareOnBasisOfSecondElement(vector<int> first_ele, vector<int> second_ele)
{
    if (first_ele[1] < second_ele[1])
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    //
    //                   first_ele  second_ele
    //                         |       |
    vector<vector<int>> vec{{6, 2}, {4, 1}, {1, 0}, {9, 2}};

    sort(vec.begin(), vec.end(), compareOnBasisOfSecondElement);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << "[" << vec[i][0] << "," << vec[i][1] << "]"
             << ", ";
    }
}