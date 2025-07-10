#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include<string>
#include<sstream>
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
string serialize(TreeNode *root)
{
    if (!root)
    {
        return "";
    }
    string s = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *currNode = q.front();
        q.pop();
        if (currNode == NULL)
        {
            s.append("#,");
        }
        else
        {
            s.append(to_string(currNode->val) + ',');
        }
        if (currNode != NULL)
        {
            q.push(currNode->left);
            q.push(currNode->right);
        }
    }
    cout << s;
    return s;
}
TreeNode *deserialize(string data)
{
    if(data.size()==0)
    {
        return NULL;
    }
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode* root=new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node=q.front();
        q.pop();
        getline(s,str,',');
        if(str=="#")
        {
            node->left=NULL;
        }
        else{
            TreeNode* leftNode=new TreeNode(stoi(str));
            node->left=leftNode;
            q.push(leftNode);
        }
        getline(s,str,',');
        if(str=="#")
        {
            node->right=NULL;
        }
        else{
            TreeNode* rightNode=new TreeNode(stoi(str));
            node->right=rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
//Time complexity is O(N)
//Space complexity is O(N)