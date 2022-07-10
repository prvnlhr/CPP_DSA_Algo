#include <iostream>
#include <array>         // including array from STL
#include <vector>        // including vector from STL
#include <set>           // including set from STL
#include <unordered_set> //including unordered_set from STL
using namespace std;

int main()
{

    // ARRAY________________________________________________________

    // Declaration

    // <array<dataType, size> name;
    array<int, 3> arr; // {?, ?, ?}

    // OR, can also initialize as
    array<int, 5> arr = {1, 2, 3}; // {1, 5, 6, 0, 0} -> size 5, three are given, by default rest would be 0

    array<int, 5> arr = {1}; // {1, 0, 0, 0, 0}

    // OR can use fill() to initialize to a given value
    array<int, 5> arr;
    arr.fill(10); //  ->  {10, 10, 10, 10, 10}

    arr.at(2); // take index a parameter and given value at that index

    // Printing array

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i];
    }

    // OR using ITERATOR
    //  begin() , end() , rbegin() , rend()

    // begin() --> points first or start ele of array
    // rbegin() --> points last ele of array, (reverse array start)

    // end() --> points after last:: IMP: not last  ex, {1, 2, 3, 4, 5, 6} end() will point after LAST 6
    //  rend() -> points before first, or (reverse array after last)

    // traversing using iterators
    array<int, 5> arr = {1, 3, 4, 5, 6};
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        cout << *it << " "; // 1  3  4  5  6   NOTE: it will give pointer, not value, for value do -> *it
    }

    for (auto it = arr.end() - 1; it >= arr.begin(); it--)
    {
        cout << *it << " "; // 1  3  4  5  6   NOTE: it will give pointer, not value, for value do -> *it
    }

    // OR using forEach Loop

    for (auto it : arr) // NOTE : auto is used to, get automatic dataType in runtime. compiler will decide dataType of it automatic
    {
        cout << it << " "; // NOTE : here we are not using *it.
    }

    // IN case of strings

    string s = "hellworld";
    for (auto c : s)
    {
        cout << c << " ";
    }

    for (char c : s)
    {
        cout << c << " ";
    }

    // Size of array,
    cout << arr.size(); // give no of elements

    // front
    cout << arr.front(); // or arr.at(0);

    // back
    cout << arr.back(); // or arr.at(arr.size()-1);

    // using for loop  and size() to print arr ele
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    // IMP CONCEPT OF ARRAY

    // Inside main function,
    // max size of array can be 10^6 -> int, double, char
    int arr[1000000];

    // max size of array can be 10^7-> bool
    bool arr[10000000];

    // globally ,
    // max size of array can be 10^7 -> int, double, char
    int arr[10000000];

    // max size of array can be 10^8-> bool
    bool arr[100000000];

    //_____________________________________________________________________________________________________________

    // VECTOR

    vector<int> vec; // -> {}

    cout << vec.size(); // -->  0

    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(6);
    cout << vec.size(); // -->  5

    vec.pop_back();     // -> {1, 3, 5, 4}  , 6 popped
    cout << vec.size(); // -->  4

    vec.clear(); // clear all ele at once {}

    // copying vec to another vec

    vector<int> vec1 = {1, 2, 3, 4, 5}; // can also be done as " vector <int> vec1(1, 2, 3, 4, 5); "
    vector<int> vec2(vec1);             // copying vec1 to vec2

    // OR copy only specified ele

    vector<int> vec3(vec1.begin(), vec1.begin() + 2); // vec3 --> {1, 2, 3}
    // OR
    vector<int> vec3(vec1.begin(), vec1.end() - 2); // vec3 --> {1, 2, 3}

    // 2D vector

    vector<int> oneD;

    vector<vector<int>> twoD;

    vector<int> temp = {1, 2, 3};

    twoD[0] = temp;

    // twoD -> {{1, 2, 3}}

    // Printing
    for (auto vctr : twoD)
    {
        for (auto it : vctr)
        {
            cout << it << " ";
        }
    }

    // Or

    for (int i = 0; i < twoD.size(); i++)
    {
        for (int j = 0; j < twoD[i].size(); j++)
        {

            cout << twoD[i][j];
        }
    }

    // defining 10 x 20

    // vector < dataType > name(size,   initialize)

    // dataType -> vector<int> -> of cols
    // name -> vec
    // size(10)
    // initialize by -> vector <int>(20,0) --> cols

    vector<vector<int>> vec(10, vector<int>(20, 0));

    // _______________________________________________________________

    set<int> st; // Only Holds single values if duplicated are given
                 // gives elements in increasing oreder

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }

    // if n == 3 , three  values are inserted
    // st -> {1,2,5}

    // erase functionality
    st.erase(st.begin()); // st.erase(iterator) // st -> {2,5}

    // OR st.erase(startIterator,endIterator)
    // OR st.erase(index)

    set<int> st = {1, 2, 3, 8};

    // Time Complexity log N
    auto itr = st.find(3); // itr will be iterator to 3

    // if ele is not present
    auto itr = st.find(9); // itr -> will given iterator to end()

    // Size of set
    cout << st.size();

    for (auto it = st.begin(); it != st.end(); it++)
    {
        cout << *it << " ";
    }
    for (auto it : st)
    {
        cout << it << endl;
    }

    st.erase(st.begin(), st.end()); // deletes entire set

    unordered_set<int> st; // average time complexity O(1)
    // worst case is linear in nature, set size

    st.insert(2);
    st.insert(3);
    st.insert(1);

    //_____________________________________________________

    multiset<int> ms;

    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3);

    // st ->{1, 1, 2, 2, 3}

    ms.erase(2); // erase all instances of 2

    auto itr = ms.find(2); // retrurn iterator to first occurrence
}
