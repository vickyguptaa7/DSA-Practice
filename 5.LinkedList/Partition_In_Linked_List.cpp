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

node* Partition(node*head,node*tail=nullptr)
{
    if(head==tail||head->next==tail)return head;
    node*pivot=head;
    node*ptr=head->next;
    head->next=nullptr;
    node*pptr=pivot;
    while(ptr!=tail)
    {
        if(ptr->data>=pivot->data)
        {
            pptr->next=ptr;
            ptr=ptr->next;
            pptr=pptr->next;
            pptr->next=nullptr;
        }
        else
        {
            node*temp=ptr;
            ptr=ptr->next;
            temp->next=head;
            head=temp;
        }
    }
    return head;
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
    node *newHead = Partition(head);
    Display(newHead);
    return 0;
}