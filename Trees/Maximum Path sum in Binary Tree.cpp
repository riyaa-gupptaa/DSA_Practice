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
int maxPathDown(Node* root,int &maxi)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=max(0,maxPathDown(root->left,maxi));
    int right=max(0,maxPathDown(root->right,maxi));
    maxi=max(maxi,left+right+root->data);
    return max(left,right)+root->data;
}
int maxPathSum(Node* root)
{
    int maxi=INT_MIN;
    maxPathDown(root,maxi);
    return maxi;
}
