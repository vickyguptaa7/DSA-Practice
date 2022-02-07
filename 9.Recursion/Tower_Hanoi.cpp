#include<iostream>
using namespace std;

void Tower_Of_Hanoi(int n,char s,char d,char h)
{
    if(n==0)
    {
        return;
    }
    Tower_Of_Hanoi(n-1,s,h,d);
    cout<<"Move From "<<s<<" -> "<<d<<endl;
    Tower_Of_Hanoi(n-1,h,d,s);
}

int main(){
    int n;
    cin>>n;

    char s='S',d='D',h='H';
    Tower_Of_Hanoi(n,s,d,h);
    return 0;
}