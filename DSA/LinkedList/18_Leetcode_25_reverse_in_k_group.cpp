
/*
>------------------------------------------------------------------------------------------------------------------------------------------------------------
>                               █▀ ▀█▀ █▀▀ █░░ █░░ █░█ █▀█
>                               ▄█ ░█░ ██▄ █▄▄ █▄▄ █▀█ █▀▄
>------------------------------------------------------------------------------------------------------------------------------------------------------------
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
    int data;
    ListNode *next;

    ListNode(int data)
    {
        this->data = data;
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
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode *reverseLL(ListNode *head)
{

    ListNode *curr = head;
    ListNode *prev = nullptr;
    int cnt = 0;
    while (curr)
    {
        ListNode *nextt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextt;
    }

    return prev;
}

//_ SELF SOLVED AFTER WHOLE DAY OF BRAINSTROMING
//> TIME COMPLEXITY: 2N --> N
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *ptr = head;            // main ptr for interating LL
    ListNode *start = head;          // start head of every group
    ListNode *end = new ListNode(0); // for reversing connections
    ListNode *finalHead = nullptr;   // final output list head

    //> STEPS:
    // 1. Store start node = head and iterate the LL till cnt != k, taking k nodes of groups
    // 2. when cnt == k, ptr will be the kth node, and ptr.next will be next group's head
    // 3. reverse k nodes starting from start
    // 4. after reversing we have reversed k nodes directions, but we still need to change their connections
    // i.e its left and right-most nodes direction
    // 5. we get left-most node which is start, and right-most node will be store in end
    // 6. change connections by start.next = nextGrphHead,  and end.next = newHead, i.e head of reversed group
    // 7. finally update all ptr's and cnt = 1;

    int cnt = 1;
    while (ptr)
    {
        if (cnt == k)
        {
            ListNode *nextGrphHead = ptr->next;

            ptr->next = nullptr;

            //> Reversing k nodes or group staring from grphHead
            ListNode *newHead = reverseLL(start);

            if (finalHead == nullptr)
            {
                finalHead = newHead;
            }

            //> changing reversed group's  left and right connections
            start->next = nextGrphHead;
            end->next = newHead;

            //> updating values for next iteration
            end = start;
            start = nextGrphHead;
            ptr = nextGrphHead; //* IMP: also move ptr, because connections has reversed
            cnt = 1;
        }
        else
        {
            cnt++;
            ptr = ptr->next;
        }
    }
    return finalHead;
}

void solve()
{
    vector<int> inputList{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, -1};
    // vector<int> inputList{1, 2, 3, 4, 5, 6, 7, 8, 9, -1};
    // vector<int> inputList{1, 2, 3, 4, 5, 6, 7, -1};
    // vector<int> inputList{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, -1};
    // vector<int> inputList{1, 2, -1};

    int k = 3;

    auto head = buildLL(inputList);
    // printLL(head);
    ListNode *newHead = reverseKGroup(head, k);
    cout << endl;

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
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration.count() / 1000 << endl;
#endif
}
