#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *random;
    node(int val)
    {
        data = val;
        next = nullptr;
        random=nullptr;
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
node*Reverse(node*head)
{
    if(!head||!head->next)return head;
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

int main()
{
    node *head = nullptr;
    InsertAtTail(head, 12);
    InsertAtTail(head, 15);
    InsertAtTail(head, 10);
    InsertAtTail(head, 11);
    InsertAtTail(head, 5);
    InsertAtTail(head, 6);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    

    Display(head);

    return 0;
}