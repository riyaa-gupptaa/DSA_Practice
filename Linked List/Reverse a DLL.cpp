#include<iostream>
#include<vector>
#include<queue>
#include<stack>
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class Solution {
    public:
      // Function to reverse a doubly linked list
      DLLNode* reverseDLL(DLLNode* head) {
          // Your code here
        DLLNode* temp=head;
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
      }
  };
//Time complexity is O(2N)
//Space complexity is O(N)

//We will use swapping
DLLNode* reverseDLL(DLLNode* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    DLLNode* current=head;
    DLLNode* last=NULL;
    while(current!=NULL)
    {
        last=current->prev;
        current->prev=current->next;
        current->next=last;
        current=current->prev;
    }
    return last->prev;
}
//Time complexity is O(N)
//Space complexity is O(1)