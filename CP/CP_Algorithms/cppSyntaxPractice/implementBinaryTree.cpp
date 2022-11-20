#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>

class BinaryTreeNode
{

public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void printTreeLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        int currData = curr->data;

        int left = -1;
        int right = -1;

        if (curr->left != NULL)
        {
            left = curr->left->data;
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            right = curr->right->data;
            q.push(curr->right);
        }

        cout << currData << "-> L: " << left << " R: " << right << endl;
    }
}

BinaryTreeNode<int> *buildTree(vector<int> &inputList)
{
    int index = 0;
    int length = inputList.size();

    if (length <= 0 || inputList[0] == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(inputList[index]);
    index++;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        auto currNode = q.front();
        q.pop();

        int left_child = inputList[index];
        index++;

        if (left_child != -1)
        {
            BinaryTreeNode<int> *left_node = new BinaryTreeNode<int>(left_child);
            currNode->left = left_node;
            q.push(left_node);
        }

        int right_child = inputList[index];
        index++;

        if (right_child != -1)
        {
            BinaryTreeNode<int> *right_node = new BinaryTreeNode<int>(right_child);
            currNode->right = right_node;
            q.push(right_node);
        }
    }
    return root;
}
int main()
{
    // vector<int> inputList{1, 2, 3, 4, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1};
    vector<int> inputList{1, 2, 3, 4, 5, 6, 7, -1, -1, 8, 9, -1, -1, -1, -1, 12, -1, 11, 14, -1, 18, -1, -1, 15, 20, -1, -1, 17, 16, -1, -1, -1, -1, -1, -1};

    BinaryTreeNode<int> *root = buildTree(inputList);
    printTreeLevelWise(root);
}