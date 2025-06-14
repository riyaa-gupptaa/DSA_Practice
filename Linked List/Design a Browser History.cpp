#include<iostream>
using namespace std;
class Node {
    public:
        string data;
        Node* prev;
        Node* next;
    
        Node(string x) {
            data = x;
            prev = nullptr;
            next = nullptr;
        }
};
class BrowserHistory {
    public:
    Node* current;
    BrowserHistory(string homepage)
    {
        current=new Node(homepage);
    }
    void visit(string url)
    {
        Node* newNode=new Node(url);
        current->next=newNode;
        newNode->prev=current;
        current=newNode;
    }
    string back(int step)
    {
        while(step)
        {
            if(current->prev)
            {
            current=current->prev;
            }
            else{
                break;
            }
            step--;
        }
        return current->data;
    }
    string forward(int step)
    {
        while(step)
        {
            if(current->next)
            {
                current=current->next;
            }
            else{
                break;
            }
            step--;
        }
        return current->data;
    }
};
//Time complexity is O(steps)
