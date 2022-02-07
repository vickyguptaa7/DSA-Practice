#include <iostream>
using namespace std;

struct circularqueue
{
    int size, cap, front;
    int *arr;
    circularqueue(int c)
    {
        cap = c;
        size = 0;
        front = 0;
        arr = new int[cap];
    }
    void enqueue(int val)
    {
        if (isfull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        int rear = getrear();
        rear = (rear + 1) % cap; // increment in circular loop
        arr[rear] = val;
        size++;
    }
    void dequeue()
    {
        if (isempty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        front = (front + 1) % cap;
        size--;
    }
    int getfront()
    {
        if (isempty())
            return -1;
        return front;
    }
    int getrear()
    {
        if (isempty())
            return -1;
        return ((front + size - 1) % cap); // front + size is the elements in the array we have
        // to find the last element from size we can get it by (front+size-1)%array total size
    }
    bool isfull()
    {
        return (size == cap) ? 1 : 0;
    }
    bool isempty()
    {
        return (size == 0) ? 1 : 0;
    }
    void display()
    {
        if (isempty())
            return;
        int rear = getrear();
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }

        else
        {
            for(int i=front;i<size;i++)
            {
                cout<<arr[i]<<" ";
            }

            for (int i = 0; i <= rear ; i++)
            {
                cout << arr[i] << " ";
            }
        }

        cout << endl;
    }
};

int main()
{
    circularqueue cq(5);
    cq.enqueue(14);
    cq.enqueue(22);
    cq.enqueue(13);
    cq.enqueue(-6);

    cq.display();

    cq.dequeue();
    cq.display();
    cq.dequeue();
    cq.display();

    cq.enqueue(9);
    cq.enqueue(20);
    cq.enqueue(5);
    cq.display();
    cq.enqueue(1);

    return 0;
}