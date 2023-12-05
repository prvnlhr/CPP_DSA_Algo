
/*
|>------------------------------------------------------------------------------------------------------------------------------------------------------------
|>                               █▀ ▀█▀ █▀▀ █░░ █░░ █░█ █▀█
|>                               ▄█ ░█░ ██▄ █▄▄ █▄▄ █▀█ █▀▄
|>------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define MOD 1000000007
#define MOD1 998244353
#define PI 3.141592653589793238462

typedef long long ll;

// |> --- DEBUG_TEMPLATE_START ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    return os << '{' << p.first << ", " << p.second << '}';
}

template <class T, class = decltype(begin(declval<T>())),
          class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &os, const T &c)
{
    os << '[';
    for (auto it = begin(c); it != end(c); ++it)
        os << (it == begin(c) ? "" : ", ") << *it;
    return os << ']';
}

#define _NTH_ARG(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N
#define _FE_1(_CALL, x) _CALL(x)
#define _FE_2(_CALL, x, ...) _CALL(x) _FE_1(_CALL, __VA_ARGS__)
#define _FE_3(_CALL, x, ...) _CALL(x) _FE_2(_CALL, __VA_ARGS__)
#define _FE_4(_CALL, x, ...) _CALL(x) _FE_3(_CALL, __VA_ARGS__)
#define _FE_5(_CALL, x, ...) _CALL(x) _FE_4(_CALL, __VA_ARGS__)
#define _FE_6(_CALL, x, ...) _CALL(x) _FE_5(_CALL, __VA_ARGS__)
#define _FE_7(_CALL, x, ...) _CALL(x) _FE_6(_CALL, __VA_ARGS__)
#define _FE_8(_CALL, x, ...) _CALL(x) _FE_7(_CALL, __VA_ARGS__)
#define _FE_9(_CALL, x, ...) _CALL(x) _FE_8(_CALL, __VA_ARGS__)
#define _FE_10(_CALL, x, ...) _CALL(x) _FE_9(_CALL, __VA_ARGS__)
#define FOR_EACH_MACRO(MACRO, ...)                                                               \
    _NTH_ARG(__VA_ARGS__, _FE_10, _FE_9, _FE_8, _FE_7, _FE_6, _FE_5, _FE_4, _FE_3, _FE_2, _FE_1) \
    (MACRO, __VA_ARGS__)

//-- Change output format here ______________________________________________________________________________________________________________________________________________________
#define out(x) #x " = " << x << "; "

#ifndef ONLINE_JUDGE
#define debug(...) \
    cerr << "Line " << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
#else
#define debug(...)
#endif

//|> --- DEBUG_TEMPLATE_END -----------------------------------------------------------------------------------------------------------------------------------------------------------

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

//|> --- GCD -------------------------------------------------------------------
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

//|> --- EXPONENTIAL ----------------------------------------------------------
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

//|> --- FACTORIAL ------------------------------------------------------------
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

//|> --- SOLVE -----------------------------------------------------------------------------------------------------------------------------------------------

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

struct DLLNode
{
    int val;
    DLLNode *prev;
    DLLNode *next;

    DLLNode(int x)
    {
        val = x;
        prev = nullptr;
        next = nullptr;
    }
};

void printTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<TreeNode *> q;
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

TreeNode *buildTree(vector<int> inputList)
{

    int currIndex = 0;
    int n = inputList.size();

    if (n == 0 || inputList[0] == -1)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(inputList[currIndex]);
    currIndex++;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {

        auto currNode = q.front();
        q.pop();

        int leftChild = inputList[currIndex];
        currIndex++;
        if (leftChild != -1)
        {
            TreeNode *leftNode = new TreeNode(leftChild);
            currNode->left = leftNode;
            q.push(leftNode);
        }

        int rightChild = inputList[currIndex];
        currIndex++;
        if (rightChild != -1)
        {
            TreeNode *rightNode = new TreeNode(rightChild);
            currNode->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}

// ---------------------------------------------------------------------------------------

void BSTtoDLLHelper(TreeNode *root, DLLNode *&headNode, DLLNode *&tailNode)
{
    if (!root)
    {
        return;
    }

    BSTtoDLLHelper(root->left, headNode, tailNode);

    DLLNode *newNode = new DLLNode(root->val);

    if (!headNode)
    {
        headNode = newNode;
        tailNode = newNode;
    }
    else
    {
        tailNode->next = newNode;
        newNode->prev = tailNode;
        tailNode = newNode;
    }

    BSTtoDLLHelper(root->right, headNode, tailNode);
}

DLLNode *BSTtoDLL(TreeNode *root)
{
    DLLNode *head = nullptr;
    DLLNode *tail = nullptr;
    BSTtoDLLHelper(root, head, tail);
    return head;
}

// -----------------------------------------------------------------------------
TreeNode *mergeDLL(DLLNode *head1, DLLNode *head2, int &count)
{
    TreeNode *root = nullptr;

    while (head1 && head2)
    {
        if (head1->val < head2->val)
        {
            count++;
            if (!root)
            {
                root = new TreeNode(head1->val);
            }
            else
            {
                root->right = new TreeNode(head1->val);
                root->right->left = root;
                root = root->right;
            }
            head1 = head1->next;
        }
        else
        {
            count++;
            if (!root)
            {
                root = new TreeNode(head2->val);
            }
            else
            {
                root->right = new TreeNode(head2->val);
                root->right->left = root;
                root = root->right;
            }
            head2 = head2->next;
        }
    }

    while (head1)
    {
        count++;
        root->right = new TreeNode(head1->val);
        root->right->left = root;
        root = root->right;
        head1 = head1->next;
    }

    while (head2)
    {
        count++;
        root->right = new TreeNode(head2->val);
        root->right->left = root;
        root = root->right;
        head2 = head2->next;
    }

    return root;
}
// -----------------------------------------------------------------------------

TreeNode *DLLtoBST(DLLNode *&head, int n)
{
    if (n <= 0 || !head)
    {
        return nullptr;
    }

    TreeNode *left = DLLtoBST(head, n / 2);
    TreeNode *root = new TreeNode(head->val);
    head = head->next;
    root->left = left;
    root->right = DLLtoBST(head, n - (n / 2) - 1);

    return root;
}
// -----------------------------------------------------------------------------

TreeNode *mergeBTS(TreeNode *root1, TreeNode *root2)
{
    DLLNode *head1 = BSTtoDLL(root1);
    DLLNode *head2 = BSTtoDLL(root2);

    int count = 0;
    
    TreeNode *mergedRoot = mergeDLL(head1, head2, count);

    DLLNode *dummy = new DLLNode(0);
    dummy->next = head1 ? head1 : head2;

    return DLLtoBST(dummy->next, count);
}

// -----------------------------------------------------------------------------
void printInOrder(TreeNode *root)
{
    if (root)
    {
        printInOrder(root->left);
        cout << root->val << " ";
        printInOrder(root->right);
    }
}
void solve()
{
    vector<int> input1{6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5, -1, -1, -1, -1, -1, -1, -1, -1};
    vector<int> input2{4, 2, 6, 1, 3, 5, 7, -1, -1, -1, -1, -1, -1, -1, -1};
    TreeNode *root1 = buildTree(input1);
    TreeNode *root2 = buildTree(input2);

    auto mergedBST = mergeBTS(root1, root2);

    // Print the in-order traversal of the merged BST
    cout << "In-order traversal of the merged BST: ";
    printInOrder(mergedBST);
}

//|> --- MAIN -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
