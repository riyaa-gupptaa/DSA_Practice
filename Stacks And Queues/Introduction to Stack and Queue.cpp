#include <iostream>
#include <stack>
#include <queue>
using namespace std;
// Implement stack using arrays
//  Function to push an integer into the stack.

class MyStack
{
private:
    int arr[1000];
    int top;

public:
    MyStack() { top = -1; }
    int pop();
    void push(int);
    int Top();
    int size();
};

void MyStack ::push(int x)
{
    // Your Code
    if (top >= 999)
    {
        return;
    }
    arr[++top] = x;
}
int MyStack::Top()
{
    if (top == -1)
    {
        return 0;
    }
    return arr[top];
}
// Function to remove an item from top of the stack.
int MyStack ::pop()
{
    // Your Code
    if (top == -1)
    {
        return -1;
    }
    return arr[top--];
}
int MyStack::size()
{
    return top + 1;
}
// Time complexity is O(1)
// Space complexity is O(size of array)

// Implementing Queues using array
class Queue
{
    vector<int> q;

public:
    bool isEmpty() { return q.empty(); }

    void enqueue(int x)
    {
        q.push_back(x);
    }

    void dequeue()
    {
        if (!isEmpty())
            q.erase(q.begin());
    }

    int getFront()
    {
        return isEmpty() ? -1 : q.front();
    }

    void display()
    {
        for (int x : q)
            cout << x << " ";
        cout << "\n";
    }
};

// Stack using LinkedList
class StackNode
{
public:
    int data;
    StackNode *next;
    StackNode(int x)
    {
        data = x;
        next = nullptr;
    }
};
class MyStack
{
private:
    StackNode *top;
    int size = 0;

public:
    void push(int x)
    {
        // code here
        StackNode *temp = new StackNode(x);
        temp->next = top;
        top = temp;
        size = size + 1;
    }

    int pop()
    {
        StackNode *temp = top;
        top = top->next;
        delete temp;
        size = size - 1;
        // code here
    }
    int Top()
    {
        return top->data;
    }
    int size()
    {
        return size;
    }
    MyStack() { top = NULL; }
};

// Queue using Linked list
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue
{
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() { front = rear = NULL; }
};

// Function to push an element into the queue.
void MyQueue::push(int x)
{
    // Your Code
    QueueNode *temp = new QueueNode(x);
    if (front == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

// Function to pop front element from the queue.
int MyQueue ::pop()
{
    // Your Code
    if (front == NULL)
    {
        return 0;
    }
    QueueNode *temp = front;
    front = front->next;
    if (front == NULL)
    {
        rear = NULL; // Fix: update rear if queue becomes empty
    }
    delete temp;
}
// Time complexity is O(1)

// Stack using Queue
class Stack
{

    queue<int> q;

public:
    void push(int data)
    {
        int s = q.size();
        q.push(data);
        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    void pop()
    {
        if (q.empty())
        {
            return;
        }
        else
        {
            q.pop();
        }
    }
    int top()
    {
        return q.empty() ? -1 : q.front();
    }
    int size()
    {
        return q.size();
    }
};

// Implement Queue using Stack
struct Queue
{
    stack<int> s;

    // Enqueue an item to the queue
    void enqueue(int x)
    {
        s.push(x);
    }

    // Dequeue an item from the queue
    int dequeue()
    {
        if (s.empty())
        {
            return -1;
        }

        // pop an item from the stack
        int x = s.top();
        s.pop();

        // if stack becomes empty, return
        // the popped item
        if (s.empty())
            return x;

        // recursive call
        int item = dequeue();

        // push popped item back to the stack
        s.push(x);

        // return the result of dequeue() call
        return item;
    }
};