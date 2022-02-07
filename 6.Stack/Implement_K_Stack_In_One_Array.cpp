#include<iostream>
using namespace std;
#define max 100
#define K 3

struct stack
{
    int *sdata;
    int *next;
    int *top;
    int nextAvailable;
    stack(int n=max,int k=K)
    {
        sdata=new int[max];
        next=new int[max];
        top=new int[k];
        nextAvailable=0;
        for(int i=0;i<max;i++)
        {
            if(i<k)top[i]=-1;
            if(i==max-1)
            {
                next[i]=-1;
                break;
            }
            next[i]=i+1;
        }
    }
    void push(int itop,int val)
    {
        if(nextAvailable==-1)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        // Updating nextAvailable
        int i=nextAvailable;
        nextAvailable=next[i];
        //Update  next
        next[i]=top[itop];
        //update top
        top[itop]=i;
        //update sdata
        sdata[i]=val;
    }
    void pop(int itop)
    {
        if(top[itop]==-1)
        {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        // updating top
        int i=top[itop];
        top[itop]=next[i];
        // updating next
        next[i]=nextAvailable;
        // Updating nextAvailble 
        nextAvailable=i;
    }
    int Top(int itop)
    {
        if(top[itop]==-1)
        {
            cout<<"Stack Is Empty"<<endl;
            return -1;
        }
        return sdata[top[itop]];
    }
    bool isEmpty(int itop)
    {
        return (top[itop]==-1)?1:0;
    }

};

int main(){
    stack st(9,3);
    
    st.push(0,1);
    cout<<st.Top(0)<<" ";
    st.push(0,2);
    cout<<st.Top(0)<<" ";
    st.push(0,3);
    cout<<st.Top(0)<<" ";

    st.push(2,21);
    cout<<st.Top(2)<<" ";
    st.push(2,22);
    cout<<st.Top(2)<<" ";
    st.push(2,23);
    cout<<st.Top(2)<<" ";


    st.push(1,11);
    cout<<st.Top(1)<<" ";
    st.push(1,12);
    cout<<st.Top(1)<<" ";
    st.push(1,13);
    cout<<st.Top(1)<<" "<<endl;

    
    st.pop(0);
    cout<<st.Top(0)<<" ";
    
    st.pop(1);
    cout<<st.Top(1)<<" ";
    
    st.pop(2);
    cout<<st.Top(2)<<" ";
    
    return 0;
}