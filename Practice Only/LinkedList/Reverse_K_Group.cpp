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

void InsertAtTail(node* &head,int val)
{
    node*n=new node(val);
    if(!head)
    {
        n->next=head;
        head=n;
        return;
    }
    node*temp=head;
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=n;
}

void Display(node*head)
{
    node*temp=head;
    while(temp)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"Null"<<endl;
}

node* Reverse_K(node*head,int k=3) //recursive
{
    if(!head||!head->next)return nullptr;
    int i=k;
    node*prev=nullptr,*curr=head,*next=nullptr;
    while(i-->0&&curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head->next=Reverse_K(next,k);
    return prev;
}



int main(){
    node*head=nullptr;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    InsertAtTail(head,6);
    InsertAtTail(head,7);
    InsertAtTail(head,8);

    Display(head);
    Display(Reverse_K(head));

    return 0;
}
