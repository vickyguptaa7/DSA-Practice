#include <iostream>
using namespace std;

struct kqueue
{
    int *arr;
    int *front;
    int *rear;
    int *next;
    int free;
    int cap;
    kqueue(int c, int k)
    {
        cap = c;
        arr = new int[cap];
        next = new int[cap];
        front = new int[k];
        rear = new int[k];
        free = 0;
        for (int i = 0; i < cap; i++)
        {
            next[i] = i + 1;
        }
        next[cap - 1] = -1;
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
        }
    }
    bool isFull()
    {
        return (free == -1) ? 1 : 0;
    }
    bool isEmpty(int t)
    {
        return (front[t] == -1) ? 1 : 0;
    }
    void enque(int t, int val)
    {
        if (isFull())
        {
            cout << "Queue Is Full" << endl;
            return;
        }
        //update free
        int i = free;
        free = next[i];

        if (isEmpty(t))
        {
            front[t] = i;
        }
        else
        {
            next[rear[t]] = i;
        }
        next[i] = -1;
        rear[t] = i;

        arr[i] = val;
    }
    void dequeue(int t)
    {
        if (isEmpty(t))
        {
            cout << "Queue Is Empty" << endl;
            return;
        }
        int i = front[t];
        front[t] = next[i];

        next[i] = free;
        free = i;
    }
    int Front(int t)
    {
        if (isEmpty(t))
        {
            cout << "Queue Is Empty" << endl;
            return -1;
        }
        return arr[front[t]];
    }
    int Rear(int t)
    {
        if (isEmpty(t))
        {
            cout << "Queue Is Empty" << endl;
            return -1;
        }
        return arr[rear[t]];
    }
    
};

int main()
{
    kqueue kq(9,3);
    kq.enque(0,5);
    cout<<kq.Front(0)<<endl;
    kq.enque(0,10);
    cout<<kq.Front(0)<<endl;
    cout<<kq.Rear(0)<<endl;
    
    kq.enque(1,7);
    cout<<kq.Front(1)<<endl;
    kq.enque(1,14);
    cout<<kq.Front(1)<<endl;
    cout<<kq.Rear(1)<<endl;
    
    kq.dequeue(0);
    kq.dequeue(1);
    cout<<kq.Front(0)<<endl;
    
    return 0;
}