#include <iostream>
using namespace std;
struct node
{
    int data;
    node*prev;
    node *next;
    node(int val)
    {
        data = val;
        prev=nullptr;
        next = nullptr;
    }
};

void InsertAtHead(node *&head, int val)
{
    node *n = new node(val);
    if(head)
    head->prev=n;
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
    n->prev=temp;
    temp->next = n;
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

node* Delete(node*head,int k=7)
{
    if(!head)return head;
    
    while(head->data==k)
    {
        head=head->next;
        delete (head->prev);
        head->prev=nullptr;
    }

    node*temp=head;
    while(temp)
    {
        if(temp->data==k)
        {
            temp=temp->next;
            node*todelete=temp->prev;
            temp->prev=temp->prev->prev;
            temp->prev->next=temp;
        }
        else
        {
            temp=temp->next;
        }
    }
    return head;
}

node *reverse(node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    node *prev = nullptr,*curr = head;
    while (curr != nullptr)
    {
        prev=curr->prev;
        curr->prev=curr->next;
        curr->next=prev;
        curr=curr->prev;
    }
    return prev->prev;
}

int Count_Node(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        temp = temp->next;
    }
    return count;
}

int main()
{
    node *head = nullptr;
    InsertAtTail(head, 7);
    InsertAtTail(head, 2);
    InsertAtTail(head, 6);
    InsertAtTail(head, 9);
    InsertAtTail(head, 0);
    InsertAtTail(head, 7);
    InsertAtTail(head, 9);

    Display(head);
    node*newHead=reverse(head);
    Display(newHead);
    return 0;
}