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

node *Add_One(node *head)
{
    head = reverse(head);
    node *temp = head;
    int rem = 0;
    while (temp)
    {
        if (temp->data < 9)
        {
            rem = 0;
            temp->data++;
            break;
        }
        else if (temp->next == nullptr && temp->data == 9)
        {
            temp->data = 0;
            node *n = new node(1);
            temp->next = n;
            break;
        }
        else
        {
            temp->data = 0;
            temp = temp->next;
        }
    }

    head = reverse(head);
    return head;
}

int main()
{
    node *head = nullptr;
    // InsertAtTail(head, 1);
    // InsertAtTail(head, 2);
    // InsertAtTail(head, 3);
    // InsertAtTail(head, 4);
    // InsertAtTail(head, 5);
    // InsertAtTail(head, 6);
    InsertAtTail(head, 9);

    Display(head);
    head = Add_One(head);
    Display(head);
    return 0;
}