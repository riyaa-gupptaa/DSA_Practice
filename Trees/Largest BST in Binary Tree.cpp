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
//largest<node<smallest
class NodeValue{
    public:
    int maxNode,minNode,maxSize;
    NodeValue(int minNode,int maxNode,int maxSize)
    {
        this->maxNode=maxNode;
        this->minNode=minNode;
        this->maxSize=maxSize;
    }
};
class Solution{
private:
NodeValue largestBSTSubtreeHelper(Node* root)
{
    if(!root)
    {
        return NodeValue(INT_MAX,INT_MIN,0);
    }
    auto left=largestBSTSubtreeHelper(root->left);
    auto right=largestBSTSubtreeHelper(root->right);
    if(left.maxNode<root->val && root->val<right.minNode)
    {
        return NodeValue(min(root->val,left.minNode),max(root->val,right.maxNode),left.maxSize+right.maxSize+1);
    }
    return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
}
    public:
int largestBst(Node *root)
{
    return largestBSTSubtreeHelper(root).maxSize;
}
};
//Time complexity is O(N)
//Space complexity is O(1)