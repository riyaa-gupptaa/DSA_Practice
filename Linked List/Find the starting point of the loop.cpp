#include <iostream>
#include <map>
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
//Hashing
Node* findFirstNode(Node* head)
{
    map<Node*,int> mpp;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(mpp.find(temp)!=mpp.end())
        {
            return temp;
        }
        mpp[temp]=1;
        temp=temp->next;
    }
    return NULL;
}
//Time complexity is O(N)
//Space complexity is O(N)

//Tortoise and hare
Node* findFirstNode(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            slow=head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
}