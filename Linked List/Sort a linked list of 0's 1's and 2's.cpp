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
//Brute force approach
Node* segregate(Node* head)
{
    int cnt0=0;
    Node* temp=head;
    int cnt1=0;
    int cnt2=0;
    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            cnt0++;
        }
        else if(temp->data==1)
        {
            cnt1++;
        }
        else{
            cnt2++;
        }
        temp=temp->next;
    }
    Node* temp=head;
    while(temp!=NULL)
    {
        if(cnt0)
        {
        temp->data=0;
        cnt0--;
        }
        else if(cnt1)
        {
            temp->data=1;
            cnt1--;
        }
        else{
            temp->data=2;
            cnt2--;
        }
        temp=temp->next;
    }
    return head;
}

//Second approach
Node* seggregate(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    Node* zeroHead=new Node(-1);
    Node* oneHead=new Node(-1);
    Node* twoHead=new Node(-1);
    Node* zero=zeroHead;
    Node* one=oneHead;
    Node* two=twoHead;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data=0)
        {
            zero->next=temp;
            zero=temp;
        }
        else if(temp->data=1)
        {
            one->next=temp;
            one=temp;
        }
        else{
            two->next=temp;
            two=temp;
        }
        temp=temp->next;
    }
    zero->next=(oneHead->next)?oneHead->next:twoHead->next;
    one->next=twoHead->next;
    two->next=nullptr;
    Node* newHead=zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return newHead;
}
//Time complexity is O(N)