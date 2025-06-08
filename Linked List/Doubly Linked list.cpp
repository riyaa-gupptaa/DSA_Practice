#include<iostream>
#include<vector>
using namespace std;
//Representation of a DLL
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    public:
    Node(int data1,Node* next1,Node* prev1)
    {
        data=data1;
        next=next1;
        prev=prev1;
    }
    public:
    Node(int data1)
    {
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};
//Array to a doubly linked list
Node* ConvertArr2DLL(Node* head)
{
    vector<int> arr={1,3,2,4};
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size()-1;i++)
    {
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
//Deletion of Node

Node* deletehead(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return NULL;
    }
    Node* prev=head;
    head=head->next;
    head->prev=nullptr;
    prev->next=nullptr;
    delete prev ;
    return head;
}

//Delete the tail of the linked list
Node* deleteTail(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return NULL;
    }
    Node* tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    Node* newTail=tail->prev;
    newTail->next=nullptr;
    tail->prev=nullptr;
    delete tail;
    return head;
}
//Delete the kth element of the DLL

Node* deleteKthElement(Node* head,int k)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        if(cnt==k)
        {
            break;
        }
        temp=temp->next;
    }
    Node* prev=temp->prev;
    Node* front=temp->next;
    if(prev==NULL && front==NULL)
    {
        delete temp;
        return NULL;
    }
    else if(prev==NULL)
    {
        deletehead(head);
        return;
    }
    else if(front==NULL)
    {
        deleteTail(head);
        return;
    }
    else{
        prev->next=front->next;
        front->prev=prev;
        temp->next=nullptr;
        temp->prev=nullptr;
        delete temp;
    }
    return head;
}

//Delete from the gievn Node
void deleteNode(Node* temp)
{
    Node* prev=temp->prev;
    Node* front=temp->next;
    if(front==NULL)
    {
        prev->next=nullptr;
        free(temp);
        return;
    }
    prev->next=front;
    front->prev=prev;
    temp->next=temp->prev=nullptr;
    free(temp);
}

//Insertion Before: 1)head 2)tail 3)Kth 4)Node
Node* insertBeforeHead(Node* head,int val)
{
    Node* newNode=new Node(val,head,nullptr);
    head->prev=newNode;
    return newNode;
}

//Insertion Before Tail
Node* insertBeforeTail(Node* head,int val)
{
    if(head->next==NULL)
    {
        return insertBeforeHead(head,val);
    }
    Node* tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    Node* prev=tail->prev;
    Node* newNode=new Node(val,tail,prev);
    prev->next=newNode;
    tail->prev=newNode;
    return head;
}

//Insert Before the kth Node
Node* insertBeforekthElement(Node* head,int k,int val)
{
    if(k==1)
    {
        return insertBeforeHead(head,val);
    }
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        if(cnt==k)
        {
            break;
        }
        temp=temp->next;
    }
    Node* prev=temp->prev;
    Node* newNode=new Node(val,temp,prev);
    prev->next=newNode;
    temp->prev=newNode;
    return head;
}

//Inserting before a given node
void insertBeforeNode(Node* node,int val)
{
    Node* prev=node->prev;
    Node* newNode=new Node(val,node,prev);
    prev->next=newNode;
    node->prev=newNode;
}