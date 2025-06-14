#include <iostream>
#include<map>
using namespace std;
class Node
{
public:
    // Data stored in the node
    int data;
    // Pointer to the next node
    Node *next;
    // Pointer to a random
    // node in the list
    Node *random;

    // Constructors for Node class
    Node() : data(0), next(nullptr), random(nullptr) {};
    Node(int x) : data(x), next(nullptr), random(nullptr) {}
    // Constructor with data,
    // next, and random pointers
    Node(int x, Node *nextNode, Node *randomNode) : data(x), next(nextNode), random(randomNode) {}
};
Node *cloneLL(Node *head)
{
    Node* temp=head;
    map<Node*,Node*> mpp;
    while(temp!=NULL)
    {
        Node* newNode=new Node(temp->data);
        mpp[temp]=newNode;
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        Node* copyNode=mpp[temp];
        copyNode->random=mpp[temp->random];
        temp=temp->next; 
    }
    return mpp[head];
}
//Time complexity is O(2N)
//Space complexity is O(N)+O(N)

//1)Insert copy Nodes in between
//2)Connect Random Pointers
//3)Connect next Pointer
Node *cloneLL(Node *head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        Node* copyNode=new Node(temp->data);
        copyNode->next=temp->next;
        temp->next=copyNode;
        temp=temp->next->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        Node* copyNode=temp->next;
        if(temp->random!=NULL)
        {
        copyNode->random=temp->random->next;
        }
       else{
        copyNode->random=nullptr;
       }
       temp=temp->next->next;
    }
    Node* dummyNode=new Node(-1);
    Node* res=dummyNode;
    Node* temp=head;
    while(temp!=NULL)
    {
        res->next=temp->next;
        temp->next=temp->next->next;
        res=res->next;
        temp=temp->next;
    } 
    return dummyNode->next;
}
//Time complexity is O(3N)
//Space complexity is O(N)