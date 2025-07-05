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
//Root Right Left
void recursion(Node* root,int level,vector<int>&res)
{
    if(root==NULL)
    {
        return;
    }
    if(res.size()==0)
    {
        res.push_back(root->data);
    }
    recursion(root->right,level+1,res);
    recursion(root->left,level+1,res);
}
vector<int> rightSideView(Node* root)
{
    vector<int> res;
    recursion(root,0,res);
    return res;
}
//Time complexity is O(N)
//Space complexity is O(N)
