class Node {
public:
    int data;
    Node* next;
  
    Node(int x) {
        this->data = x;
        this->next = nullptr;
    }
};
int getLength(Node* head)
{
    int length=0;
    while(head)
    {
        length++;
        head=head->next;
    }
    return length;
}
int getMiddle(Node* head)
{
    int length=getLength(head);
    int mid_index=length/2;
    while(mid_index--)
    {
        head=head->next;
    }
    return head->data;
}

//Optimal approach
//Floyd's cycling algorithm
int getMiddle(Node* head)
{
    if(head==nullptr||head->next==nullptr)
    {
        return head->data;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}