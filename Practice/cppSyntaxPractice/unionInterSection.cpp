#include <iostream>

#include <vector>

using namespace std;

void unionIntersection(vector<int> &arr1, vector<int> &arr2)
{

    vector<int> interArr;
    vector<int> unionArr;

    for (auto ele : arr1)
    {
        cout << ele << " ";
    }
    cout << endl;

    for (auto el : arr2)
    {
        cout << el << " ";
    }
    cout << endl;

    int len1 = arr1.size();
    int len2 = arr2.size();

    int i = 0;
    int j = 0;

    cout << arr1.size() << " " << arr2.size() << endl;

    while (i < len1 && j < len2)
    {
        cout << "i " << i << " j " << j << endl;
        cout << arr1[i] << " " << arr2[j] << endl;

        if (arr1[i] < arr2[j])
        {
            unionArr.push_back(arr1[i]);
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            unionArr.push_back(arr2[j]);
            j++;
        }
        else
        {
            interArr.push_back(arr2[j]);
            unionArr.push_back(arr2[j]);
            i++;
            j++;
        }
    }

    cout << i << " " << j << endl;

    while (i < len1)
    {
        unionArr.push_back(arr1[i]);
        i++;
    }

    while (j < len2)
    {

        unionArr.push_back(arr2[j]);
        j++;
    }

    for (auto ele : unionArr)
    {
        cout << ele << " ";
    }

    cout << endl;

    for (auto el : interArr)
    {
        cout << el << " ";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> arr1;
    vector<int> arr2;

    int n, m;

    cin >> m >> n;
    int a, b;

    while (m--)
    {
        cin >> a;
        arr1.push_back(a);
    }

    while (n--)
    {
        cin >> b;
        arr2.push_back(b);
    }
    unionIntersection(arr1, arr2);
}
