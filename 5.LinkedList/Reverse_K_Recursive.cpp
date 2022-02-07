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

node* reverse(node*head,int k)
{
    node*prev=nullptr,*next=nullptr,*curr=head;
    int count=0;
    while(curr!=nullptr&&count<k)
    {
        count++;
                    next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
    }   

    if(next!=nullptr)
    {
        head->next=reverse(next,k);
    }
    return prev;
}

int main()
{
    node*head=nullptr;
    InsertAtHead(head,1);
    InsertAtHead(head,2);
    InsertAtHead(head,3);
    InsertAtHead(head,4);
    InsertAtHead(head,5);
    
    Display(head);
    
    node*newHead=reverse(head,3);

    Display(newHead);
    return 0;
}