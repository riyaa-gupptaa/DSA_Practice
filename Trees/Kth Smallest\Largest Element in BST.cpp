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
void inOrder(TreeNode *root, int &k, int &result)
{
    if (!root || k < 0)
    {
        return;
    }
    inOrder(root->left, k, result);
    k--;
    if (k == 0)
    {
        result = root->data;
        return;
    }
    inOrder(root->right, k, result);
}
int kthSmallest(TreeNode *root, int k)
{
    int result = -1;
    inOrder(root, k, result);
    return result;
}
// Time complexity is O(N)
// Space complexity is O(N)

// Kth Largest
void inOrder(Node *root, int &k, int &result)
{
    if (!root || k < 0)
    {
        return;
    }
    inOrder(root->right, k, result);
    k--;
    if (k == 0)
    {
        result = root->data;
        return;
    }
    inOrder(root->left, k, result);
}
int kthLargest(Node *root, int k)
{
    // Your code here
    int result = -1;
    inOrder(root, k, result);
    return result;
}