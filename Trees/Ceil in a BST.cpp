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
int findCeil(Node* root, int input) {
   int ceil=-1;
   while(root)
   {
    if(root->data==input)
    {
        ceil=root->data;
        return ceil;
    }
    if(input>root->data)
    {
        root=root->right;
    }
    else{
        ceil=root->data;
        root=root->left;
    }
   }
   return ceil;
}