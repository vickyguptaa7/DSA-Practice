#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int val)
    {
        data=val;
        next=nullptr;
    }
};
struct lqueue
{
    node*front,*rear;
    int size;
    lqueue()
    {
        size=0;
        front=nullptr;
        rear=nullptr;
    }
    bool isempty()
    {
        return(front==nullptr)?1:0;
    }
    void enqueue(int val)
    {
        node*n=new node(val);
        size++;
        if(isempty())
        {
            rear=n;
            front=n;
            return;
        }
        rear->next=n;
        rear=n;
    }
    void dequeue()
    {
        if(isempty())
        {
            cout<<"Empty"<<endl;
            return;
        }
        node*todelete=front;
        front=front->next;
        if(isempty())rear=nullptr;
        delete todelete;
    }
    int getfront()
    {
        if(isempty())
        {
            cout<<"Queue Is Empty"<<endl;
            return -1;
        }
        return front->data;
    }
    int getrear()
    {
        if(isempty())
        {
            cout<<"Queue Is Empty"<<endl;
            return -1;
        }
        return rear->data;
    }
    void display()
    {
        node*temp=front;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    lqueue lq;
    lq.enqueue(14);
    lq.enqueue(22);
    lq.enqueue(6);
    
    lq.display();

    lq.dequeue();
    lq.display();

    lq.dequeue();
    lq.display();
    
    lq.enqueue(9);
    lq.enqueue(20);
    lq.display();
    cout<<lq.getfront()<<endl;
    cout<<lq.getrear()<<endl;
    
    return 0;
}