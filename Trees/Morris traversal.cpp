#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;
struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int val) {
        this->val = val;
        left = right = NULL;
    }
};
vector<int> getInOrder(Node* root)
{
    vector<int> inOrder;
    Node* curr=root;
    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
            inOrder.push_back(curr->val);
            curr=curr->right;
        }
        else{
            Node* prev=curr->left;
            while(prev->right && prev->right!=curr)
            {
                prev=prev->right;
            }   
            if(prev->right==NULL)
            {
                prev->right=curr;
                curr=curr->left;
            }
            else{
               prev->right=NULL;
                inOrder.push_back(curr->val);
                curr=curr->right;
            }
        }
    }
    return inOrder;
}
//For preorder
vector<int> preOrder(Node* root)
{
    vector<int> preOrder;
    Node* curr=root;
    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
            preOrder.push_back(curr->val);
            curr=curr->right;
        }
        else{
            Node* prev=curr->left;
            while(prev->right && prev->right!=curr)
            {
                prev=prev->right;
            }   
            if(prev->right==NULL)
            {
                prev->right=curr;
                preOrder.push_back(curr->val);
                curr=curr->left;
            }
            else{
               prev->right=NULL;
                curr=curr->right;
            }
        }
    }
    return preOrder;
}
//Time complexity is O(N)
