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
        this->next = nullptr;
    }
};

Node *buildLL(vector<int> inputList)
{

    Node *head = nullptr;
    Node *tail = nullptr;

    for (auto currData : inputList)
    {

        if (currData == -1)
        {
            break;
        }

        Node *newNode = new Node(currData);

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

int main()
{

    vector<int> inputList{1, 5, 8, 2, 5, 12, 3, -1};
    Node *head = buildLL(inputList);

    Node *temp = head;

    while (temp->next)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}