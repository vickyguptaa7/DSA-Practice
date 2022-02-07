#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct ListNode
{
    ListNode *next;
    int val;
    ListNode(int data)
    {
        val = data;
        next = nullptr;
    }
};

void Insert_At_Head(ListNode *&head, int data)
{
    ListNode *newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
}

void Display(ListNode *head)
{
    while (head)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "nullptr\n";
}

ListNode *Remove_Duplicates(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy, *curr = head;
    while (prev && curr)
    {
        if (curr->next && curr->next->val == curr->val)
        {
            while (curr && curr->next && curr->val == curr->next->val)
            {
                curr = curr->next;
            }

            prev->next = curr->next;
            curr = curr->next;
        }
        else
        {
            prev = prev->next;
            curr = curr->next;
        }
    }
    return dummy->next;
}

int main()
{
    ListNode *head = nullptr;
    Insert_At_Head(head, 5);
    Insert_At_Head(head, 4);
    Insert_At_Head(head, 4);
    Insert_At_Head(head, 3);
    Insert_At_Head(head, 3);
    Insert_At_Head(head, 2);
    Insert_At_Head(head, 1);
    Display(head);
    Display(Remove_Duplicates(head));
    return 0;
}