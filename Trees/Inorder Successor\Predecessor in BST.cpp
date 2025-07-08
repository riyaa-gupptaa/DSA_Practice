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
Node* inorderSuccessor(Node* root,int key)
{
    Node* successor=NULL;
    while(root!=NULL)
    {
        if(key>=root->data)
        {
            root=root->right;
        }
        else{
            successor=root;
            root=root->left;
        }
    }
    return successor;
}
Node* inorderPre(Node* root,int key)
{
    Node* pre=NULL;
    while(root!=NULL)
    {
        if(key<=root->data)
        {
            root=root->left;
        }
        else{
            pre=root;
            root=root->right;
        }
    }
    return pre;
}
vector<Node*> findPreSuc(Node* root, int key)
{
    vector<Node*> ans;
    Node* succ=inorderSuccessor(root,key);
    Node* pre=inorderPre(root,key);
    ans.push_back(succ);
    ans.push_back(pre);
    return ans;
}
