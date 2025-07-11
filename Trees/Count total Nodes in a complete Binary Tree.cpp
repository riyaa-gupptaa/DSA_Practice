#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int val)
    {
        data = val;
        left = right = NULL;
    }
};
//Number of nodes in a complete tree is 2^heightoftree -1;
int findheightleft(TreeNode* node)
{
    int height=0;
    while(node)
    {
        height++;
        node=node->left;
    }
    return height;
}
int findheightright(TreeNode* node)
{
    int height=0;
    while(node)
    {
        height++;
        node=node->right;
    }
    return height;
}
int countNodes(TreeNode *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh=findheightleft(root);
    int rh=findheightright(root);
    if(lh==rh)
    {
        return (1<<lh)-1;
    }
    return 1+countNodes(root->left)+countNodes(root->right);
}