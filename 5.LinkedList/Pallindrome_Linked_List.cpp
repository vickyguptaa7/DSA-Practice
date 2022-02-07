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

bool Pallindrome(node*head)
{
    if(!head&&!head->next)return 1;
    node*slow=head;
    node*fast=head->next;
    while(fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=reverse(slow->next);
    slow=slow->next;
    fast=head;
    bool chk=true;
    while(slow)
    {
        if(slow->data!=fast->data)
        {
            chk=false;
            break;
        }
        slow=slow->next;
        fast=fast->next;
    }
    // Code To Change The Linked List To The Given Order
    // slow=head;
    // fast=head;
    // while(fast&&fast->next)
    // {
    //     slow=slow->next;
    //     fast=fast->next->next;
    // }
    // slow->next=reverse(slow->next);
    return chk;
}

int main()
{
    node *head = nullptr;
    InsertAtTail(head, 9);
    InsertAtTail(head, 2);
    InsertAtTail(head, 1);
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 9);

    Display(head);
    cout<<Pallindrome(head)<<endl;
    Display(head);
    return 0;
}