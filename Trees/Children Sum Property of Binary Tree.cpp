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
//[node]=[left]+[right]
void changeTree(Node* root) {
    if (root == NULL) {
        return;
    }

    int child = 0;

    if (root->left) {
        child += root->left->data;
    }
    if (root->right) {
        child += root->right->data;
    }

    // Push values down to children if current node is greater
    if (child >= root->data) {
        root->data = child;
    } else {
        if (root->left) {
            root->left->data = root->data;
        }
        if (root->right) {
            root->right->data = root->data;
        }
    }

    // Recursive call on left and right
    changeTree(root->left);
    changeTree(root->right);

    // After returning, fix the root's value to be sum of its children
    int tot = 0;
    if (root->left) {
        tot += root->left->data;
    }
    if (root->right) {
        tot += root->right->data;
    }

    // Don't change leaf nodes
    if (root->left || root->right) {
        root->data = tot;
    }
}
//Time complexity is O(N)
//Space complexity is O(H)