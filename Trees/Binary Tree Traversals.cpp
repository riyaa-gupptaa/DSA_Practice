#include<iostream>
#include<vector>
using namespace std;
//Preorder Traversal
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
void preOrder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data;
    preOrder(root->left);
    preOrder(root->right);
}
//Time complexity is O(N)
//Space complexity is O(N)

//Inorder Traversal
void inOrder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<endl;
    inOrder(root->right);
}
//Time complexity is O(N)
//Space complexity is O(N)

//PostOrder Traversal
void inOrder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->left);
    inOrder(root->right);
    cout<<root->data<<endl;
}
//Time complexity is O(N)
//Space complexity is O(N)