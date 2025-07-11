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
int findMaxDistance(map<TreeNode*,TreeNode*> &mp,TreeNode* target)
{
    queue<TreeNode*> q;
    q.push(target);
    map<TreeNode*,int> vis;
    vis[target]=1;
    int maxi=0;
    while(!q.empty())
    {
        int sz=q.size();
        int f1=0;
        for(int i=0;i<sz;i++)
        {
            auto node=q.front();
            q.pop();
            if(node->left && !vis[node->left])
           {
            f1=1;
            vis[node->left]=1;
            q.push(node->left);
           }
           if(node->right && !vis[node->right])
           {
            f1=1;
            vis[node->right]=1;
            q.push(node->right);
           }
           if(mp[node] && !vis[mp[node]])
           {
            f1=1;
            vis[mp[node]]=1;
            q.push(mp[node]);
           }
        }
        if(f1)
        {
            maxi++;
        }
    }
    return maxi;
}
TreeNode* bfsToMakeParent(TreeNode* root,map<TreeNode*,TreeNode*> &mp,int start)
{
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* res;
    while(!q.empty())
    {
        TreeNode* node=q.front();
        if(node->data==start)
        {
            res=node;
        }
        q.pop();
        if(node->left)
        {
            mp[node->left]=node;
            q.push(node->left);
        }
        if(node->right)
        {
            mp[node->right]=node;
            q.push(node->right);
        }
    }
    return res;
}
int amountOfTime(TreeNode *root, int start)
{
    map<TreeNode*,TreeNode*> mp;
    TreeNode* target=bfsToMakeParent(root,mp,start);
    int maxi=findMaxDistance(mp,target);
    return maxi;
}
//Time complexity is O(N)+O(N)~O(N)
//Space complexity is O(N)