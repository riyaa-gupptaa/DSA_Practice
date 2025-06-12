#include <iostream>
#include<map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};
//Hashing
bool detectLoop(Node* head)
{
    Node* temp=head;
    map<Node*,int> mpp;
    while(temp!=NULL)
    {
        if(mpp.find(temp)!=mpp.end())
        {
            return true;
        }
        mpp[temp]=1;
        temp=temp->next;
    }
    return false;
}
//Time complexity is O(N)
//Space complexity is O(N)

//Floyd's Algorithm
bool detectloop(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;//Moves 1 step
        fast=fast->next->next;//Moves 2 step
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}
//Time complexity is O(n)
//Space complexity is O(1)