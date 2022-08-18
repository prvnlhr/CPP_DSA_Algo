#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;
        vector<int> arr(n);
        int MAX = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            MAX = max(arr[i], MAX);
        }
        int domIndex = -1;

        for (int i = 0; i < arr.size(); i++)
        {

            if (i > 0 && arr[i - 1] < arr[i])
            {
                domIndex = i;
                if (arr[i] == MAX)
                {
                    break;
                }
            }
            else if (i + 1 < n && arr[i] > arr[i + 1])
            {
                domIndex = i;
                if (arr[i] == MAX)
                {
                    break;
                }
            }
        }
        if (domIndex != -1)
        {

            cout << domIndex + 1 << endl;
        }
        else
        {
            cout << domIndex << endl;
        }
    }
}
