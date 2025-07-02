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
vector<int> inOrder(Node *root)
{
    vector<int> inorder;
    stack<Node*> st;
    if(root==NULL)
    {
        return inorder;
    }
    Node* node=root;
    while(true)
    {
        if(node!=NULL)
        {
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty()==true)
            {
                break;
            }
            node=st.top();
            st.pop();
            inorder.push_back(node->data);
            node=node->right;
        }
    }
    return inorder;
}