#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};
vector<int> postOrder(Node *root)
{
    vector<int> post;
    if(root==NULL)
    {
        return post;
    }
    stack<Node*> st1,st2;
    st1.push(root);
    while(!st1.empty())
    {
        root=st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=NULL)
        {
            st1.push(root->left);
        }
        if(root->right!=NULL)
        {
            st1.push(root->right);
        }
    }
    while(!st2.empty())
    {
        post.push_back(st2.top()->data);
        st2.pop();
    }
    return post;
}
//Time complexity is O(N)
//Space complexity is O(2N)