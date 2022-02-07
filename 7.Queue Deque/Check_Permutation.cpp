#include<iostream>
#include<queue>
#include<stack>

using namespace std;

bool Check_Permuatation(int arr[],int parr[],int n)
{
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        q.push(parr[i]);
    }

    stack<int>st;
    for(int i=0;i<n;i++)
    {
        st.push(arr[i]);
        while(!st.empty()&&q.front()==st.top())
        {
            q.pop();
            st.pop();
        }
    }
    return (q.empty());
}

int main(){
    cout<<"Size Of Input : ";
    int n;
    cin>>n;
    int arr[n],parr[n];
    cout<<"Enter The Array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter The Permutation Array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>parr[i];
    }

    (Check_Permuatation(arr,parr,n))?cout<<"Possible"<<endl:cout<<"Not Possible"<<endl;
    return 0;
}