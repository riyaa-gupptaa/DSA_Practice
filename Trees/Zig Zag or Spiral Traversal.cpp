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
vector<vector<int>> zigzaglevel(Node* root)
{
    vector<vector<int>> result;
    if(root==NULL)
    {
        return result;
    }
    queue<Node*> q;
    q.push(root);
    bool leftToright=true;
    while(!q.empty())
    {
        int size=q.size();
        vector<int> row(size);
        for(int i=0;i<size;i++)
        {
            Node* node=q.front();
            q.pop();
            int index=leftToright?i:(size-1-i);
            row[index]=node->data;
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        leftToright=!leftToright;
        result.push_back(row);
    }
    return result;
}
//Time complexity is O(N)
//Space complexity is O(N)