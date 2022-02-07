#include<iostream>
#include<stack>
#include<vector>

using namespace std;
string Answer(string s) 
{
    stack<char>st;
    int count=0;
    for(int i=0;i<s.length();i++)
    {
        if(st.empty())
        {
            st.push(s[i]);
        }
        else 
        {
            if(st.top()==s[i])
            {
                count++;
                st.pop();
            }
            else 
            {
                st.push(s[i]);
            }
        }
    }
    cout<<count<<endl;
    return (count%2==0)?"Pinpin":"Merry";
}
int main(){
    int t;
    cin>>t;
    string str;
    for(int i=0;i<t;i++)
    {
        cin>>str;
        cout<<Answer(str)<<endl;
    }

    return 0;
}
