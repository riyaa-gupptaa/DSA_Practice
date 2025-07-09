#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void flattenHelper(TreeNode* root, TreeNode*& prev) {
    if (!root) return;

    flattenHelper(root->right, prev);
    flattenHelper(root->left, prev);

    root->right = prev;
    root->left = NULL;
    prev = root;
}

void flatten(TreeNode* root) {
    TreeNode* prev = NULL;
    flattenHelper(root, prev);
}

//Time complexity is O(N)
//Space complexity is O(N)

//Other method
void flatten(TreeNode* root)
{
    stack<TreeNode* > st;
    if(root==NULL)
    {
        return;
    }
    st.push(root);
    while(!st.empty())
    {
        TreeNode* curr=st.top();
        st.pop();
        if(curr->right)
        {
            st.push(curr->right);
        }
        if(curr->left)
        {
            st.push(curr->left);
        }
        if(!st.empty())
        {
            curr->right=st.top();
        }
        curr->left=NULL;
    }
}

//Another method
void flatten(TreeNode* root)
{
    TreeNode* curr=root;
    while(curr!=NULL)
    {
        if(curr->left!=NULL)
        {
            TreeNode* prev=curr->left;
            while(prev->right)
            {
                prev=prev->right;
            }
            prev->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->right;
    }
}