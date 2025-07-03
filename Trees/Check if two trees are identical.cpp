#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};
bool isSameTree(Node* p, Node* q)
{
    if(!p && !q)
    {
        return true;
    }
    if(!p||!q)
    {
        return false;
    }
    if(p->data!=q->data)
    {
        return false;
    }
    return isSameTree(p->left,q->left) && (p->right,q->right);
}
//Time complexity is O(N)
//Space complexity is O(N)