#include <iostream>
using namespace std;

struct node
{
    int data;
    node*next;
    node(int val)
    {
        data=val;
        next=nullptr;
    }
};

int C_N(node *head)
{
    int t = 0;
    node *temp = head;
    while (temp != nullptr)
    {
        t++;
        temp = temp->next;
    }
    return t;
}

node *reverse(node *head, int k)
{
    int n = C_N(head);
    node *prev = nullptr, *curr = head, *next = nullptr;
    node *Tail_1 = nullptr, *Tail_2 = head, *newHead = nullptr;
    while (n>0)
    {
        int count = k;
        while (count--&&curr!=nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if (newHead == nullptr)
            newHead = prev;
        if (Tail_1)
            Tail_1->next = prev;
        
        Tail_2->next=curr;
        Tail_1 = Tail_2;
        Tail_2 = curr;
        prev = nullptr;
        n-=k;
    }
    return newHead;
}

void InsertAtHead(node*&head,int val)
{
    node*n=new node(val);
    n->next=head;
    head=n;
}

void Display(node*head)
{
    node*temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"Null"<<endl;
}
int main()
{
    node*head=nullptr;
    InsertAtHead(head,1);
    InsertAtHead(head,2);
    InsertAtHead(head,3);
    InsertAtHead(head,4);
    InsertAtHead(head,5);
    
    Display(head);
    
    node*newHead=reverse(head,3);

    Display(newHead);
    return 0;
}