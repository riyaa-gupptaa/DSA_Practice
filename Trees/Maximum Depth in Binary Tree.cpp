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
//Recursive takes O(height) complexity
//Level order takes O(N) complexity
int maxDepth(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int l=maxDepth(root->left);
    int r=maxDepth(root->right);
    return 1+max(l,r); 
}