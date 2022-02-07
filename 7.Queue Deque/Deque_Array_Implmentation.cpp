#include<iostream>
using namespace std;

struct deque
{
    int *arr;
    int front,size,cap;
    deque(int c)
    {
        front=0,size=0;
        cap=c;
        arr=new int[cap];
    }
    void insertfront(int val)
    {
        if(isfull())
        {
            cout<<"Deque Is Full"<<endl;
            return;
        }
        arr[front]=val;
        front=(front-1)%cap;
        size++;
    }
    void insertrear(int val)
    {
        if(isfull())
        {
            cout<<"Deque Is Full"<<endl;
            return;
        }
        int rear=getrear();
        rear=(rear+1)%cap;
        arr[rear]=val;
        size++;
    }
    void deletefront()
    {
        if(isempty())
        {
            cout<<"Deque Is Empty"<<endl;
            return;
        }
        front=(front+1)%cap;
        size--;
    }
    void deleterear()
    {
        if(isempty())
        {
            cout<<"Deque Is Empty"<<endl;
            return;
        }
        size--;
    }
    bool isempty()
    {
        return (size==0)?1:0;
    }
    bool isfull()
    {
        return (size==cap)?1:0;
    }
    int getrear()
    {
        if(isempty())return -1;
        int prevfrnt=(front+1)%cap;
        return (size+prevfrnt-1)%cap;
    }
    int getfront()
    {
        if(isempty())return -1;
        return (front+1)%cap;
    }
    void display()
    {
        if(isempty())
        {
            cout<<"Deque Is Empty"<<endl;
            return;
        }
        int rear=getrear();
        int prevfrnt=(front+1)%cap;
        if(prevfrnt<=rear)
        {
            for(int i=prevfrnt;i<=rear;i++)
            {
                cout<<arr[i]<<" ";
            }
        }
        else
        {
            for(int i=prevfrnt;i<cap;i++)
            {
                cout<<arr[i]<<" ";
            }
            for(int i=0;i<=rear;i++)
            {
                cout<<arr[i]<<" ";
            }
        }
        cout<<endl;
    }   
};

int main(){
    deque dq(5);
    dq.insertfront(5);
    dq.insertfront(15);
    dq.display();
    dq.insertrear(20);
    dq.display();
    dq.deletefront();
    dq.display();
    dq.deleterear();
    dq.display();
    
    dq.insertfront(15);
    dq.display();
    
    dq.deletefront();
    
    dq.display();
    cout<<dq.getfront();
    return 0;
}