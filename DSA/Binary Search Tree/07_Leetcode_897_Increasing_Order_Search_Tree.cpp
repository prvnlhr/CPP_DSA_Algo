
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

template <typename T>
class TreeNode
{

public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
void printTree(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        auto currNode = q.front();
        int currVal = currNode->val;
        q.pop();

        int leftVal = -1;
        int rightVal = -1;

        if (currNode->left != nullptr)
        {
            leftVal = currNode->left->val;
            q.push(currNode->left);
        }
        if (currNode->right != nullptr)
        {
            rightVal = currNode->right->val;
            q.push(currNode->right);
        }

        cout << currVal << " --> L: " << leftVal << ", R: " << rightVal << endl;
    }
}

//> SAMPLE INPUT:  vector<int> inputList{1, 2, 3, 4, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1};

/*

Ex_1: 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

               1
            /     \
           2       3
         /   \    /   \
        4     5  6     7


Ex_2: 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 12 -1 11 14 -1 18 -1 -1 15 20 -1 -1 17 16 -1 -1 -1 -1 -1 -1
vector<int> inputList{1 ,2 3, 4, 5, 6, 7, -1, -1, 8, 9, -1, -1, -1, -1, 12 ,-1, 11, 14, -1, 18, -1, -1, 15, 20 ,-1 ,-1, 17, 16, -1, -1, -1, -1, -1 ,-1};

                1
            /      \
           2        3
         /   \     /   \
        4     5   6     7
            /   \
           8     9
          /     /   \
         12     11    14
          \          / \
           18       15   20
                    / \
                   17    16




*/

TreeNode<int> *buildTree(vector<int> inputList)
{

    int currIndex = 0;
    int n = inputList.size();

    if (n == 0 || inputList[0] == -1)
    {
        return nullptr;
    }

    TreeNode<int> *root = new TreeNode(inputList[currIndex]);
    currIndex++;

    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {

        auto currNode = q.front();
        q.pop();

        int leftChild = inputList[currIndex];
        currIndex++;
        if (leftChild != -1)
        {
            TreeNode<int> *leftNode = new TreeNode(leftChild);
            currNode->left = leftNode;
            q.push(leftNode);
        }

        int rightChild = inputList[currIndex];
        currIndex++;
        if (rightChild != -1)
        {
            TreeNode<int> *rightNode = new TreeNode(rightChild);
            currNode->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}

/*
BST:
           4
         /   \
        2     6
      /  \   /  \
     1    3 5    7

4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1




      17
     /  \
    4    18
  /   \
 2     9

17 4 18 2 9 -1 -1 -1 -1 -1 -1

Output: 4 9 17 18 = 4 +  9 + 17 + 18 = 48








Ex: 6 2 8 0 4 7 8 -1 -1 3 5 -1 -1 -1 -1 -1 -1 -1 -1
                         6
                      /    \
                     2      8
                    / \    / \
                   1   4  7   8
                      / \
                     3   5


OP:
        1
         \
          2
           \
            3
             \
              4
               \
                5
                 \
                  6
                   \
                    7
                     \
                      8


*/

void inorderTra(TreeNode<int> *root, vector<int> &vec)
{
    if (!root)
    {
        return;
    }

    inorderTra(root->left, vec);
    vec.push_back(root->val);
    inorderTra(root->right, vec);
}

TreeNode<int> *increasingBST(TreeNode<int> *root)
{

    vector<int> inorder;
    inorderTra(root, inorder);
    if (inorder.size() == 0)
    {
        return nullptr;
    }
    int indx = 0;
    debug(inorder);

    TreeNode<int> *newRoot = new TreeNode(inorder[indx]);
    indx++;

    TreeNode<int> *prev = newRoot;

    while (indx < inorder.size())
    {
        TreeNode<int> *node = new TreeNode(inorder[indx]);
        prev->right = node;
        prev = node;
        indx++;
    }
    return newRoot;
}
void solve()
{
    int ele;
    vector<int> input;
    while (cin >> ele)
    {
        input.push_back(ele);
    }
    TreeNode<int> *root = buildTree(input);
    auto nR = increasingBST(root);
    printTree(nR);
}

//>-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration.count() / 1000 << endl;
#endif
}
