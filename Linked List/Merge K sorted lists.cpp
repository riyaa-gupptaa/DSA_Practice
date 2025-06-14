#include <iostream>
using namespace std;
#include<queue>
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
Node* convert(vector<int> &arr)
{
    if(arr.size()==0)
    {
        return NULL;
    }
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=mover->next;
    }
    return head;
}
Node* mergeKLists(vector<Node*>& arr)
{
    vector<int> ans;
    for(int i=0;i<arr.size();i++)
    {
        Node* temp=arr[i];
        while(temp!=NULL)
        {
            ans.push_back(temp->data);
            temp=temp->next;
        }
    }
    sort(ans.begin(),ans.end());
    Node* head=convert(ans);
    return head;
}
//Time complexity is O(n*K)+MlogM+M
//Space complexity is O(M)+O(M)

//Optimal solution
Node* merge2Lists(Node* a,Node* b)
{
    Node* dummy=new Node(-1);
    Node* curr=dummy;
    while(a!=nullptr && b!=nullptr)
    {
        if(a->data<=b->data)
        {
            curr->next=a;
            a=a->next;
        }
        else{
            curr->next=b;
            b=b->next;
        }
        curr=curr->next;
    }
    if(a!=nullptr)
    {
        curr->next=a;
    }
    if(b!=nullptr)
    {
        curr->next=b;
    }
    return dummy->next;
}
Node* mergeKLists(vector<Node*>& arr)
{
     Node* head=arr[0];
     for(int i=1;i<arr.size();i++)
     {
        head=merge2Lists(head,arr[i]);
     }
     return head;
}
//Time complexity is O(N*(K*k+1)/2)
//Space complexity is O(1)

//We will use minHeap
Node* mergeKLists(vector<Node*>& arr)
{
    priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> pq;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i])
        {
            pq.push({arr[i]->data,arr[i]});
        }
    }
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        if(it.second->next)
        {
            pq.push({it.second->next->data,it.second->next});
        }
        temp->next=it.second;
        temp=temp->next;
    }
    return dummyNode->next;
}