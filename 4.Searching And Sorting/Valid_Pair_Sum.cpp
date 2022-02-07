#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);

    int i=0,j=n-1,count=0;
    while(i<j)
    {
        if(arr[i]+arr[j]>0)
        {
            count+=j-i;
            j--;
        }
        else 
        i++;
    }
    cout<<count<<endl;
    return 0;
}