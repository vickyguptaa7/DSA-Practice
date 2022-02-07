#include<iostream>
#include<stack>

using namespace std;

bool Redundant_Parenthesis(string str,int n)
{
    stack<char>st;
    for(int i=0;i<n;i++)
    {
        if(str[i]!=')')st.push(str[i]);
        else
        {
            bool chk =true; // Check If It Contain Any Operator Or Not Before Poping '('
            while(st.top()!='(')
            {
                if(st.top()=='+'||st.top()=='-'||st.top()=='/'||st.top()=='*')
                {
                   chk=false;
                }
                st.pop();
            }
            st.pop();
            if(chk)return true;
        }
    }
    return false;
}

int main(){
    string str;
    cin>>str;
    int len=str.length();

    (Redundant_Parenthesis(str,len))?cout<<"Redundant"<<endl:cout<<"Not Redundant"<<endl;
    return 0;
}