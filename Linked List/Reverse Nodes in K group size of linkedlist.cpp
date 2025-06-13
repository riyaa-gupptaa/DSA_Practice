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
Node* reverse(Node* head)
{
    Node* temp=head;
    Node* front=NULL;
    Node* prev=NULL;
    while(temp!=NULL)
    {
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
Node* findKthNode(Node* temp,int k)
{
    k-=1;
    while(temp!=NULL && k>=0)
    {
        k--;
        temp=temp->next;
    }
    return temp;
}
Node *reverseKGroup(Node *head, int k)
{
    Node* temp=head;
    Node* prevLast=NULL;
    while(temp!=NULL)
    {
        Node* kthNode=findKthNode(temp,k);
        if(kthNode==NULL)
        {
            if(prevLast)
            {
                prevLast->next=temp;
            }
            break;
        }
        Node* nextNode=kthNode->next;
        kthNode->next=NULL;
        Node* reversehead=reverse(temp);
        if(temp==head)
        {
            head=reversehead;
        }
        else{
            prevLast->next=reversehead;
        }
        prevLast=temp;
        temp=nextNode;
    }
    return head;
}
//Time complexity is O(2N)
//Space complexity is O(1)