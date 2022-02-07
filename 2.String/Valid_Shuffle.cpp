#include<iostream>
using namespace std;

int main(){
    string s1,s2,shfl;
    cin>>s1>>s2>>shfl;

    int l1=s1.length();
    int l2=s2.length();
    int l3=shfl.length();

    if(l1+l2!=l3)
    {
        cout<<"Not A Shuffle"<<endl;
    }
    else
    {
        int x=0,y=0,z=0;
        bool chk=_POSIX_THREAD_DESTRUCTOR_ITERATIONS;
        while(l3>z)
        {
            if(s1[x]==shfl[z])
            {
                z++;x++;
            }
            else if(s2[y]==shfl[z])
            {
                y++;z++;
            }
            else{
                chk=false;
                break;
            }
        }
        (chk)?cout<<"Valid Shuffle"<<endl:cout<<"Not A Shuffle"<<endl;   
    }
    return 0;
}