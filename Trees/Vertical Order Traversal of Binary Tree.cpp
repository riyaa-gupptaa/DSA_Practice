#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<set>
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
//Smaller value first then greater value
//4
//2 5
//1 9 10 6
//3
//10
//We need to store O(node,v,level)
vector<vector<int>> verticalTraversal(Node* root)
{
    map<int,map<int,multiset<int>>> nodes;
    queue<pair<Node*,pair<int,int>>> todo;
    todo.push({root, {0, 0}});
    while(!todo.empty())
    {
        auto p=todo.front();
        todo.pop();
        Node* node=p.first;
        int x=p.second.first,y=p.second.second;
        nodes[x][y].insert(node->data);
        if(node->left)
        {
            todo.push({node->left,{x-1,y+1}});
        }
        if(node->right)
        {
            todo.push({node->right,{x+1,y+1}});
        }
    }
    vector<vector<int>> ans;
    for(auto n:nodes)
    {
        vector<int> col;
        for(auto q:n.second)
        {
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
//Time complexity is O(N)logN
//Space complexity is O(N)+O(N)