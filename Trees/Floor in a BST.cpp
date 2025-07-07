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
int floor(Node* root, int x)
{
    int floor=-1;
    while(root)
    {
        if(root->data==x)
        {
            floor=root->data;
            return floor;
        }
        if(x>root->data)
        {
            floor=root->data;
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return floor;
}