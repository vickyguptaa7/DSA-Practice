#include<iostream>
#include<stack>
using namespace std;

bool Check_For_Valid_Preorder_Using_Stack(int *pre,int n)
{
    if(n==0||n==1)return 1;
    stack<int>st;
    int root=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(pre[i]<root)return 0;
        while(!st.empty()&&st.top()<pre[i])
        {
            root=st.top();
            st.pop();
        }
        st.push(pre[i]);
    }
    return 1;
}

void Check_Pre(int *pre,int l,int r,int n,int &indx)
{
    if(indx>=n||pre[indx]<l||pre[indx]>r)return;
    int val=pre[indx++];
    Check_Pre(pre,l,val,n,indx);
    Check_Pre(pre,val,r,n,indx);
}

bool Check_For_Valid_Preorder(int *pre,int n)
{
    int indx=0;
    Check_Pre(pre,-1000000000,1000000000,n,indx);
    if(indx<n)return 0;
    else return 1;
}

int main(){
    int n;
    cin>>n;
    int pre[n];
    for(int i=0;i<n;i++)cin>>pre[i];
    cout<<Check_For_Valid_Preorder(pre,n)<<endl;
    cout<<endl<<Check_For_Valid_Preorder_Using_Stack(pre,n)<<endl;
    return 0;
}