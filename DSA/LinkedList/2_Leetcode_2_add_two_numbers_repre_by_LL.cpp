
/*

 ▄▀█ █░█ █▀▄▀█ █▄░█ █▀█ █▀▄▀█
 █▀█ █▄█ █░▀░█ █░▀█ █▄█ █░▀░█

*/

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

//__________________________________________________________________________________________________________________________________________________________________________________________________

#define MOD 1000000007
#define MOD1 998244353
#define PI 3.141592653589793238462

typedef long long ll;

//>---DEBUG_TEMPLATE_START---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    return os << '{' << p.first << ", " << p.second << '}';
}

template <class T, class = decay_t<decltype(*begin(declval<T>()))>,
          class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &os, const T &c)
{
    os << '[';
    for (auto it = c.begin(); it != c.end(); ++it)
        os << &", "[2 * (it == c.begin())] << *it;
    return os << ']';
}
//__support up to 5 args
#define _NTH_ARG(_1, _2, _3, _4, _5, _6, N, ...) N
#define _FE_0(_CALL, ...)
#define _FE_1(_CALL, x) _CALL(x)
#define _FE_2(_CALL, x, ...) _CALL(x) _FE_1(_CALL, __VA_ARGS__)
#define _FE_3(_CALL, x, ...) _CALL(x) _FE_2(_CALL, __VA_ARGS__)
#define _FE_4(_CALL, x, ...) _CALL(x) _FE_3(_CALL, __VA_ARGS__)
#define _FE_5(_CALL, x, ...) _CALL(x) _FE_4(_CALL, __VA_ARGS__)
#define FOR_EACH_MACRO(MACRO, ...)                                           \
    _NTH_ARG(dummy, ##__VA_ARGS__, _FE_5, _FE_4, _FE_3, _FE_2, _FE_1, _FE_0) \
    (MACRO, ##__VA_ARGS__)

//__Change output format here
#define out(x) #x " = " << x << "; "

#ifndef ONLINE_JUDGE
#define debug(...) \
    cerr << "Line " << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
#else
#define debug(...)
#endif

//>---DEBUG_TEMPLATE_END-----------------------------------------------------------------------------------------------------------------------------------------------------------

// #define FOR(i, start, end) for (int i = start; i < end; i++)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define RFOR(i, start, end) for (int i = end; i >= start; i--)
#define FOREACH(x, b) for (auto x : b)

#define cout1(x) cout << x << endl;
#define cout2(x, y) cout << x << " " << y << endl;
#define cout3(x, y, z) cout << x << " " << y << " " << z << endl;

#define SUMOFN(arr) accumulate(arr.begin(), arr.end(), 0LL);
#define SORTASC(arr) sort(arr.begin(), arr.end());
#define SORTDSC(arr) sort(arr.begin(), arr.end(), greater<int>());
#define REV(arr) reverse(arr.begin(), arr.end());

#define strLow(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define strUp(s) transform(s.begin(), s.end(), s.begin(), ::toupper);

#define lb(arr, ele) lower_bound(arr.begin(), arr.end(), ele);
#define ub(arr, ele) upper_bound(arr.begin(), arr.end(), ele);

typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> stint;
typedef map<int, int> mpint;
typedef pair<int, int> pi;
typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;
//_____________________________
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
//_____________________________
ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
//__factorial______________________________________________
vector<ll> fact;
void factOfN(ll n)
{
    ll prod = 1;
    fact.resize(n + 1);
    for (int f = 1; f <= n; f++)
    {

        fact[f] = prod * f;
        prod = prod * f;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------

//>----------------------------ＳＯＬＶＥ-----------------------------------------------------------------------------------------------------------------------------------------------
class ListNode
{

public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

ListNode *buildLL(vector<int> &input)
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    for (int i = 0; i < input.size(); i++)
    {
        int ele = input[i];
        if (ele == -1)
        {
            break;
        }

        ListNode *newNode = new ListNode(ele);

        if (head == nullptr)
        {

            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}
void printLL(ListNode *head)
{
    ListNode *curr = head;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode *reverseLL(ListNode *head)
{

    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr)
    {

        ListNode *nextt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextt;
    }

    return prev;
}

ListNode *addTwoNums(ListNode *head1, ListNode *head2)
{
    ListNode *finalist = nullptr;
    ListNode *tail = finalist;

    ListNode *curr1 = head1;
    ListNode *curr2 = head2;
    int carry = 0;
    while (curr1 && curr2)
    {

        int a = curr1->val;
        int b = curr2->val;
        int sum = a + b + carry;
        int val = 0;
        if (sum >= 10)
        {
            val = (sum % 10);
        }
        else
        {
            val = sum;
        }
        // debug(a, b, sum, val, carry);
        ListNode *newNode = new ListNode(val);
        carry = sum / 10;

        if (!finalist)
        {
            finalist = newNode;
            tail = finalist;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    debug(carry);
    if (curr1)
    {
        while (curr1)
        {
            int num = curr1->val;
            int sum = num + carry;
            int data = 0;
            if (sum >= 10)
            {
                data = (sum % 10);
            }
            else
            {
                data = sum;
            }
            ListNode *newNode = new ListNode(data);
            tail->next = newNode;
            tail = newNode;
            carry = sum / 10;

            curr1 = curr1->next;
        }
    }
    if (curr2)
    {
        while (curr2)
        {
            int num = curr2->val;
            int sum = num + carry;
            int data = 0;
            if (sum >= 10)
            {
                data = (sum % 10);
            }
            else
            {
                data = sum;
            }
            ListNode *newNode = new ListNode(data);
            tail->next = newNode;
            tail = newNode;
            carry = sum / 10;

            curr2 = curr2->next;
        }
    }

    if (carry != 0)
    {
        ListNode *newNode = new ListNode(carry);
        tail->next = newNode;
    }
    return finalist;
}
void solve()
{
    // vector<int> inputList1{2, 4, 3, -1};
    // vector<int> inputList2{5, 6, 4, -1};
    // vector<int> inputList1{9, 9, 9, -1};
    // vector<int> inputList2{9, 9, 9, -1};
    vector<int> inputList1{5, 6, 3, -1};
    vector<int> inputList2{8, 4, 2, -1};
    // vector<int> inputList1{9, 9, 9, 9, 9, 9, 9, -1};
    // vector<int> inputList2{9, 9, 9, 9, -1};

    auto head1 = buildLL(inputList1);
    auto head2 = buildLL(inputList2);
    auto newHead = addTwoNums(head1, head2);
    printLL(newHead);
}

//>-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("../../Error.txt", "w", stderr);
    freopen("../../output.txt", "w", stdout);
    freopen("../../input.txt", "r", stdin);
#endif
    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    auto now = system_clock::to_time_t(system_clock::now());
    stringstream timeStream;

    timeStream << put_time(localtime(&now), "%d %b %Y %H:%M:%S");
    string formatted_time = timeStream.str();

#ifndef ONLINE_JUDGE
    cerr << endl;
    cerr << "Exec Time: " << duration.count() / 1000 << " ms" << endl;
    cerr << "Curr Time: " << formatted_time << endl;
#endif
}
