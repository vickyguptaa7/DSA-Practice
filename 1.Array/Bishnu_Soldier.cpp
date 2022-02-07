#include <iostream>
#include<algorithm>
using namespace std;

int Binary(int arr[],int n,int k)
{
	int i=0,j=n-1;
	int ans;
	while(j>=i)
	{
		int mid=i+(j-i)/2;
		if(k==arr[mid])
		{
			ans=mid;
			break;
		}
		else if(arr[mid]>k)
		{
			j=mid-1;
		}
		else
		{
            ans=mid;
			i=mid+1;
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;	
	int a1[n];
	for(int i=0;i<n;i++)
	{
		cin>>a1[i];
	}			
    sort(a1,a1+n);
	int m;
	cin>>m;				 

	for(int i=0;i<m;i++)
	{
        int k;
        cin>>k;
		int u=Binary(a1,n,k);
		int sum=0;
		for(int j=0;j<=u;j++)
		{
			sum+=a1[j];
		}
		cout<<a1[u]<<" "<<sum<<endl;
	}
	return 0;
}	


