#include<iostream>
using namespace std;

void Print(int n)
{
    if(n==0)return;

    cout<<n<<" ";
    Print(n-1);
}

int main(){
    int n;
    cin>>n;
    Print(n);
    cout<<endl;
    return 0;
}