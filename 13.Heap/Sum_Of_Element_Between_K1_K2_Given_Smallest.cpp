#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Sum_Btw_K1_K2_Brute(vector<int>arr,int k1,int k2)
{
    sort(arr.begin(),arr.end());
    int Sum=0;
    for(int i=k1;i<k2;i++){
        Sum+=arr[i];
    }
    return Sum;
}

int Kth_Smallest(vector<int>arr,int k)
{
    priority_queue<int>pq;
    for(int i=0;i<arr.size();i++)
    {
        pq.push(arr[i]);
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
    return pq.top();
}

int Sum_Btw_K1_K2_Optimal(vector<int>arr,int k1,int k2)
{
    int k1_num=Kth_Smallest(arr,k1);
    int k2_num=Kth_Smallest(arr,k2);
    int Sum=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>k1_num&&arr[i]<k2_num)Sum+=arr[i];
    }
    return Sum;
}

void Print(vector<int> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k1,k2;
    cin>>k1>>k2;
    cout<<endl<<Sum_Btw_K1_K2_Brute(arr,k1,k2-1)<<endl;
    cout<<endl<<Sum_Btw_K1_K2_Optimal(arr,k1,k2)<<endl;
    return 0;
}