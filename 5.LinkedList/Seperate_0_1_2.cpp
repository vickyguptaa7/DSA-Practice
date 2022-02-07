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

node *Sort_0_1_2(node *head)
{
    node *ptr = head;
    node *os = nullptr, *oe = nullptr;
    node *s1 = nullptr, *e1 = nullptr;
    node *s2 = nullptr, *e2 = nullptr;

    while (ptr)
    {
        if (ptr->data == 0)
        {
            if (!os)
            {
                os = ptr;
                oe = os;
            }
            else
            {
                oe->next = ptr;
                oe = oe->next;
            }
        }
        else if (ptr->data == 1)
        {
            if (!s1)
            {
                s1 = ptr;
                e1 = s1;
            }
            else
            {
                e1->next = ptr;
                e1 = e1->next;
            }
        }
        else if (ptr->data == 2)
        {
            if (!s2)
            {
                s2 = ptr;
                e2 = s2;
            }
            else
            {
                e2->next = ptr;
                e2 = e2->next;
            }
        }
        ptr = ptr->next;
    }
    if(!os&&!s1){e2->next=nullptr; return s2;}
    if(!os&&!s2){e1->next=nullptr; return s1;}
    if(!s1&&!s2){oe->next=nullptr; return os;}

    if(!os){e1->next=s2; e2->next=nullptr; return s1;}
    if(!s1){oe->next=s2; e2->next=nullptr; return os;}
    if(!s2){oe->next=s1; e1->next=nullptr; return os;}
    
    oe->next = s1;
    e1->next = s2;
    e2->next = nullptr;
    return os;
}

int main()
{
    node *head = nullptr;
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 2);
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 0);
    InsertAtTail(head, 2);
    InsertAtTail(head, 2);
    

    Display(head);
    node *newHead = Sort_0_1_2(head);
    Display(newHead);
    return 0;
}