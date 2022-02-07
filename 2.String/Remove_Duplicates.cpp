#include<iostream>
using namespace std;

void RemoveDuplicates(char *str)
{
    if(str[0]!='\0')
    {
        while(str[0]==str[1])
        {
            str[0]='\0';
        }
        RemoveDuplicates(str+1);
    }
    return;
}

int main(){
    int n;
    cin>>n;

    char str[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
    }

    RemoveDuplicates(str);
    for(int i=0;i<n;i++)
    {
        cout<<str[i]<<endl;
    }

    return 0;
}