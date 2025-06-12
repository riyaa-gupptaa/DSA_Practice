#include <iostream>
#include<vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    Node* temp1=head;
    vector<pair<int,int>> ans;
    while(temp1!=NULL)
    {
        Node* temp2=temp1->next;
        while(temp2!=NULL && (temp1->data+temp2->data)<=target)
        {
            if(temp1->data+temp2->data==target)
            {
                ans.push_back({temp1->data,temp2->data});
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return ans;
}

//Another approach
Node* findTail(Node* head)
{
    Node* tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    return tail;
}
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int,int>> ans;
    Node* left=head;
    Node* right=findTail(head);
    while(left->data<right->data)
    {
        if(left->data+right->data==target)
        {
            ans.push_back({left->data,right->data});
            left=left->next;
            right=right->next;
        }
        else if(left->data+right->data<target)
        {
            left=left->next;
        }
        else{
            right=right->next;
        }
    }
    return ans;
}
//TIme complexity is O(n)