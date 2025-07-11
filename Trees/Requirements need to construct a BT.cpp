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
bool isPossible(int a, int b)
{
    if ((a == 2 && (b == 1 || b == 3)) ||
        ((a == 1 || a == 3) && b == 2))
    {
        return true;
    }
    return false;
}