#include<iostream>
#include<stack>
using namespace std;

int Longest_Valid_Parenthesis(string str,int n)
{
    stack<int>st;
    st.push(-1);
    int maxlength=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')st.push(i);
        else if(str[st.top()]=='('&&str[i]==')')
        {
            st.pop();
            maxlength=max(maxlength,i-st.top());
        }
        else st.push(i);
    }
    return maxlength;
}

int Longest_Valid_Parenthesis_Optimal(string str,int n)
{
    int lc=0,rc=0;
    int maxlength=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')lc++;
        else if(str[i]==')')rc++;
        
        if(lc==rc)maxlength=max(maxlength,lc+rc);
        else if(lc<rc)
        {
            rc=0;lc=0;
        }
    }
    lc=0;rc=0;
    for(int i=n-1;i>=0;i--)
    {
        if(str[i]=='(')rc++;
        else if(str[i]==')')lc++;
        
        if(lc==rc)maxlength=max(maxlength,lc+rc);
        else if(lc<rc)
        {
            rc=0;lc=0;
        }
    }
    return maxlength;
}


int main(){
    string str;
    cin>>str;
    int len=str.length();
    cout<<Longest_Valid_Parenthesis(str,len)<<endl;
    return 0;
}