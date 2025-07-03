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
//We will use a single stack
vector<int> allTraversal(Node* root)
{
    stack<pair<Node*,int>> st;
    st.push({root,1});
    vector<int> pre,in,post;
    if(root==NULL)
    {
        return;
    }
    while(!st.empty())
    {
        auto it=st.top();
        st.pop();
        if(it.second==1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL)
            {
                st.push({it.first->left,1});
            }
        }
        else if(it.second==2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL)
            {
                st.push({it.first->right,1});
            }
        }
        else{
            post.push_back(it.first->data);
        }
    }
}
//Time complexty is O(3N)
//Space complexity is O(2N)