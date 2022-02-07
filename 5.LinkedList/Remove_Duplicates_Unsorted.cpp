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

void Remove_Duplicate(node*head)
{
    node*i=head;
    while(i&&i->next)
    {
        node*j=i;
        while(j->next!=nullptr)
        {
            if(i->data==j->next->data)
            {
                node*todelete=j->next;
                j->next=j->next->next;
                delete todelete;
            }
            else
            {
                j=j->next;
            }
        }
        i=i->next;
    }
}

int main(){
    node*head=nullptr;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,7);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    InsertAtTail(head,6);
    InsertAtTail(head,7);
    
    
    Display(head);
    Remove_Duplicate(head);
    Display(head);
    
    return 0;
}