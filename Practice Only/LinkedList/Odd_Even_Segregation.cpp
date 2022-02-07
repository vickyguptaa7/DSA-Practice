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

node* Odd_Even(node*head)
{
    if(!head&&!head->next)
    {
        return head;
    }
    node*odd=nullptr,*even=nullptr;
    node*i=head,*io=nullptr,*ie=nullptr;

    while(i)
    {
        if(i->data%2)
        {
            if(!odd)
            {
                odd=i;
                io=i;
                i=i->next;
                continue;
            }
            io->next=i;
            io=io->next;
            i=i->next;
            io->next=nullptr;
        }
        else
        {
            if(!even)
            {
                even=i;
                ie=i;
                i=i->next;
                continue;
            }
            ie->next=i;
            ie=ie->next;
            i=i->next;
            ie->next=nullptr;
        }
    }
    if(ie)
    {
       ie->next=odd;
       return even; 
    }
    else
    {
        return odd;
    }
}

int main(){
    node*head=nullptr;
    // InsertAtTail(head,1);
    // InsertAtTail(head,3);
    // InsertAtTail(head,5);
    InsertAtTail(head,2);
    InsertAtTail(head,4);
    InsertAtTail(head,6);
     
    Display(head);

    Display(Odd_Even(head));
    
    return 0;
}
