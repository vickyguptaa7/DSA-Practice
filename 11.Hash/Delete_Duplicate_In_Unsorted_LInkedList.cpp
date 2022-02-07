#include<iostream>
#include<unordered_set>
using namespace std;

struct node
{
    int data;
    node*next;
    node(int key)
    {
        data=key;
        next=nullptr;
    }
};
void InsertAtHead(node*&head,int key)
{
    node*newnode=new node(key);
    newnode->next=head;
    head=newnode;
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

void Remove_Duplicate(node*&head)
{
    unordered_set<int>uset;
    node*temp=head;
    uset.insert(temp->data);
    while(temp->next!=nullptr)
    {
        if(uset.find(temp->next->data)!=uset.end())
        {
            node*todelete=temp->next;
            temp->next=temp->next->next;
            delete todelete;
            uset.insert(temp->data);
        }
        else
        {
            uset.insert(temp->next->data);
            temp=temp->next;
        }
    }
}

int main(){
    node*head=nullptr;
    InsertAtHead(head,1);
    InsertAtHead(head,1);
    InsertAtHead(head,3);
    InsertAtHead(head,4);
    InsertAtHead(head,5);
    InsertAtHead(head,1);
    InsertAtHead(head,6);
    Display(head);
    Remove_Duplicate(head);
    Display(head);
    return 0;
}