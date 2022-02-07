#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node*bottom;
    node(int val)
    {
        data = val;
        next = nullptr;
        bottom=nullptr;
    }
};

void InsertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void InsertAtTail(node *&head, int val)
{
    if (head == nullptr)
    {
        InsertAtHead(head, val);
        return;
    }
    node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    node *n = new node(val);
    temp->next = n;
}

void InsertAtBottom(node*&head,int val)
{
    if(!head)return ;
    node*temp=head;
    while(temp->next)
    {
        temp=temp->next;
    }
    while(temp->bottom)
    {
        temp=temp->bottom;
    }
    node*n=new node(val);
    temp->bottom=n;
}

void Display(node *head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "Null" << endl;
}

void Display_Bottom(node *head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->bottom;
    }
    cout << "Null" << endl;
}

void Display_Flatten(node*head)
{
    if(!head)return;
    node*ptr1=head;
    while(ptr1)
    {
        node*ptr2=ptr1;
        while(ptr2)
        {
            cout<<ptr2->data<<"->";
            ptr2=ptr2->bottom;
        }
        cout<<"Null";
        cout<<endl<<"|"<<endl<<"v"<<endl;
        ptr1=ptr1->next;
    }
    cout<<"Null"<<endl;
}


node* Merge_List(node*head1,node*head2)
{
    if(!head1)return head2;
    if(!head2)return head1;

    node*merge=nullptr;
    if(head1->data<head2->data)
    {
        merge=head1;
        head1=head1->bottom;
    }
    else
    {
        merge=head2;
        head2=head2->bottom;
    }
    node*p1=head1,*p2=head2,*t=merge;

    while(p1&&p2)
    {
        if(p1->data>p2->data)
        {
            merge->bottom=p2;
            p2=p2->bottom;
            merge=merge->bottom;
        }
        else
        {
            merge->bottom=p1;
            p1=p1->bottom;
            merge=merge->bottom;
        }
    }
    while(p1)
    {
                    merge->bottom=p1;
            p1=p1->bottom;
            merge=merge->bottom;
    }
    while(p2)
    {
                    merge->bottom=p2;
            p2=p2->bottom;
            merge=merge->bottom;
    }
    return t;
}

node* Merge_Flatten(node*head)
{
    if(!head||!head->next)return head;
    node*temp=head;
    node*Answer=nullptr;
    while(temp)
    {
        Answer= Merge_List(Answer,temp);
        Display_Bottom(Answer);
        temp=temp->next;
    }
    return Answer;
}
int main()
{
    node *head = nullptr;
    InsertAtTail(head, 5);
    InsertAtBottom(head,7);
    InsertAtBottom(head,8);
    InsertAtBottom(head,30);
    
    InsertAtTail(head, 10);
    InsertAtBottom(head,20);
    
    InsertAtTail(head, 19);
    InsertAtBottom(head,22);
    InsertAtBottom(head,50);
    

    InsertAtTail(head, 28);
    InsertAtBottom(head,30);
    InsertAtBottom(head,35);
    InsertAtBottom(head,40);
    InsertAtBottom(head,45);

    //Display_Flatten(head);
    Display_Bottom(Merge_Flatten(head));
    return 0;
}