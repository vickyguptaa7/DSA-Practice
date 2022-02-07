#include<iostream>
using namespace std;

struct node
{
    int data;
    node*next;
    node(int val)
    {
        data=val;
        next=nullptr;
    }
};

void InsertAtHead(node*&head,int val)
{
    node*n=new node(val);
    n->next=head;
    head=n;
}

void InsertAtTail(node*&head,int val)
{
    if(head==nullptr)
    {
        InsertAtHead(head,val);
        return;
    }
    node*temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    node*n=new node(val);
    temp->next=n;
}

void Display(node*head)
{
    node*temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"Null"<<endl;
}

void Sorted_Insert(node*&head,int val)
{
    if(head==nullptr||head->data>val)
    {
        InsertAtHead(head,val);
        return;
    }
    
    node*temp=head;
    while(temp->next!=nullptr&&temp->next->data<=val)
    {
        temp=temp->next;
    }
    node*n=new node(val);
    n->next=temp->next;
    temp->next=n;
}

int main(){
    node*head=nullptr;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    InsertAtTail(head,7);
    
    Display(head);
    Sorted_Insert(head,100);
    Display(head);
    return 0;
}