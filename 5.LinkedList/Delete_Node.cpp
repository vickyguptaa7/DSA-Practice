#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = nullptr;
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

node *reverse(node *head)
{
    if (head == nullptr && head->next == nullptr)
        return head;
    node *next = nullptr, *prev = nullptr, *curr = head;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

node* Delete_Node(node*head,int val)
{
    while(head&&head->data==val)
    {
        node*todelete=head;
        head=head->next;
        delete todelete;
    }
    if(!head)return head;
    node*temp=head;
    while(temp->next)
    {
        if(temp->next->data==val)
        {
            node*todelete=temp->next;
            temp->next=temp->next->next;
            delete todelete;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}

int main()
{
    node *head = nullptr;
    InsertAtTail(head, 1);
    InsertAtTail(head, 9);
    InsertAtTail(head, 9);
    InsertAtTail(head, 9);
    InsertAtTail(head, 9);
    InsertAtTail(head, 9);
    InsertAtTail(head, 9);

    Display(head);
    head=Delete_Node(head,9);
    Display(head);
    return 0;
}