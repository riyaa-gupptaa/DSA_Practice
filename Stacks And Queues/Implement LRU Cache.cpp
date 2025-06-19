#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;
// We will use a doubly linked list
class Node
{
public:
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr)
    {
    }
};
class LRUCache
{
private:
    void deleteNode(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insertAtHead(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        node->next = head->next;
        head->next = node;
        node->prev = head;
        node->next->prev = node;
    }
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

public:
    int capacity = 0;
    unordered_map<int, Node *> mp;
    LRUCache(int capacity)
    {
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
        mp.clear();
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            deleteNode(node);
            insertAtHead(node);
            return node->val;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            // key exists update
            Node *node = mp[key];
            node->val = value;
            deleteNode(node);
            insertAtHead(node);
        }
        else
        {
            Node *node = new Node(key, value);
            // key doesnt exist add
            if (mp.size() == capacity)
            {
                // remove least recent
                Node *lru = tail->prev;
                deleteNode(lru);
                mp.erase(lru->key);
                insertAtHead(node);
                mp[key] = head->next;
            }
            else
            {
                // add
                insertAtHead(node);
                mp[key] = head->next;
            }
        }
    }
};