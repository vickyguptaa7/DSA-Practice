#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *random;
    node(int val)
    {
        data = val;
        next = nullptr;
        random = nullptr;
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
node *Reverse(node *head)
{
    if (!head || !head->next)
        return head;
    node *prev = nullptr, *curr = head, *next = nullptr;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void Delete_Linked_List(node*&head)
{
    if(!head)return;
    node*temp=head;
    while(temp)
    {
        temp=temp->next;
        free(head);
        head=temp;
    }
}

node *Multiply(node *head, int m)
{
    if (!head)
        return head;

    head = Reverse(head);
    node*ptr1=head;
    node*multi_List=nullptr;
    
    int carry = 0;

    while (ptr1 || carry)
    {
        if (ptr1)
        {
            int sum = ptr1->data * m + carry;
            carry=sum/10;
            InsertAtHead(multi_List,sum%10);
            ptr1=ptr1->next;
        }
        else
        {
            if(carry>=10)
            {
                InsertAtHead(multi_List,carry%10);
            }
            else
            {
                InsertAtHead(multi_List,carry);
            }
            carry/=10;
        }
    }
    head=Reverse(head);
    return multi_List;
}

node* Addition_Two_List(node*head1,node*head2)
{
    if(!head1)return head2;
    if(!head2)return head1;
    
    head1=Reverse(head1);
    head2=Reverse(head2);
    node*ptr1=nullptr;
    node*ptr2=nullptr;

    ptr1=head1;
    ptr2=head2;
    node*Add=nullptr;

    int carry=0;
    while(ptr1||ptr2||carry)
    {
        int sum=0;
        if(ptr1)
        {
            sum+=ptr1->data;
            ptr1=ptr1->next;
        }
        if(ptr2)
        {
            sum+=ptr2->data;
            ptr2=ptr2->next;
        }
        sum+=carry;
        carry=sum/10;
        InsertAtHead(Add,sum%10);
    }
    Delete_Linked_List(head1);
    Delete_Linked_List(head2);
    return Add;
}

node*Multiply_Two_List(node*head1,node*head2)
{
    if(!head1)return head2;
    if(!head2)return head1;

    head1=Reverse(head1);
    node*ptr1=head1;
    node*ptr2=head2;

    node*Answer=nullptr;
    int pow_ten=1;
    while(ptr1)
    {
        Answer=Addition_Two_List(Multiply(head2,ptr1->data*pow_ten),Answer);
        pow_ten*=10;
        ptr1=ptr1->next;
    }
    head1=Reverse(head1);
    return Answer;
}

int main()
{
    node *head1 = nullptr;
    InsertAtTail(head1, 1);
    InsertAtTail(head1, 4);
    InsertAtTail(head1, 5);
    InsertAtTail(head1, 6);
    node *head2 = nullptr;
    InsertAtTail(head2, 5);
    InsertAtTail(head2, 6);
    InsertAtTail(head2, 2);
    InsertAtTail(head2, 3);

    Display(head1);
    Display(head2);
    Display(Multiply_Two_List(head1,head2));
    Display(head1);
    Display(head2);
    return 0;
}