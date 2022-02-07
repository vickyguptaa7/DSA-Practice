#include<iostream>
using namespace std;

int Check_Rotation(string txt,string rtxt)
{
    if(txt.length()!=rtxt.length())
    {
        return 0;
    }

    txt.append(txt);
    return (txt.find(rtxt)!=string::npos);
}

int main(){
    string txt,rtxt;
    cin>>txt>>rtxt;

    (Check_Rotation(txt,rtxt))?cout<<"True"<<endl:cout<<"No"<<endl;
    
    return 0;
}