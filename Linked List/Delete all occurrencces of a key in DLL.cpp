#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

Node *deleteAllOccurrences(Node *head, int k)
{
    // Write your code here
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == k)
        {
            if (temp == head)
            {
                head = head->next;
            }
            Node *newNode = temp->next;
            Node *prevNode = temp->prev;
            if (newNode)
            {
                newNode->prev = prevNode;
            }
            if (prevNode)
            {
                prevNode->next = newNode;
            }
            free(temp);
            temp = newNode;
        }
        else
        {
            temp=temp->next;
        }
    }
    return head;
}