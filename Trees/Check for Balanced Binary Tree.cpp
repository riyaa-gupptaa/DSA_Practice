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
//For every node height(left)-height(right)<=1
int check(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh=check(root->left);
    int rh=check(root->right);
    if(lh==-1||rh==-1)
    {
        return -1;
    }
    if(abs(lh-rh)>1)
    {
        return -1;
    }
    return max(lh,rh)+1;
}
bool isBalanced(Node* root)
{
    if(root==NULL)
    {
        return true;
    }
    return check(root)!=-1;
}