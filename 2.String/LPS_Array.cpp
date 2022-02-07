#include<iostream>
using namespace std;

int main(){
    string str;
    cin>>str;

    int len=str.length();
    int arr[len]={0};

    int i=0,j=1;

    while(j<len)
    {
        if(str[i]==str[j])
        {
            arr[j]=i+1;
            i++;j++;
        }
        else
        {
            if(i>0)
            i=arr[i-1];
            else
            j++;
        }
    }

    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}