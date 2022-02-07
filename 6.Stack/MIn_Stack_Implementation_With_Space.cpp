#include<iostream>
using namespace std;
#define max 100
struct stack
{
    int *arr;
    int *marr;
    int top;
    int minele;
    stack()
    {
        arr=new int[max];
        marr=new int[max];
        top=-1;
        minele=-1;
    }
    void push(int val)
    {
        if(top==max-1)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top]=val;
        if(minele==-1)
        {
            minele++;
            marr[minele]=val;
        }
        else if(marr[minele]>=val)
        {
            minele++;
            marr[minele]=val;
        }
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        if(marr[minele]==arr[top])
        {
            minele--;
        }
        top--;
    }
    int Top()
    {
        if(top==-1)
        {
            cout<<"Stack Is Empty"<<endl;
            return -1;
        }
        return arr[top];
    }
    int Minele()
    {
        if(minele==-1)
        {
            cout<<"Stack Is Empty"<<endl;
            return -1;
        }
        return marr[minele];
    }
    bool empty()
    {
        return (top==-1)?1:0;
    }
};
int main(){
    stack st;
    st.push(18);
    cout<<st.Top()<<" ";
    cout<<st.Minele()<<" ";
    st.pop();
    st.push(19);
    cout<<st.Top()<<" ";
    cout<<st.Minele()<<" ";
    st.push(29);
    cout<<st.Top()<<" ";
    cout<<st.Minele()<<" ";
    st.push(18);
    cout<<st.Top()<<" ";
    cout<<st.Minele()<<" "; 
    st.push(15);
    cout<<st.Top()<<" ";
    cout<<st.Minele()<<" ";
    st.push(6);
    cout<<st.Top()<<" ";
    cout<<st.Minele()<<" ";
    
      
    return 0;
}