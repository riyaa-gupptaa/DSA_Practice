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
//Longest path between any two nodes is referred as diameter
//Path does not need to pass via root
int findMax(Node* root,int &maxi)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh=findMax(root->left,maxi);
    int rh=findMax(root->right,maxi);
    maxi=max(maxi,lh+rh);
    return 1+max(lh,rh);
}
int diameterOfBinaryTree(Node* root)
{
    int diameter=0;
    findMax(root,diameter);
    return diameter;
}
//Time complexity is O(N)
//Space complexity is O(N)