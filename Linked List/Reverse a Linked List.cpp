#include <iostream>
using namespace std;
#include<stack>
// Using a stack
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
Node *reverseList(Node *head)
{
    Node* temp=head;
    stack<int> st;
    while(temp!=NULL)
    {
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}
//Time complexity is O(2N)
//Space complexity is O(N)

Node* reverseList(Node* head)
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

//3rd Method
Node* reverseList(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    Node* newHead=reverseList(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}
//Time complexity is O(N)
//Space complexity is O(n)