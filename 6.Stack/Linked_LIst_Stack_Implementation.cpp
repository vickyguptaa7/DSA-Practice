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
node *top = nullptr;

void push(int val)
{
    node *n = new node(val);
    n->next = top;
    top = n;
}

void pop()
{
    if (!top)
    {
        cout << "Stack Underflow" << endl;
        return;
    }
    node *temp = top;
    top = top->next;
    delete temp;
}

int Top()
{
    if (!top)
    {
        cout << "Empty" << endl;
        return -1;
    }
    return top->data;
}

void Display()
{
    if (top == nullptr)
    {
        cout << "No Element In Stack" << endl;
        return;
    }
    node *temp = top;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool empty()
{
    return (top == nullptr) ? true : false;
}

int main()
{
    cout << empty << endl;
    \
    push(5);
    cout << Top() << " ";
    push(4);
    cout << Top() << " ";
    push(3);
    cout << Top() << " ";
    push(2);
    cout << Top() << " ";
    push(1);
    cout << Top() << " ";
    cout << endl;

    Display();
    pop();
    Display();
    cout << empty() << endl;
    return 0;
}