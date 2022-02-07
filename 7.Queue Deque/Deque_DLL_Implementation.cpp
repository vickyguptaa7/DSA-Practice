#include <iostream>
using namespace std;

struct dll
{
    int data;
    dll *prev;
    dll *next;
    dll(int val)
    {
        prev = nullptr;
        next = nullptr;
        data = val;
    }
};
struct Deque
{
    dll *front, *rear;
    int size;
    Deque()
    {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }
    void insertfront(int val)
    {
        size++;
        dll *n = new dll(val);
        if (isempty())
        {
            front = n;
            rear = n;
            return;
        }
        n->next = front;
        front->prev = n;
        front = n;
    }
    void insertrear(int val)
    {
                size++;
        dll *n = new dll(val);
        if (isempty())
        {
            front = n;
            rear = n;
            return;
        }
        rear->next = n;
        n->prev = rear;
        rear = n;
    }
    void deletefront()
    {
        if (isempty())
        {
            cout << "Deque Is Empty" << endl;
            return;
        }
        dll *todelete = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete todelete;
        size--;
    }
    void deleterear()
    {
        if (isempty())
        {
            cout << "Deque Is Empty" << endl;
            return;
        }
        dll*todelete=rear;
        rear=rear->prev;
        rear->next=nullptr;
        if(rear==nullptr)front=nullptr;
        delete todelete;
        size--;
    }
    bool isempty()
    {
        return (front == nullptr) ? 1 : 0;
    }
    int getrear()
    {
        if (isempty())
        {
            cout << "Deque Empty" << endl;
            return -1;
        }
        return rear->data;
    }
    int getfront()
    {
        if (isempty())
        {
            cout << "Deque Empty" << endl;
            return -1;
        }
        return front->data;
    }
    void display()
    {
        if(isempty())
        {
            cout<<"Deque Is Empty"<<endl;
            return;
        }
        dll*temp=front;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    int Size()
    {
        return size;
    }
};

int main()
{
    Deque dq;
    dq.insertrear(5);
    dq.display();

    dq.insertrear(10);
    dq.display();
    
    cout<<dq.getrear()<<endl;

    dq.deleterear();
    dq.display();

    dq.insertfront(15);
    dq.display();

    cout<<dq.getfront()<<endl;
    
    cout<<dq.Size()<<endl;
    dq.display();

    dq.deleterear();
    dq.display();

    return 0;
}