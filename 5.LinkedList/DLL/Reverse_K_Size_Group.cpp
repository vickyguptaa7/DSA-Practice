#include <iostream>
using namespace std;
struct node
{
    int data;
    node *prev;
    node *next;
    node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

void InsertAtHead(node *&head, int val)
{
    node *n = new node(val);
    if (head)
        head->prev = n;
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
    n->prev = temp;
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

node *Delete(node *head, int k = 7)
{
    if (!head)
        return head;

    while (head->data == k)
    {
        head = head->next;
        delete (head->prev);
        head->prev = nullptr;
    }

    node *temp = head;
    while (temp)
    {
        if (temp->data == k)
        {
            temp = temp->next;
            node *todelete = temp->prev;
            temp->prev = temp->prev->prev;
            temp->prev->next = temp;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

node *reverse(node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    node *prev = nullptr, *curr = head;
    while (curr != nullptr)
    {
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
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

node *Reverse(node *head, int k = 1)
{
    if (!head || !head->next)
        return head;
    node *curr = head, *prev = nullptr;
    node *newHead=nullptr,*Tail_1=nullptr,*Tail_2=head;
    int count = Count_Node(head);
    while (count >= k)
    {
        while (curr != nullptr)
        {
            prev = curr->prev;
            curr->prev = curr->next;
            curr->next = prev;
            curr = curr->prev;
        }
        if(!newHead)newHead=prev->prev;
        if(Tail_1){
            Tail_1->next=prev->prev;
            prev->prev->prev=Tail_1;
            }
        Tail_2->next=curr;
        curr->prev=Tail_2;
        Tail_1=Tail_2;
        prev=curr;
        count-=k;
    }

    return newHead;
}

int main()
{
    node *head = nullptr;
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    // InsertAtTail(head, 5);
    // InsertAtTail(head, 6);
    // InsertAtTail(head, 7);

    Display(head);
    Display(Reverse(head));
    return 0;
}