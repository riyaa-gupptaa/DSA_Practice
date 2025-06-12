#include <iostream>
using namespace std;
struct Node
{
    int data;
        Node*  prev;
        Node*  next;
        Node() {
            this->data = 0;
            this->prev = NULL;
            this->next = NULL;
        }
        Node(int data) {
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
        Node (int data, Node*  next, Node*  prev) {
            this->data = data;
            this->prev = prev;
            this->next = next;
        }
};
class Solution
{
public:
    // Function to remove duplicates from sorted linked list.
    Node*  removeDuplicates(Node*  head)
    {
        Node*  temp=head;
        while(temp!=NULL && temp->next!=NULL)
        {
            Node*  nextNode=temp->next;
            while(nextNode!=NULL && nextNode->data==temp->data)
            {
                nextNode=nextNode->next;
            }
            temp->next=nextNode;
            if(nextNode!=NULL)
            {
                nextNode->prev=temp;
            }
            temp=temp->next;
        }
        return head;
    }
};