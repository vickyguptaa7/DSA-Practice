#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int Min=arr[0],Diff=arr[1]-arr[0];
    for(int i=1;i<n;i++)
    {
        Diff=max(Diff,arr[i]-Min);
        Min=min(arr[i],Min);
    }
    cout<<Diff<<endl;
    return 0;
}