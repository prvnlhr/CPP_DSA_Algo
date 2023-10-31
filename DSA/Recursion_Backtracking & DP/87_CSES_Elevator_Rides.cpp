#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> weights(n);

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end()); // Sort the weights in non-decreasing order

    int rides_needed = 0;
    int current_ride_weight = 0;
    int current_ride_index = 0;

    for (int i = 0; i < n; i++)
    {
        if (current_ride_weight + weights[i] <= x)
        {
            current_ride_weight += weights[i];
            current_ride_index++;
        }
        else
        {
            rides_needed++;
            current_ride_weight = weights[i];
            current_ride_index = 1;
        }
    }

    if (current_ride_index > 0)
    {
        rides_needed++;
    }

    cout << rides_needed << endl;

    return 0;
}
