#include <iostream>
#include <vector>
#include<map>
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
int countN(Node *slow)
{
    Node *temp = slow;
    int count = 1;
    while (temp->next != slow)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
int countNodesinLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    int count = 0;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return countN(slow);
        }
    }
    return 0;
}

//Hashing algorithm
int countNodesinLoop(Node *head)
{
    Node* temp=head;
    map<Node*,int> mpp;
    int timer=1;
    while(temp!=NULL)
    {
        if(mpp.find(temp)!=mpp.end())
        {
            int value=mpp[temp];
            return (timer-value);
        }
        mpp[temp]=timer;
        timer++;
        temp=temp->next;
    }
    return 0;
}
//Time complexity is O(N)
//Space complexity is O(N)