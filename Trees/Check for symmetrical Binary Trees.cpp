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
//It forms a mirror of itself around the entre or not
bool isSymmetricHelp(Node* left,Node* right)
{
    if(left==NULL||right==NULL)
    {
        return left==right;
    }
    if(left->data!=right->data)
    {
        return false;
    }
    return isSymmetricHelp(left->left,right->right) && isSymmetricHelp(left->right,right->left);
}
bool isSymmetric(Node* root)
{
    return root==NULL|| isSymmetricHelp(root->left,root->right);
}
//Time complexity is O(N)
//Space complexity is O(N)