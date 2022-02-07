#include<iostream>
using namespace std;

struct queue
{
    int cap,size;
    int *arr;
    queue(int c)
    {
        cap=c;
        size=0;
        arr=new int[cap];
    }
    void enqueue(int val)
    {
        if(size==cap)
        {
            cout<<"Queue Overflow"<<endl;
            return;
        }
        arr[size]=val;
        size++;
    }
    void dequeue()
    {
        if(size==0)
        {
            cout<<"Queue Underflow"<<endl;
            return;
        }
        for(int i=1;i<size;i++)
        {
            arr[i-1]=arr[i];
        }
        size--;
    }
    int getfront()
    {
        if(size==0)
        {
            cout<<"Queue Is Empty"<<endl;
            return -1;
        }
        return arr[0];
    }
    int getrear()
    {
        if(size==0)
        {
            cout<<"Queue Is Empty"<<endl;
            return -1;
        }
        return arr[size-1];
    }
    bool isfull()
    {
        return (size==cap)?1:0;
    }
    bool isempty()
    {
        return (size==0)?1:0;
    }
    int Size()
    {
        return size;
    }
    void display()
    {
        if(size==0){
            cout<<"Queue Is Empty"<<endl;
            return;
            }
        int i;
        for(i=0;i<size-1;i++)
        {
            cout<<arr[i]<<"<-";
        }
        cout<<arr[i]<<endl;
    }
};

int main(){
    queue q(4);
    q.display();
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.enqueue(60);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    cout<<q.getfront()<<endl;
    cout<<q.getrear()<<endl;
    
    return 0;
}