#include<iostream>
using namespace std;
struct Node{
    public:
        int data;
        Node *next;
    public:
    Node(int data1,Node* next1)
    {
        data=data1;
        next=next1;
    }
    public:
    Node(int data1)
    {
        data=data1;
        next=nullptr;
    }
};
int main()
{
    vector<int> arr={2,5,8,7};
    Node* y=new Node(arr[0]);//We got the memory location of arr[0]
    cout<<y<<endl;
    cout<<y->data<<endl;
    Node a=Node(arr[0]);//Created an object
    cout<<a.data<<endl;
    cout<<a.next<<endl;
}
//Array to a linked list
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1,Node* next1)
    {
        data=data1;
        next=next1;
    }
};
Node convertArr2LL(vector<int> arr)
{
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
int main()
{
    vector<int> arr={2,1,3,8};
    Node* head=convertArr2LL(arr);
    cout<<head->data;
}
//Time complexity is O(N)

//Length of a linked list
int lengthofLL(Node* head)//Time complexity is O(N)
{
    int cnt=0;
    Node *temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
//Traversal of a linked list Time complexity is O(N)
int main()
{
    vector<int> arr={2,1,3,8};
    Node* head=convertArr2LL(arr);
    Node *temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

//Search an element in a linked list
int checkIfPresent(Node* head,int val)
{
    Node *temp=head;
    while(temp!=nullptr)
    {
        if(temp->data==val)
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
//Time complexity is O(N)
