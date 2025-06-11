#include <iostream>
#include<stack>
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
bool isPalindrome(Node* head)
{
    stack<int> st;
    Node* temp=head;
    while(temp!=NULL)
    {
        st.push(temp->data);
        temp=temp->next;
    }
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data!=st.top())
        {
            return false;
        }
        temp=temp->next;
        st.pop();
    }
    return true;
}
//Time complexity is O(2N)
//Space complexity is O(N)

//Other approach
Node* reverse(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    Node* newHead=reverse(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}
bool isPalindrome(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL||fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newHead=reverse(slow->next);
    Node* first=head;
    Node* second=newHead;
    while(second!=NULL)
    {
        if(first->data!=second->data)
        {
            reverse(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverse(newHead);
    return true;
}
//Time complexity is O(2N)
//Space complexity is O(1)