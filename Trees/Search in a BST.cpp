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
Node* searchBST(Node* root, int val)
{
    while(root)
    {
        if(root->data==val)
        {
            return root;
        }
        else if(val<root->data)
        {
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return nullptr;
}