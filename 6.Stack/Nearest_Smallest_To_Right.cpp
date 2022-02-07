#include<iostream>
#include<stack>
using namespace std;

int* Nearest_Smallest(int arr[],int n)
{
    stack<int> st;
    int *ans=new int[n];
    for(int i=n-1;i>=0;i--)
    {
        
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int *ans=Nearest_Smallest(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}