#include <iostream>
#define ll long long
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string s, r;
        cin >> n;
        cin >> s;
        cin >> r;
        int cnt1 = 0;

        /*
        * Given : Intially bulb is ON.
        * couting the set bits in initial state of btns,
        * to decide if bulb is ON or OFF
         >> if count is even bulb is ON else OFF

        * Now couting set bits in final state of btns,
         >> if initial from initial state of btn, we found that bulb is ON,
         >> then from final state if cnt2 is even, bulb is ON else OFF

         >> but ,from initial state ,bulb is OFF then,
         >> if cnt 2 is even bulb is OFF else ON.

        ? TIME COMPLEXITY : O(N)

         */

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                cnt1++;
            }
        }

        string ans;
        if (cnt1 == 0 or cnt1 % 2 == 0)
        {
            ans = "ON";
        }
        else
        {
            ans = "OFF";
        }
        int cnt2 = 0;
        for (int i = 0; i < r.length(); i++)
        {
            if (r[i] == '1')
            {
                cnt2++;
            }
        }

        if (ans == "ON" && cnt2 % 2 == 0)
        {
            ans = "ON";
        }
        else if (ans == "ON" && cnt2 % 2 != 0)
        {
            ans = "OFF";
        }
        else if (ans == "OFF" && cnt2 % 2 == 0)
        {
            ans == "OFF";
        }
        else if (ans == "OFF" && cnt2 % 2 != 0)
        {
            ans = "ON";
        }

        if (ans == "OFF")
        {

            cout << 0 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
}

/*
 * This solution can be simplied further.
 * if we look carefully then we see that the difference in switches from initial and final state
 * decides whether a bulb if ON or OFF.
 *
 * if we count all the setbit in initial and final state, and if cnt is even -> ON else OFF


 >> for(int i= 0 l i< s.length(); i++){
 >>    if(s[i] != r[i]){
 >>       cnt ++
 >>     }
 >> }
 >> if cnt even -> ON else OFF

 */
