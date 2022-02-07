#include<iostream>
#include<stack>
using namespace std;

bool Duplicate(string str,int n)
{
    stack<char>st;
    for(int i=0;i<n;i++)
    {
        if(str[i]==')')
        {
            if(st.top()=='(')return true;
            while(st.top()!='(')
            {
                st.pop();
            }
            st.pop();
        }
        else
        {
            st.push(str[i]);
        }
    }
    return false;
}

int main(){
    string str;
    cin>>str;
    int len=str.length();
    (Duplicate(str,len))?cout<<"Duplicate"<<endl:cout<<"Not Duplicate"<<endl;
    return 0;
}