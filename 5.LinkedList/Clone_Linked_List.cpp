#include <iostream>
#include <unordered_map>
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

node *Clone_Linked_List(node *head) // T.C ->  O(n) and S.C -> O(n) bcoz of map
{
    unordered_map<node *, node *> umap;
    node *curr = head;
    while (curr)
    {
        node *newnode = new node(curr->data);
        umap[curr] = newnode;
        curr = curr->next;
    }
    curr = head;
    while (curr) // umap[nullptr] is zero so we dont need to explicity set it
    {
        umap[curr]->next = umap[curr->next];
        umap[curr]->random = umap[curr->random];
        curr = curr->next;
    }
    return umap[head];
}

node *Clone_Linked_List_Opt(node *head) // T.C ->  O(n) and S.C -> O(n) bcoz of map
{
    if (!head)
        return nullptr;
    node *curr = head;
    while (curr) // created nodes
    {
        node *newNode = new node(curr->data);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = curr->next->next;
    }
    curr = head;
    while (curr) /// assigned random pointers
    {
        if (curr->random)
            curr->next->random = curr->random->next;
        else
            curr->next->random = nullptr;
        curr = curr->next->next;
    }
    node *newHead = head->next;
    curr = newHead;
    while (curr && curr->next) // assigned next pointers
    {
        head->next = curr->next;
        curr->next = curr->next->next;
        curr = curr->next;
        head = head->next;
    }
    head->next = nullptr;
    return newHead;
}

int main()
{
    node *head = nullptr;
    InsertAtTail(head, 12);
    InsertAtTail(head, 15);
    InsertAtTail(head, 10);
    InsertAtTail(head, 11);
    InsertAtTail(head, 5);
    InsertAtTail(head, 6);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);

    Display(Clone_Linked_List_Opt(head));
    Display(head);

    return 0;
}