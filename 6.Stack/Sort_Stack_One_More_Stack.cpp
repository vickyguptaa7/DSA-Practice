#include<iostream>
#include<stack>

using namespace std;

stack<int> Sort_Stack(stack<int> st)
{
    stack<int>ans;
    while(!st.empty())
    {
        int temp=st.top();
        st.pop();
        while (!ans.empty()&&ans.top()<temp)
        {
            st.push(ans.top());
            ans.pop();
        }
        ans.push(temp);
    }
    return ans;
}

void Display(stack<int>st)
{
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        st.push(num);
    }

    stack<int> ans=Sort_Stack(st);
    Display(ans);
    return 0;
}