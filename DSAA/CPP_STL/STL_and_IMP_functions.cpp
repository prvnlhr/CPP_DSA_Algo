#include <iostream>
#include <array>         // including array from STL
#include <vector>        // including vector from STL
#include <set>           // including set from STL
#include <unordered_set> //including unordered_set from STL
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <climits>
using namespace std;

int main()
{

    //> ARRAY________________________________________________________

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

    //> ITERATORS__________________________________________________
    // used to point address of elements in sequence , ex vector, queue or stack etc

    vector<int> arrs{1, 2, 3, 4, 5, 6, 7, 8};

    vector<int>::iterator itr;

    for (auto itr = arrs.begin(); itr != arrs.end(); itr++)
    {
        cout << *itr << "";
    }

    //> VECTOR_____________________________________________________

    //* Initialization ::
    // >> 1. empty vector
    vector<int> vec; // -> {}

    // >> 2. with size and default elements
    vector<int> vec(4, 0); // -> { 0, 0, 0, 0}
    vector<int> vec(4, 5); // -> { 5, 5, 5, 5}

    cout << vec.size(); // * gievs size of vector

    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(6);

    cout << vec.size(); // -->  5

    // ? => {1, 3, 5, 4, 6}

    vec.pop_back(); // -> {1, 3, 5, 4}  , 6 popped

    cout << vec.size(); // -->  4

    vec.clear(); // clear all ele at once {}

    // copying vec to another vec

    vector<int> vec1 = {1, 2, 3, 4, 5}; // can also be done as " vector <int> vec1(1, 2, 3, 4, 5); "
    vector<int> vec2(vec1);             // copying vec1 to vec2

    // OR copy only specified ele

    vector<int> vec3(vec1.begin(), vec1.begin() + 2); // vec3 --> {1, 2, 3}
    // OR
    vector<int> vec3(vec1.begin(), vec1.end() - 2); // vec3 --> {1, 2, 3}

    // > 2D vector_____________________________________________________

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

    //> SET _______________________________________________________________

    set<int> st; // * only holds single values if duplicates are given
                 // * gives elements in increasing oreder

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

    //> erase functionality
    st.erase(st.begin()); // st.erase(iterator) // * st -> {2,5}

    //* OR st.erase(startIterator,endIterator)
    //* OR st.erase(index)

    set<int> st = {1, 2, 3, 8};

    //> Time Complexity log N
    auto itr = st.find(3); // itr will be iterator to 3

    // if ele is not present
    auto itr = st.find(9); //* itr -> will give iterator to end()

    // > Size of set
    cout << st.size();

    //> Printing set elements_____
    for (auto it = st.begin(); it != st.end(); it++)
    {
        cout << *it << " ";
    }

    for (auto it : st)
    {
        cout << it << endl;
    }

    st.erase(st.begin(), st.end()); // deletes entire set

    //> UNORDERED SET_____________________________________________________

    unordered_set<int> st; //* average time complexity O(1)
    // worst case is linear in nature, set size

    st.insert(2);
    st.insert(3);
    st.insert(1);

    // * if TLE switch to set
    // * worst case time complextiy is O(size_of_set)

    // > MULTISET_____________________________________________________

    multiset<int> ms;

    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3);

    // st ->{1, 1, 2, 2, 3}

    ms.erase(2); // erase all instances of 2

    auto itr = ms.find(2); // returns iterator to first occurrence

    ms.count(2); //-> finds how many time 2 occur

    //> MAP_____________________________________________________

    //* Initialzing map

    map<int, int> mpp1;
    // OR
    map<string, int> mpp;
    // OR

    // key : value

    //* only stores unique keys
    mpp["steve"] = 1;
    mpp["stark"] = 19;
    mpp["bruce"] = 5;
    // OR
    mpp.emplace("thor", 55);

    mpp.erase("stark"); // * mpp.erase(key); -> removes key from map.

    mpp.clear(); // * clears the whole map

    auto it1 = mpp.find("steve");
    auto it2 = mpp.find("bruce");

    mpp.erase(it1, it2);

    auto it = mpp.find("stark"); // * points where "stark' lies in map

    //* check if map  is empty of not,
    mpp.empty();

    mpp.count("stark"); //  always gives 1, as map stores unique values

    pair<int, int> pr;

    cout << pr.first;
    cout << pr.second;

    //> printing map______________________

    for (auto ele : mpp)
    {
        cout << ele.first << ele.second << " ";
    }
    // OR

    for (auto it = mpp.begin(); it != mpp.end(); it++)
    {
        cout << it->first << " " << it->second;
    }

    //> C++17 printing
    map<int, vector<int>> mpp{{1, {12, 15, 26}}, {13, {14, 15, 18, 19}}};

    for (auto [key, value] : mpp)
    {
        cout << key << " " << value << endl;
    }

    //> UNORDER MAP________________________________________________________________________________
    unordered_map<int, int> umpp;
    // *O(1) in almost all cases
    // *O(N) in worst case

    //> PAIR CLASS_________________________________________________________________

    pair<int, int> pr;
    pr.first = 1;
    pr.second = 2;

    // OR
    pair<int, int> prr = {2, 5};

    pair<pair<int, int>, int> pr1 = {{1, 2}, 5};

    //> Uses
    vector<pair<int, int>, int> vec1;

    set<pair<string, int>> st1;

    map<pair<string, int>, int> mpp2;

    //> STACK___________________________________________________________________

    stack<int> stk;

    stk.push(5);
    stk.push(6);
    stk.push(7);
    stk.push(8);
    stk.push(9);

    cout << stk.top(); // * prints 5

    stk.pop(); //* deletes last entered value -> 9

    cout << stk.empty();

    stk.size(); // * size of stack

    //> QUEUE________________________________________________________________________________

    queue<int> q;

    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.front();

    q.pop();

    q.empty();
    q.size();

    //> PRIORITY QUEUE________________________________________________________________________________

    priority_queue<int> pq; // * default max priority queue
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);
    pq.push(6);

    //> for min pq either use - sign , OR

    priority_queue<int, vector<int>, greater<int>> pq;

    cout << pq.top(); //* 6
    pq.pop();

    //> for pair pq

    //* MAX PQ:
    priority_queue<pair<int, int>> pqp1;
    pqp1.push({1, 2});
    pqp1.push({9, 4});
    pqp1.push({2, 6});
    pqp1.push({8, 5});
    pqp1.push({3, 4});
    cout << pqp1.top().first << endl; //* -> 9

    //* MIN PQ

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqp2;
    pqp2.push({1, 2});
    pqp2.push({9, 4});
    pqp2.push({2, 6});
    pqp2.push({8, 5});
    pqp2.push({3, 4});
    cout << pqp2.top().first << endl; //* -> 1

    //>  DEQUE________________________________________________________________________________

    deque<int> dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);

    // print dq elements using iterator
    deque<int>::iterator it;

    for (auto it = dq.begin(); it != dq.end(); it++)
    {
        cout << *it << " "; // 1 2 3 4
    }

    dq.push_front(9); // 9 1 2 3 4

    dq.pop_back();  // 9 1 2 3
    dq.pop_front(); // 1 2 3

    //> __ALGORITHMS______________________________________________________________________

    //* 1. SWAP
    int x = 10;
    int y = 20;

    cout << x << y; // 10 20

    swap(x, y);

    cout << x << y; // 20 10

    //> REVERSE
    vector<int> arr{1, 2, 3, 4, 5, 6};

    for (auto x : arr)
    {
        cout << x << " "; // 1 2 3 4 5 6
    }
    cout << endl;

    reverse(arr.begin(), arr.end()); // 6 5 4 3 2 1

    reverse(arr.begin() + 2, arr.end()); // 1 2 3 4 5 6 -> 1 2 6 5 4 3

    //> SORTING

    vector<int> arr1{2, 71, 12, 45, 26, 80, 53, 33};

    sort(arr1.begin(), arr1.end());
    for (auto x : arr1)
    {
        cout << x << " "; // 2 12 26 33 45 53 71 80
    }
    //                                     begin   begin + 4
    //                                       |       |
    sort(arr1.begin(), arr1.begin() + 4); // 2 71 12 45
    for (auto x : arr1)
    {
        cout << x << " "; // 2 12 45 71 26 80 53 33
    }
    //>--------------------------------------------------------------------------------------------------------

    //> SORTING USING COMPARATOR__

    /*

 >>   bool comapre(pair<int, int> & p1, pair<int, int> & p2)
 >>   {
 >>
 >>       if (p1.first != p2.first)
 >>       {
 >>           return p1.first > p2.first;
 >>       }
 >>       else
 >>       {
 >>           return p1.second < p2.second;
 >>       }
 >>   }

    */

    vector<pair<int, int>> table;
    table = {{4, 10}, {4, 3}, {4, 10}, {3, 20}, {2, 1}, {2, 1}, {1, 10}};

    /*

    >> Lets say we want to sort table vector on the basis of first element in decreasing order
    >> but if the first elements are equal then we want to consider second element
    >>and sort according to the second element but in increasing order.

    >  O/P: [{4, 3}, {4, 10}, {4, 10}, {3, 20}, {2, 1}, {2, 1}, {1, 10}];
    >  As we can se table is sorted on basis of first element, whith biggest
    > value placed at first but if first element is eqaul then,  according to second
    > element value are sorted in inceasing order.
     */
    //* sort(table.begin(), table.end(), comapre);

    //> SORTING ONE LINE
    vector<int> v = {3, 1, 2, 1, 8};
    sort(begin(v), end(v), [](int a, int b)
         { return a > b; });
    for (auto i : v)
    {

        cout << i << ' ';
    }
    //>> Output:8 3 2 1 1
    //>--------------------------------------------------------------------------------------------------------
    //> LOWER BOUND & UPPER BOUND     #include <algorithm>

    // vector<int> ar{10, 10, 20, 20, 23, 23, 30, 55};
    vector<int> ar{10, 20, 30, 30, 30, 40, 50};

    auto itr1 = lower_bound(ar.begin(), ar.end(), 23);
    auto itr2 = upper_bound(ar.begin(), ar.end(), 40);
    cout << itr1 - ar.begin() << " " << ar[itr1 - ar.begin() - 1] << endl;
    cout << itr2 - ar.begin() << " " << ar[itr2 - ar.begin() - 1] << endl;

    //> ACCUMULATE -> to find sum of all elements of vector #include <numeric>
    vector<int> ary{1, 2, 3, 4, 5};
    int SUM = 0;
    SUM = accumulate(ary.begin(), ary.end(), SUM);
    cout << SUM << endl;

    // OR
    cout << accumulate(ary.begin(), ary.end(), 0) << endl;

    //> CMATH -> ceil, floor, round, trunc
    cout << ceil(2.8) << endl;                       // -> 3,  Ceil rounds off the given value to the closest integer which is more than the given value
    cout << floor(2.8) << endl;                      // -> 2,   Floor rounds off the given value to the closest integer which is less than the given value.
    cout << round(2.8) << " " << round(2.3) << endl; // -> 3 , 2 Rounds gave numbers to the closest integer
    cout << trunc(2.835) << endl;                    // -> 2 Trunc rounds remove digits after the decimal point

    //> CLIMITS
    cout << INT_MIN << endl;
    cout << INT_MAX << endl;

    //> find index of first occurance,
    string s = "101010";
    int c = s.find('0'); //-> 1, else -1 if not found

    string s1 = "saaa";
    string s2 = "terer";
    s1.compare(s2); //> compares lexicographically
}