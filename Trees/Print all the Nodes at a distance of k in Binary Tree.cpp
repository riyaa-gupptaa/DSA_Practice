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
//BFS Traversal
void markParents(Node* root,unordered_map<Node*,Node*> &parent_track,Node* target)
{
    queue<Node*> queue;
    queue.push(root);
    while(!queue.empty())
    {
        Node* current=queue.front();
        queue.pop();
        if(current->left)
        {
            parent_track[current->left]=current;
            queue.push(current->left);
        }
        if(current->right)
        {
            parent_track[current->right]=current;
            queue.push(current->right);
        }
    }
}
vector<int> distanceK(Node* root, Node* target, int k)
{
    unordered_map<Node*,Node*> parent_track;
    markParents(root,parent_track,target);
    unordered_map<Node*,bool> visited;
    queue<Node*> queue;
    queue.push(target);
    visited[target]=true;
    int curr_level=0;
    while(!queue.empty())
    {
        int size=queue.size();
        if(curr_level++ == k)
        {
            break;
        }
        for(int i=0;i<size;i++)
        {
            Node* current=queue.front();
            queue.pop();
            if(current->left && !visited[current->left])
            {
                queue.push(current->left);
                visited[current->left]=true;
            }
            if(current->right && !visited[current->right])
            {
                queue.push(current->right);
                visited[current->right]=true;
            }
            if(parent_track[current] && !visited[parent_track[current]])
            {
                queue.push(parent_track[current]);
                visited[parent_track[current]]=true;
            }
        }
    }
    vector<int> result;
    while(!queue.empty())
    {
        Node* current=queue.front();
        queue.pop();
        result.push_back(current->data);
    }
    return result;
}
//Time complexity is O(N)+O(N)
//Space complexity is O(1)