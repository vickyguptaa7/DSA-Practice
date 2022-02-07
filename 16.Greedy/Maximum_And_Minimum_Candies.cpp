#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

pair<int,int>Maximum_Minimum_Candies(vector<int>candy,int n,int k)
{
    sort(candy.begin(),candy.end());
    pair<int,int>Ans={0,0};
    int d=n/(k+1);
    if(n%(k+1)!=0)d++;
    for(int i=0;i<d;i++)
    {
        Ans.first+=candy[i];
        Ans.second+=candy[n-1-i];
    }
    return Ans;
}

int main()
{
    int n,k;
    cin >> n>>k;
    vector<int> candy(n);
    for (int i = 0; i < n; i++)
        cin >> candy[i];
    pair<int,int>Ans=Maximum_Minimum_Candies(candy,n,k);
    cout<<Ans.first<<" "<<Ans.second<<endl;
    return 0;
}
/*
10 1
1 2 3 4 5 6 7 8 9 10
*/