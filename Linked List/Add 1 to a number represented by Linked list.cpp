#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};
Node* reverse(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    Node* prev=nullptr;
    Node* curr=head;
    while(curr!=nullptr)
    {
        Node* newNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=newNode;
    }
    return prev;
}
Node* addOne(Node* head)
{
    head=reverse(head);
    Node* temp=head;
    int carry=1;
    while(temp!=NULL)
    {
        int sum=temp->data+carry;
        temp->data=sum%10;
        carry=sum/10;
        if(carry==0)
        {
            break;
        }
        if(temp->next==NULL && carry!=0)
        {
            temp->next=new Node(carry);
            carry=0;
            break;
        }
        temp=temp->next;
    }
    return reverse(head);
}
//Time complexity is O(3N)
//Space complexity is O(1)
int helper(Node* temp)
{
    if(temp==NULL)
    {
        return 1;
    }
    int carry=helper(temp->next);
    temp->data=temp->data+carry;
    if(temp->data<10)
    {
        return 0;
    }
    temp->data=0;
    return 1;
}
Node* addOne(Node* head)
{
    int carry=helper(head);
    if(carry==1)
    {
        Node* newNode=new Node(1);
        newNode->next=head;
        return newNode;
    }
    return head;
}
//Time complexity is O(N)
//Space complexity is O(N)
