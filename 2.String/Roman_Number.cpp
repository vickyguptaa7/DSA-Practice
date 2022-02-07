#include <iostream>
using namespace std;

int Roman_Integer(char ch)
{
    switch (ch)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}

int main()
{
    string Roman;
    cin >> Roman;
    int len=Roman.length();
    int prev=Roman_Integer(Roman[0]),ans=0;
    for(int i=1;i<len;i++)
    {
        int curr=Roman_Integer(Roman[i]);
        if(prev>=curr)
        {
            ans+=prev;
        }
        else
        {
            ans-=prev;
        }
        prev=curr;
    }
    ans+=prev;
    cout<<ans<<endl;
    return 0;
}