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
    node *newhead = new node(val);
    if (head == nullptr)
    {
        head = newhead;
        return;
    }
    newhead->next = head;
    head = newhead;
}

void InsertAtTail(node *&head, int val)
{
    if (head == nullptr)
    {
        InsertAtHead(head, val);
        return;
    }
    node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    node *newhead = new node(val);
    temp->next = newhead;
}

void Display(node *head)
{
    node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "Null" << endl;
}

node *Reverse(node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    node *prev = nullptr, *curr = head, *next = nullptr;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

node *Fold(node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    node *slow = head, *fast = head->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = Reverse(slow->next);
    slow->next = nullptr;
    slow = head;
    node *Tail = head;
    slow = slow->next;
    int i = 1;
    while (slow || fast)
    {
        if (i % 2 == 0)
        {
            Tail->next = slow;
            slow = slow->next;
            Tail = Tail->next;
        }
        else
        {
            Tail->next = fast;
            fast = fast->next;
            Tail = Tail->next;
        }
        i++;
    }
    Tail->next = nullptr;
    return head;
}

node *Unfold(node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    node *first = nullptr, *last = nullptr;
    node*n1=nullptr,*n2=nullptr;
    node *temp = head;
    int i = 0;
    while (temp != nullptr)
    {
        if (i % 2 == 0)
        {
            if (first != nullptr)
            {
                first->next = temp;
                first = first->next;
            }
            else
            {
                first = temp;
                n1=first;
            }
            temp = temp->next;
        }
        else
        {
            if (last != nullptr)
            {
                last->next = temp;
                last = last->next;
            }
            else
            {
                last = temp;
                n2=last;
            }
            temp = temp->next;
        }
        i++;
    }
    n2=Reverse(n2);
    first->next=n2;
    return n1;
}

int main()
{
    node *head = nullptr;
    InsertAtHead(head, 1);
    InsertAtHead(head, 0);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    Display(head);
    Display(Fold(head));
    Display(Unfold(head));
    return 0;
}