#include<iostream>
using namespace std;

int Score(string s)
{
    int score=0;
    
    int n=s.length();
    
    if(!n)return 0;
    
    for(int i=1;i<n;i++)
    {
        if(s[i-1]=='('&&s[i]==')')
        {
            i++;
            score++;
        }
        else if(s[i-1]=='('&&s[i]=='(')
        {
            int increment=Score(s.substr(1));
            score+=2*increment;
            i+=2*increment;
        }
    }
    return score;
}

int main(){
    string s;
    cin>>s;
    cout<<Score(s)<<endl;
    return 0;
}