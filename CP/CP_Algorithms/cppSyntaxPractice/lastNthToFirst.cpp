#include <iostream>
#include <vector>
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

Node *lastNNodesToFirst(Node *head, int n)
{

    Node *ptr = head;
    Node *nthRef = head;
    int count = 1;

    while (count < n)
    {
        count++;
        ptr = ptr->next;
    }
    Node *nthPrev = nthRef;

    while (ptr->next)
    {
        nthPrev = nthRef;
        nthRef = nthRef->next;
        ptr = ptr->next;
    }
    ptr->next = head;
    nthPrev->next = NULL;
    head = nthRef;
    return head;
}

int main()
{

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

    Node *newLL = lastNNodesToFirst(head, n);
    printLL(newLL);
}