#include<iostream>
using namespace std;

#define max 4

struct stack
{
    int *arr;
    int top1;
    int top2;
    stack()
    {
        arr=new int[max];
        top1=-1;
        top2=max;
    }
    void push1(int val)
    {
        if(top2==top1+1){cout<<"Stack Overflow"<<endl; return;}
        top1++;
        arr[top1]=val;
    }
    void push2(int val)
    {
        if(top2==top1+1){cout<<"Stack Overflow"<<endl; return;}
        top2--;
        arr[top2]=val;
    }
    void pop1()
    {
        if(top1==-1)
        {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top1--;
    }
    void pop2()
    {
        if(top2==max)
        {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top2++;
    }
    int Top1()
    {
        if(top1==-1)
        {
            cout<<"Empty"<<endl;
            return -1;
        }
        return arr[top1];
    }
    int Top2()
    {
        if(top1==max)
        {
            cout<<"Empty"<<endl;
            return -1;
        }
        return arr[top2];
    }
    bool empty1()
    {
        return (top1==-1)?1:0;
    }
    bool empty2()
    {
        return (top2==max)?1:0;
    }
    int size1()
    {
        return top1+1;
    }
    int size2()
    {
        return (max-top2);
    }
};

int main(){
    stack st;
    st.push1(1);
    cout<<st.Top1()<<endl;
    st.push1(2);
    cout<<st.Top1()<<endl;
    st.push2(4);
    cout<<st.Top2()<<endl;
    st.push2(3);
    cout<<st.Top2()<<endl;
    cout<<st.size1()<<endl;
    cout<<st.size2()<<endl;
    
    return 0;
}