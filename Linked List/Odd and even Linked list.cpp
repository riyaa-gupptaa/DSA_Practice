#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
Node* oddEvenLinkedList(Node* head)
{
    if(head==nullptr||head->next==nullptr)
    {
        return head;
    }
    Node* odd=head;
    Node* even=head->next;
    Node* evenHead=head->next;
    while(even!=nullptr && even->next!=nullptr)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenHead;
    return head;
}
//Time complexity is O(n)
//Space complexity is O(1)