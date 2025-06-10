#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};
//Brute force
Node* deleteNthNodeFromEnd(Node* head, int n)
{
    int count=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    if(count==n)
    {
        Node* newHead=head->next;
        free(head);
        return newHead;
    }
    int result=count-n;
    Node* temp=head;
    while(temp!=NULL)
    {
        result--;
        if(result==0)
        {
            break;
        }
        temp=temp->next;
    }
    Node* deleteNode=temp->next;
    free(deleteNode);
    temp->next=temp->next->next;
    return head;
}
//Time complexity is O(len)+O(len-N)
//Space complexity is O(1)

Node* removekthNode(Node* head,int k)
{
    Node* fast=head;
    Node* slow=head;
    for(int i=0;i<k;i++)
    {
        fast=fast->next;
    }
    if(fast==NULL)
    {
        return head->next;
    }
    while(fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    Node* delNode=slow->next;
    slow->next=slow->next->next;
    delete delNode;
    return head;
}