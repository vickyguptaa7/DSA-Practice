#include<iostream>
#include<stack>
#include<math.h>

using namespace std;

float Operation(float n1,float n2,char ch)
{
    switch(ch)
    {
        case '+':return n1+n2;
        case '-':return n2-n1;
        case '*':return n1*n2;
        case '/':return n2/n1;
        case '^':return pow(n2,n1);
        default:return 0;
    }
}

float Prefix_Evaluation(string str,int n)
{
    stack<float> st;
    for(int i=n-1;i>=0;i--)
    {
        if(isdigit(str[i]))
        {
            st.push(str[i]-'0');
        }
        else 
        {
            float n1=st.top(); 
            st.pop();
            float n2=st.top(); 
            st.pop();
            st.push(Operation(n2,n1,str[i])); // We Are Going From Right To Left That's Why n1 would be Second And n2 Will Be First 
        }
    }
    return st.top();
}

int main(){
    string str;
    cin>>str;

    int len=str.length();
    cout<<Prefix_Evaluation(str,len)<<endl;
    return 0;
}