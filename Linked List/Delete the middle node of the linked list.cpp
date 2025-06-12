#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};
Node* deleteMid(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return NULL;
    }
    Node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    int midd=count/2;
    Node* temp=head;
    while(temp!=NULL)
    {
        midd--;
        if(midd==0)
        {
            Node* middle=temp->next;
            temp->next=temp->next->next;
            delete middle;
            break;
        }
        temp=temp->next;
    }
    return head;
}
//Time complexity is O(N)
//Space complexity is O(1)

//Floyd's Algorithm
Node* deleteMid(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    fast=fast->next->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* middle=slow->next;
    slow->next=slow->next->next;
    free(middle);
    return head;
}
//Time complexity is O(N/2)
//Space complexity is O(1)