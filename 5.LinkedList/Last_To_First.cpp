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

void Last_To_First(node*&head)
{
    if(head==nullptr&&head->next==nullptr)return;

    node*l1=head,*l2=head->next;
    while(l2->next)
    {
        l2=l2->next;
        l1=l1->next;
    }
    l2->next=head;
    head=l2;
    l1->next=nullptr;
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
    Display(head);
    Last_To_First(head);
    Display(head);
    
    return 0;
}