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
        }
        else
        {
            temp3->next = temp1;
            temp1 = temp1->next;
            temp3 = temp3->next;
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

node* Mid_LL(node*head)
{
    if(!head||!head->next)return head;
    node*slow=head;
    node*fast=head->next;
    while(fast&&fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

node* Merge_Sort(node*head)
{
    if(!head||!head->next)return head;

    node*mid=Mid_LL(head);
    node*first=head;
    node*second=mid->next;
    mid->next=nullptr; 
    first=Merge_Sort(first);
    second=Merge_Sort(second);

    return Merge_List(first,second);
}

int main()
{
    node *head = nullptr;
    InsertAtTail(head, 11);
    InsertAtTail(head, 6);
    InsertAtTail(head,2);
    InsertAtTail(head, 9);
    InsertAtTail(head, 0);
    InsertAtTail(head, 7);

    // node*wow=nullptr;
    //     InsertAtTail(head,1);
    // InsertAtTail(head, 4);
    // InsertAtTail(head, 5);
    // InsertAtTail(head, 7);

    Display(head);
    node *newHead = Merge_Sort(head);
    Display(newHead);
    return 0;
}