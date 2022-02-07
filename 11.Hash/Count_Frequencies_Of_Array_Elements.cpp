#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }
    for(auto x:m)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }

    // For The Same Order As In The Array

    for(int i=0;i<n;i++)
    {
        if(m[arr[i]]!=-1)
        {
            cout<<arr[i]<<" "<<m[arr[i]]<<endl;
            m[arr[i]]=-1;
        }
    }
    return 0;
}