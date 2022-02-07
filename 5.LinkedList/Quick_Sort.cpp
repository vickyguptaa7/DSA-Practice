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

node *Tail(node *head,node*tail=nullptr) // Return The Tail Prev Pointer 
{
    if (head==tail || head->next==tail)
        return head;
    node *temp = head;
    while (temp->next!=tail)
    {
        temp = temp->next;
    }
    return temp;
}

node *Partition(node *&head) // Partition The Linked List Arroud Head
{
    if (!head || !head->next)
        return head;
    node *pivot = head;
    node *ptr = head->next;
    head->next = nullptr;
    node *pptr = pivot;
    while (ptr)
    {
        if (ptr->data >= pivot->data)
        {
            pptr->next = ptr;
            ptr = ptr->next;
            pptr = pptr->next;
            pptr->next = nullptr;
        }
        else
        {
            node *temp = ptr;
            ptr = ptr->next;
            temp->next = head;
            head = temp;
        }
    }
    return pivot;
}

node *Quick_Sort(node *head)
{
    if (!head || !head->next)
        return head;

    node *pivot = Partition(head); // We Have Stored Pivot 
    node *First = nullptr;         // Stores The First Half Element Of The Pivot (Before Pivot)
    node *Second = nullptr;        // Stores The Second Half Element Of The Pivot (After Pivot)
                                   // Both Do Not Include The Pivot
    if(head!=pivot)  // If Our Pivot Is Not Equal To Head Then We Point First On The Head Other Wise First Will Point On Nullptr
    {
        First = head;   
        node *temp = Tail(head,pivot); 
        temp->next = nullptr;       // Breaking The Link Between First And Pivot
    }
    Second=pivot->next;   
    pivot->next=nullptr; // Breaking The Link Between Pivot And Second

    First = Quick_Sort(First);   // Sort The First Half
    Second = Quick_Sort(Second); // Sort The Second Half

    if (First)                   // if first is not nullptr
    {
        node *temp = Tail(First); // We Find The Tail Of The First
        temp->next = pivot;       // And Join It Wiht Pivot
        head=First;               // And  Head Points To First;
    }

    if (Second)  // If Second Is Not Nullptr  
    {
        pivot->next = Second; //  Then We Join Pivot And Nullptr
    }
    return head;   // In Last We Return The Head
}

int main()
{
    node *head = nullptr;
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    InsertAtTail(head, 6);
    InsertAtTail(head, 7);
    InsertAtTail(head, 8);
    InsertAtTail(head, 9);
       

    Display(head);
    //node *newHead = Partition(head);
    node*newHead=Quick_Sort(head);
    Display(newHead);
    return 0;
}
