#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};
bool isBSTUtil(TreeNode *root, long long minval, long long maxval)
{
    if (!root)
    {
        return true;
    }
    if (root->val <= minval || root->val >= maxval)
    {
        return false;
    }
    return isBSTUtil(root->left, minval, root->val) && isBSTUtil(root->right, root->val, maxval);
}
bool isValidBST(TreeNode *root)
{
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}