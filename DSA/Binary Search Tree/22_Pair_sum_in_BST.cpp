
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




Ex: 6 2 8 1 4 7 9 -1 -1 3 5 -1 -1 -1 -1 -1 -1 -1 -1
 2 4 -> 2
 2 6 -> 6
                         6
                      /    \
                     2      8
                    / \    / \
                   1   4  7   9
                      / \
                     3   5




*/

/*

               4
      1  2  3     5  6  7



*/

int countNodes(TreeNode<int> *root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
void printAllPairs(TreeNode<int> *root, int target)
{

    int cntNodes = countNodes(root);
    int cnt = 0;
    TreeNode<int> *temp = root;
    vector<TreeNode<int> *> inorder;
    while (temp)
    {
        inorder.push_back(temp);
        temp = temp->left;
    }

    temp = root;

    vector<TreeNode<int> *> revinorder;

    while (temp)
    {
        revinorder.push_back(temp);
        temp = temp->right;
    }

    TreeNode<int> *top1 = inorder.back();
    TreeNode<int> *top2 = revinorder.back();

    inorder.pop_back();
    revinorder.pop_back();

    while (cnt < cntNodes - 1)
    {

        TreeNode<int> *top1 = inorder.back();
        TreeNode<int> *top2 = revinorder.back();

        if ((top1->val + top2->val) == target)
        {
            cout << top1->val << " " << top2->val << endl;

            TreeNode<int> *temp = top1;
            inorder.pop_back();
            revinorder.pop_back();

            if (temp->right)
            {
                temp = temp->right;
                while (temp)
                {
                    inorder.push_back(temp);
                    temp = temp->left;
                }
            }

            temp = top2;
            if (temp->left)
            {
                temp = temp->left;
                while (temp)
                {
                    revinorder.push_back(temp);
                    temp = temp->right;
                }
            }
        }
        else if ((top1->val + top2->val) > target)
        {
            revinorder.pop_back();
            TreeNode<int> *temp = top2;
            if (temp->left)
            {
                temp = temp->left;
                while (temp)
                {
                    revinorder.push_back(temp);
                    temp = temp->right;
                }
            }
        }
        else
        {
            inorder.pop_back();
            TreeNode<int> *temp = top1;
            if (temp->right)
            {
                temp = temp->right;
                while (temp)
                {
                    revinorder.push_back(temp);
                    temp = temp->left;
                }
            }
        }
    }
}
//____________________________________________________________________________________________________

class BSTIterator
{
public:
    vector<TreeNode<int> *> st1;
    vector<TreeNode<int> *> st2;

    void putLeftNodes(TreeNode<int> *root)
    {
        while (root)
        {
            st1.push_back(root);
            root = root->left;
        }
    }

    void putRightNodes(TreeNode<int> *root)
    {
        while (root)
        {
            st2.push_back(root);
            root = root->right;
        }
    }

    int getLeftNode()
    {
        TreeNode<int> *temp = st1.back();
        st1.pop_back();
        putLeftNodes(temp->right);
        return temp->val;
    }

    int getRightNode()
    {
        TreeNode<int> *temp = st2.back();
        st2.pop_back();
        putRightNodes(temp->left);
        return temp->val;
    }
};

//> Pair sum using BST iterator
void pairSum(TreeNode<int> *root, int target)
{
    BSTIterator obj;
    obj.putLeftNodes(root);
    obj.putRightNodes(root);

    int left = obj.getLeftNode();
    int right = obj.getRightNode();

    while (left < right)
    {
        debug(left, right);
        if (left + right == target)
        {
            cout << left << " + " << right << " = " << target << endl;
            left = obj.getLeftNode();
            right = obj.getRightNode();
        }
        else if (left + right > target)
        {
            right = obj.getRightNode();
        }
        else
        {
            left = obj.getLeftNode();
        }
    }
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
    // printAllPairs(root, 5);
    pairSum(root, 12);
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
