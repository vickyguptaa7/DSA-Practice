#include<iostream>
using namespace std;

int foo(int n)
{
    if(n==1)return 1;
    else return foo((n+1)/2)+foo(n/2);
}

int main(){
    cout<<foo(8)<<endl;
    return 0;
}