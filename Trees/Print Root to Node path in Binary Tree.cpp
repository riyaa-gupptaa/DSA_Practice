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
bool getPath(Node *root,vector<int> &arr,int x)
{
    if(!root)
    {
        return false;
    }
    arr.push_back(root->data);
    if(getPath(root->left,arr,x)||getPath(root->right,arr,x))
    {
        return true;
    }
    arr.pop_back();
    return false;
}
vector<int> binaryTreePaths(Node* root,int B)
{
    vector<int> arr;
    if(root==NULL)
    {
        return arr;
    }
    getPath(root,arr,B);
    return arr;
}
//Time complexity is O(N)
//Space complexity is O(N)