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

void InsertAtTail(node*&head,int val)
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
    while (temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* reverse(node*head)
{
    node*prev=nullptr,*curr=head,*next=nullptr;
    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

void Unfold_LinkedList(node*head)
{
    if(!head||!head->next||!head->next->next)return;
    
    node*h2=head->next;
    node*i1=head,*i2=head->next;

    while((i1!=nullptr&&i1->next!=nullptr)&&(i2!=nullptr&&i2->next!=nullptr))
    {
        i1->next=i1->next->next;
        i2->next=i2->next->next;
        i2=i2->next;
        i1=i1->next;
    }    
    i2->next=nullptr;
    i1->next=reverse(h2);
    Display(head);
}

int main(){
    node*head=nullptr;
    InsertAtTail(head,1);
    InsertAtTail(head,4);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    Display(head);
    Unfold_LinkedList(head);
    return 0;
}