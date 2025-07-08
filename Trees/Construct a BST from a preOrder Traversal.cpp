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
TreeNode* build(vector<int> &A,int& i,int bound)
{
    if(i==A.size()||A[i]>bound)
    {
        return NULL;
    }
    TreeNode* root=new TreeNode(A[i++]);
    root->left=build(A,i,root->val);
    root->right=build(A,i,bound);
    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder)
{
    int i=0;
    return build(preorder,i,INT_MAX);
}
//Time complexity us O(3N)
//Space complexity is O(1)