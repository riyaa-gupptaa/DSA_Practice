#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int new_data)
    {
        data = new_data;
        next = nullptr;
    }
};
Node* findNthNode(Node* temp,int k)
{
    int cnt=1;
    while(temp!=NULL)
    {
        if(cnt==k)
        {
            return temp;
        }
        cnt++;
        temp=temp->next;
    }
    return temp;
}
Node *rotate(Node *head, int k)
{
    int len=1;
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        len++;
    }
    k=k%len;
    if(k==len)
    {
        return head;
    }
    temp->next=head;
    Node* newLastNode=findNthNode(head,len-k);
    head=newLastNode->next;
    newLastNode->next=NULL;
    return head;
}
//Time complexity is O(2n)
//Space complexity is O(1)