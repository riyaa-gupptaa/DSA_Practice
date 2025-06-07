#include<iostream>
#include<vector>
#include<map>
//Delete the head of the linked list
Node* deleteHead(Node* head)
{
    if(head==NULL)
    {
        return  head;
    }
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}

//Delete the tail of the linked list
Node* deleteTail(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return NULL;
    }
    Node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp);
    temp->next=nullptr;
    return head;
}
//Delete the kth element from the list
Node* deletek(Node* head,int k)
{
    if(head==NULL)
    {
        return head;
    }
    if(k==1)
    {
        deleteHead(head);
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL)
    {
        cnt++;
        if(cnt==k)
        {
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
//Delete on the basis of value
Node* removeValue(Node* head,int value)
{
    if(head==NULL)
    {
        return head;
    }
    if(head->data==value)
    {
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL)
    {
        if(temp->data==value)
        {
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

//Insertion at the beginning
Node* insertHead(Node* head,int val)
{
    Node* temp=new Node(val,head);
    return temp;
}
//Insertion at the end
Node* insertTail(Node* head,int val)
{
    if(head==NULL)
    {
        return new Node(val);
    }
    Node* temp=head;
    while(temp->next!=null)
    {
        temp=temp->next;
    }
    Node* newNode=new Node(val);
    temp->next=newNode;
    return head;
}
//Inserting at a given kth element
Node* insertAtPosition(Node* head,int val)
{
    if(head==NULL)
    {
        if(k==1)
        {
            return new Node(val);
        }
        else{
            return NULL;
        }
    }
    if(k==1)
    {
        Node* temp=new Node(head,val);
        return temp;
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        count++;
        if(cnt==k-1)
        {
            Node* x=new Node(val);
            x->next=temp->next;
            temp->next=x;
            return head;
        }
        temp=temp->next;
    }
    return head;
}
//Insert Before Value
Node* insertBeforeValue(Node* head,int el,int val)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->data==val)
    {
        return new Node(el,val);
    }
    Node* temp=head;
    while(temp->next!=NULL)
    {
        if(temp->next->data==val)
        {
            Node* x=new Node(el,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}