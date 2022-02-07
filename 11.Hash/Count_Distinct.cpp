#include<iostream>
#include<unordered_set>

using namespace std;

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    unordered_set<int> m;
    for(int i=0;i<n;i++)
    {
        m.insert(arr[i]);
    }
    cout<<m.size()<<endl;
    return 0;
}