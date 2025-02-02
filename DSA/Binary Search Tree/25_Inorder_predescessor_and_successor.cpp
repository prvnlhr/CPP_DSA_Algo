
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

void preSucc(TreeNode<int> *root, TreeNode<int> *&pre, TreeNode<int> *&succ, int key)
{
    if (!root)
    {
        return;
    }

    preSucc(root->left, pre, succ, key);

    if (root && root->val < key)
    {
        pre = root;
    }

    if (root && root->val > key)
    {
        if (!succ)
        {
            succ = root;
        }
        else if (succ && succ->val > root->val)
        {
            succ = root;
        }
    }

    preSucc(root->right, pre, succ, key);
}

pair<int, int> findPreSucc(TreeNode<int> *root, int key)
{
    TreeNode<int> *pre = nullptr;
    TreeNode<int> *succ = nullptr;
    preSucc(root, pre, succ, key);
    pair<int, int> p{pre->val, succ->val};
    return p;
}
void solve()
{

    vector<int> arr;
    int ele;
    while (cin >> ele)
    {
        arr.push_back(ele);
    }
    TreeNode<int> *root = buildTree(arr);
    auto ans = findPreSucc(root, 10);
    debug(ans);
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
