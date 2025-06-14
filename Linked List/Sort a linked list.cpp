#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
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
        mover->next=temp;
        mover=mover->next;
    }
    return head;
}
Node *sortLL(Node *head)
{
    Node* temp=head;
    vector<int> arr;
    while(temp!=NULL)
    {
        arr.push_back(temp->data);
        temp=temp->next;
    }
    sort(arr.begin(),arr.end());
    Node* newhead=convert(arr);
    return newhead;
}

//Time complexity is O(N+NlogN+N)
//Space complexity is O(N)

//Using merge Sort
Node* findMiddle(Node* head)
{
    Node* slow=head;
    Node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node* mergeTwoLists(Node* list1,Node* list2)
{
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;
    while(list1!=NULL && list2!=NULL)
    {
        if(list1->data<list2->data)
        {
            temp->next=list1;
            temp=list1;
            list1=list1->next;
        }
        else{
            temp->next=list2;
            temp=list2;
            list2=list2->next;
        }
    }
    if(list1)
    {
        temp->next=list1;
    }
    else{
        temp->next=list2;
    }
    return dummyNode->next;
}
Node *sortLL(Node *head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    Node* middle=findMiddle(head);
    Node* lefthead=head;
    Node* right=middle->next;
    middle->next=nullptr;
    Node* left=head;
    left=sortLL(left);
    right=sortLL(right);
    return mergeTwoLists(left,right);
}
//Time complexity os O(logN*(N+N/2))
//Space complexity is O(1)