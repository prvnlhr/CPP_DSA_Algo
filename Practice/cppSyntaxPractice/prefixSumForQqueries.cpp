#include <iostream>
#include <vector>

using namespace std;

int prefixSumFromLtoR(vector<int> &arr, int l, int r)
{

    int SUM = 0;

    for (int i = l - 1; i < r; i++)
    {
        SUM = SUM + arr[i];
    }

    return SUM;
}
int main()
{

    vector<int> arr{3, 6, 2, 8, 9, 2};

    int Q, l, r;

    cout << "Enter Q: ";

    cin >> Q;

    while (Q)
    {
        cout << "Enter l and r: ";
        cin >> l >> r;
        int ans = prefixSumFromLtoR(arr, l, r);
        cout << "SUM of elements from l to r: ";
        cout << ans << endl;
        cout << endl;
        Q--;
    }
}