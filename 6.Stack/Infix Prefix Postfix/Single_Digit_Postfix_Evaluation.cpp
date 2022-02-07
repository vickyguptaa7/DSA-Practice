#include<iostream>
#include<math.h>

using namespace std;

struct stack
{
    float *arr;
    int top;
    stack()
    {
        arr=new float[100];
        top=-1;
    }
    void push(float data)
    {
        if(top==100-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top]=data;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top--;
    }
    float Top()
    {
        if(top==-1)
        {
            cout<<"Empty"<<endl;
            return '!';
        }
        return arr[top];
    }
    bool empty()
    {
        return (top==-1)?1:0;
    }
};

float Operation(float n1,float n2,char ch)
{
    switch(ch)
    {
        case '+':return (n1+n2);
        case '-':return (n2-n1);
        case '*':return (n1*n2);
        case '/':return (n2/n1);
        case '^':return pow(n2,n1);
        default: return 0;
    }
}

float Postfix_Evaluation(string str,int n)
{
    stack st;
    for(int i=0;i<n;i++)
    {
        if(str[i]>=48&&str[i]<=57)
        {
            st.push(str[i]-'0');
        }
        else 
        {
            float n1=st.Top();
            st.pop();
            float n2=st.Top();
            st.pop();
            st.push(Operation(n1,n2,str[i]));
        }
    }
    return st.Top();
}

int main(){
    string str;
    cin>>str;
    int len=str.length();
    cout<<Postfix_Evaluation(str,len)<<endl;   
    return 0;
}