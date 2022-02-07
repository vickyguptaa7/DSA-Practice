#include<iostream>
using namespace std;

int No_Flips(string str)
{
    int n=str.length();
    int count_1=0,count_2=0;
    for(int i=0;i<n;i++)
    {
        if((i%2==0&&str[i]=='0')||((i+1)%2==0&&str[i]=='1'))
        {
            count_1++;
        }
        if((i%2==0&&str[i]=='1')||((i+1)%2==0&&str[i]=='0'))
        {
            count_2++;
        }
    }
    return min(count_1,count_2);
}
int main(){
    string str;
    cin>>str;
    
    cout<<No_Flips(str);

    return 0;
}