#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *bottom;

    Node(int newdata)
    {
        data = newdata;
        next = bottom = nullptr;
    }
};
Node* convert(vector<int> &arr)
{
    if(arr.size()==0)
    {
        return NULL;
    }
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i]);
        mover->bottom=temp;
        mover=mover->bottom;
    }
    return head;
}
Node* flatten(Node* root)
{
    vector<int> arr;
    Node* temp=root;
    while(temp!=NULL)
    {
        Node* t2=temp;
        while(t2!=NULL)
        {
            arr.push_back(t2->data);
            t2=t2->bottom;
        }
        temp=temp->next;
    }
    sort(arr.begin(),arr.end());
    Node* head=convert(arr);
    return head;
}
//Time complexitty is O(N*M)*2+xlogx
//Space complexity is O(N*M)*2

//Optimised solution
//Using dummy Node
Node* mergeTwoLists(Node* a,Node* b)
{
    Node* dummy=new Node(0);
    Node* curr=dummy;
    while(a && b)
    {
        if(a->data < b->data)
        {
            curr->bottom-a;
            a=a->bottom;
        }
        else{
            curr->bottom=b;
            b=b->bottom;
        }
        curr=curr->bottom;
    }
    if(a)
    {
        curr->bottom=a;
    }
    if(b)
    {
        curr->bottom=b;
    }
    return dummy->bottom;
}
Node* flatten(Node* root)
{
    if(root==NULL||root->next==NULL)
    {
        return root;
    }
    Node* curr=root;
    while(curr->next)
    {
        curr->next=flatten(curr->next);
        curr=mergeTwoLists(curr,curr->next);
        curr->next=NULL;
    }
    return curr;
}
//Time complexity is O(2NM)
//Space complexity is O(N)