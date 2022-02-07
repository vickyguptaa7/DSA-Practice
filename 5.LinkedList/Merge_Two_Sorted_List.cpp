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

node *Merge_List(node *head1, node *head2)
{
    if(!head1)return head2;
    if(!head2)return head1;
    
    node *newHead = nullptr;
    
    if(head1->data>head2->data)
    {
        newHead=head2;
        head2=head2->next;
    }
    else
    {
        newHead=head1;
        head1=head1->next;
    }
    
    node *temp1 = head1, *temp2 = head2, *temp3 = newHead;
    while (temp1 && temp2)
    {
        if (temp1->data > temp2->data)
        {
            temp3->next = temp2;
            temp2 = temp2->next;
            temp3 = temp3->next;
            temp3->next = nullptr;
        }
        else
        {
            temp3->next = temp1;
            temp1 = temp1->next;
            temp3 = temp3->next;
            temp3->next = nullptr;
        }
    }
    if(temp1)
    {
        temp3->next = temp1;

    }

    if(temp2)
    {
        temp3->next = temp2;
    }
    return newHead;
}

int main()
{
    node *head1 = nullptr;
    InsertAtTail(head1, 1);
    InsertAtTail(head1, 2);
    InsertAtTail(head1, 6);
    InsertAtTail(head1, 9);
    node *head2 = nullptr;
    InsertAtTail(head2, 0);
    InsertAtTail(head2, 7);
    InsertAtTail(head2, 9);

    Display(head1);
    Display(head2);
    node *newHead = Merge_List(head2, head1);
    Display(newHead);
    return 0;
}