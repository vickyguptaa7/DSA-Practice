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

void Cycle(node*head)
{
    if(head==nullptr)return;
    node*temp=head;
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=head;
}

void Display_Cycle(node*head)
{
    if(head==nullptr)return;
    node*temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}

void Cycle_Head(node*head,int val)
{
     node*n=new node(val);
    if(head==nullptr){
        n->next=n;
        }
    node*temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}

node* Cycle_Head_Efficiently(node*head,int val)
{
    node*temp=head;
    node*n=new node(val);
    n->next=temp->next;
    temp->next=n;
    int data=temp->data;
    temp->data=temp->next->data;
    temp->next->data=data;
    head=head->next;
    return head;
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
    Cycle(head);
    head=Cycle_Head_Efficiently(head,8);
    Display_Cycle(head);
    return 0;
}