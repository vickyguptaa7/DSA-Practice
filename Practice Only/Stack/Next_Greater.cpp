#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>Next_Greater(vector<int>arr)
{
    stack<int>st;
    reverse(arr.begin(),arr.end());
    int i=0;
    vector<int>ans;
    while(i<arr.size())
    {
        if(st.empty())
        {
            ans.push_back(-1);
            st.push(arr[i]);
        }
        else if(st.top()>arr[i])
        {
            ans.push_back(st.top());
            st.push(arr[i]);
        }
        else
        {
            while(!st.empty()&&st.top()<=arr[i])
            {
                st.pop();
            }
            if(st.empty())ans.push_back(-1);
            else ans.push_back(st.top());
            st.push(arr[i]);
        }
        i++;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n;
    cin>>n;

     vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        arr.push_back(num);
    }
    vector<int>ans=Next_Greater(arr);
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}