#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        double N, X, Y, A, B;
        cin >> N >> X >> Y >> A >> B;

        double ltrPertrolReq = N / A;
        double ltrDieselReq = N / B;
        double costPetrol = ltrPertrolReq * X;
        double costDiesel = ltrDieselReq * Y;
        cout << ltrPertrolReq << " " << ltrDieselReq << endl;
        cout << costPetrol << " " << costDiesel << endl;
        if (costPetrol > costDiesel)
        {
            cout << "DIESEL" << endl;
        }
        else if (costPetrol < costDiesel)
        {
            cout << "PETROL" << endl;
        }
        else
        {
            cout << "ANY" << endl;
        }
    }
}
