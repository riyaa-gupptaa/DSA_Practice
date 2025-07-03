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
vector<int> postOrder(Node* root)
{
    vector<int> res;
    if(!root)
    {
        return res;
    }
    stack<Node*> s;
    s.push(root);
    while(!s.empty())
    {
        Node* temp=s.top();
        s.pop();
        res.push_back(temp->data);
        if(temp->left)
        {
            s.push(temp->left);
        }
        if(temp->right)
        {
            s.push(temp->right);
        }
    }
    reverse(res.begin(),res.end());
    return res;
}
//Time complexity is O(2N)
//Space complexity is O(N)