#include <iostream>
using namespace std;
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
Node* convert(vector<int> &arr)
{
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
Node *sortedMerge(Node *head1, Node *head2)
{
    Node* temp1=head1;
    Node* temp2=head2;
    vector<int> arr;
    while(temp1!=NULL)
    {
        arr.push_back(temp1->data);
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        arr.push_back(temp2->data);
        temp2=temp2->next;
    }
    sort(arr.begin(),arr.end());
    Node* head=convert(arr);
    return head;
}
//Time complexity is O(NlogN)+O(N)
//Space complexity is O(N)+O(N)

//2nd Approach
Node *sortedMerge(Node *head1, Node *head2)
{
    Node* temp1=head1;
    Node* temp2=head2;
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data<temp2->data)
        {
            temp->next=temp1;
            temp=temp1;
            temp1=temp1->next;
        }
        else{
            temp->next=temp2;
            temp=temp2;
            temp2=temp2->next;
        }
    }
    if(temp1)
    {
        temp->next=temp1;
    }
    else{
        temp->next=temp2;
    }
    return dummyNode->next;
}
//Time complexity is O(N1+N2)
//Space complexity is O(1)