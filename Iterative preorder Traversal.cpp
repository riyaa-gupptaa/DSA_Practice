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
vector<int> preOrder(Node *root)
{
    vector<int> pre;
    if(root==NULL)
    {
        return pre;
    }
    stack<Node*> st;
    st.push(root);
    while(!st.empty())
    {
        root=st.top();
        st.pop();
        pre.push_back(root->data);
        if(root->right!=NULL)
        {
            st.push(root->right);
        }
        if(root->left!=NULL)
        {
            st.push(root->left);
        }
    }
    return pre;
}
//Time complexity is O(N)