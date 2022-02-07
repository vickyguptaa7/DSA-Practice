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

int Count_Node(node*head)
{
    node*temp=head;
    int count=0;
    while(temp!=nullptr)
    {
        temp=temp->next;
    }
    return count;
}

node* Add_2_Linked_List(node*head1,node*head2)
{
    head1=reverse(head1);
    head2=reverse(head2);

    node*newHead=nullptr;   
    node*temp1=head1,*temp2=head2;
    int carry=0;
    while(temp1||temp2||carry!=0)
    {
        int sum=0;
        if(temp1)
        {
            sum+=temp1->data;
            temp1=temp1->next;
        }
        if(temp2)
        {
            sum+=temp2->data;
            temp2=temp2->next;
        }
        sum+=carry;
        InsertAtHead(newHead,sum%10);
        carry=sum/10;
    }
    head1=reverse(head1);
    head2=reverse(head2);
    return newHead;
}

int main()
{
    node *head1 = nullptr;
    InsertAtTail(head1, 1);
    InsertAtTail(head1, 2);
    InsertAtTail(head1, 3);
    InsertAtTail(head1, 4);
    node*head2=nullptr;
    InsertAtTail(head2, 5);
    InsertAtTail(head2, 6);
    InsertAtTail(head2, 9);

    Display(head1);
    Display(head2);
    node*newHead=Add_2_Linked_List(head2,head1);
    Display(newHead);
    return 0;
}