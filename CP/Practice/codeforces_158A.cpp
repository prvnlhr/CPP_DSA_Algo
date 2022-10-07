#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;

    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    int ANS = 0;
    for (int i = 0; i < k - 1; i++)
    {
        if (arr[i] != 0)
        {
            ANS++;
        }
    }

    for (int j = k; j < n; j++)
    {

        if (arr[k - 1] != 0 && arr[j] == arr[k - 1])

        {
            ANS++;
        }
    }

    if (arr[k - 1] != 0)
    {

        cout << ANS + 1 << endl;
    }
    else
    {
        cout << ANS << endl;
    }
}
