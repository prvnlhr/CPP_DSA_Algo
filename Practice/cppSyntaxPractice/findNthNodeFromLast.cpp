// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *buildLL(vector<int> &inputList)
{

    Node *head = NULL;
    Node *tail = NULL;

    for (auto currData : inputList)
    {
        if (currData == -1)
        {
            break;
        }

        else
        {

            Node *newNode = new Node(currData);

            if (head == NULL)
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
    }
    return head;
}

void printLL(Node *head)
{

    Node *temp = head;

    while (temp->next)
    {

        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *nthNodeFromLast(Node *head, int n)
{

    Node *ptr = head;

    while (n > 1)
    {

        ptr = ptr->next;
        n--;
    }

    Node *nthRef = head;

    while (ptr->next)
    {
        nthRef = nthRef->next;
        ptr = ptr->next;
    }

    return nthRef;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numNodes, a, n;
    cin >> numNodes;

    vector<int> inputList;

    while (numNodes--)
    {
        cin >> a;
        inputList.push_back(a);
    }

    cin >> n;

    Node *head = buildLL(inputList);

    Node *nthNode = nthNodeFromLast(head, n);

    cout << nthNode->data;
}