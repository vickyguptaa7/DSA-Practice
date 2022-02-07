#include <iostream>
#define max 100
using namespace std;

struct stack
{
    public:
    int *arr;
    int top ;

    stack()
    {
        arr=new int[max];
        top=-1;
    }
    void push(int val)
    {
        if (top == max-1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
    int Top()
    {
        if(top==-1){ cout<<"Stack Is Empty"<<endl; return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }
};

void Display(stack st)
{
    if(st.top==-1)cout<<"Empty"<<endl;

    while(!st.empty())
    {
        cout<<st.Top()<<" ";
        st.pop();
    }
}
int main()
{
    stack stk;
    stk.push(1);
    cout<<stk.Top();
    stk.push(2);
    cout<<stk.Top();
    stk.push(3);
    cout<<stk.Top();
    cout<<endl;
    Display(stk);
    return 0;
}