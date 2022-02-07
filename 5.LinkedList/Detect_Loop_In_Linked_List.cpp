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

void Cycle(node*head,int k)
{
    if(head==nullptr)return;
    node*temp=head;
    while(temp->next&&k--)
    {
        temp=temp->next;
    }
    node*Tail=temp;
    while(Tail->next)
    {
        Tail=Tail->next;
    }
    Tail->next=temp;
}

int Detect_Loop(node*head)
{
    if(head==nullptr)return 0;
    node*last=head->next;
    while(last!=nullptr)
    {
        node*temp=head;
        do{
            if(last->next==temp->next)
            {
                return 1;
            }
            else
            {
                temp=temp->next;
            }
        }while(temp!=last);
        last=last->next;
    }
    return 0;
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
    Cycle(head,3);
    cout<<Detect_Loop(head)<<endl;
    return 0;
}