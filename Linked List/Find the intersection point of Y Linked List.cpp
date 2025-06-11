#include <iostream>
#include<map>
using namespace std;
// hashing Method
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};
Node *intersectPoint(Node *head1, Node *head2)
{
    map<Node*,int> mpp;
    Node* temp=head1;
    while(temp!=NULL)
    {
        mpp[temp]=1;
        temp=temp->next;
    }
    Node* temp=head2;
    while(temp!=NULL)
    {
        if(mpp.find(temp)!=mpp.end())
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}
//Time complexity is O(N1)+O(N2)
//Space complexity is O(N1)

//Length Difference approach
int getlength(Node* head)
{
    int len=0;
    while(head!=nullptr)
    {
        len++;
        head=head->next;
    }
    return len;
}

Node* intersectPoint(Node* head1,Node* head2)
{
    int len1=getlength(head1);
    int len2=getlength(head2);
    int diff=abs(len1-len2);
    if(len1>len2)
    {
        while(diff--)
        {
            head1=head1->next;
        }
    }
    else{
        while(diff--)
        {
            head2=head2->next;
        }
    }
    while(head1!=nullptr && head2!=nullptr)
    {
        if(head1==head2)
        {
            return head1;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return nullptr;
}

//Optimised approach
Node* intersectPoint(Node* head1,Node* head2)
{
    if(head1==NULL||head2==NULL)
    {
        return NULL;
    }
    Node* t1=head1;
    Node* t2=head2;
    while(t1!=t2)
    {
        t1=t1->next;
        t2=t2->next;
        if(t1==t2)
        {
            return t1;
        }
        if(t1==NULL)
        {
            t1=head2;
        }
        if(t2==NULL)
        {
            t2=head1;
        }
    }
    return t1;
}