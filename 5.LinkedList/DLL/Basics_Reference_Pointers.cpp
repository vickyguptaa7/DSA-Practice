#include<iostream>
using namespace std;

void Swap(int&x,int*y)
{
    x=x+*y;
    *y=x-*y;
    x=x-*y;
}

int main(){
    int x=20;
    int y=40;
    Swap(x,&y);   
    cout<<x<<" "<<y<<endl;
    return 0;
}