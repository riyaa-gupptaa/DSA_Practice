#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
Node* insertIntoBST(Node* root, int val)
{
    if(root==NULL)
    {
        return new Node(val);
    }
    Node *curr=root;
    while(true)
    {
        if(curr->data<=val)
        {
            if(curr->right!=NULL)
            {
                curr=curr->right;
            }
            else{
                curr->right=new Node(val);
                break;
            }
        }
        else{
            if(curr->left!=NULL)
            {
                curr=curr->left;
            }
            else{
                curr->left=new Node(val);
                break;
            }
        }
    }
    return root;
}
//Time complexity is O(logn)